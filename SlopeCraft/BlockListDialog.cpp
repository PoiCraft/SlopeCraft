//
// Created by Joseph on 2024/4/9.
//

#include "BlockListDialog.h"
#include "ui_BlockListDialog.h"
#include <QListView>
#include "SCWind.h"

class BLD_block_list_provider : public QAbstractListModel {
 public:
  const std::function<std::vector<
      std::pair<QString, const SlopeCraft::block_list_interface *>>()>
      available_block_lists;

 public:
  explicit BLD_block_list_provider(
      QWidget *parent,
      std::function<std::vector<
          std::pair<QString, const SlopeCraft::block_list_interface *>>()>
          cb)
      : QAbstractListModel{parent}, available_block_lists{std::move(cb)} {}
  BLD_block_list_provider(const BLD_block_list_provider &) = delete;

  int rowCount(const QModelIndex &parent = QModelIndex()) const final {
    if (parent.isValid()) {
      return 0;
    }
    return this->available_block_lists().size();
  }

  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const final {
    if (not index.isValid()) {
      return {};
    }
    if (role not_eq Qt::ItemDataRole::DisplayRole) {
      return {};
    }
    const auto block_lists = this->available_block_lists();
    const int idx = index.row();

    if (idx >= block_lists.size() or idx < 0) {
      return {};
    }
    if (block_lists[idx].second == nullptr) {
      return tr("SlopeCraft 内部错误，方块列表的列表中出现 nullptr");
    }
    return block_lists[idx].first;
  }
};

class BLD_block_provider : public QAbstractListModel {
 private:
  const std::function<const SlopeCraft::block_list_interface *()>
      available_block_list;
  const std::function<SCL_language()> current_lang;

 public:
  explicit BLD_block_provider(
      QWidget *parent,
      std::function<const SlopeCraft::block_list_interface *()> &&cb,
      std::function<SCL_language()> &&lang_cb)
      : QAbstractListModel{parent},
        available_block_list{std::move(cb)},
        current_lang{std::move(lang_cb)} {}

  std::vector<const SlopeCraft::mc_block_interface *> available_blocks()
      const noexcept {
    auto bl = this->available_block_list();
    if (bl == nullptr) {
      return {};
    }
    const size_t num = bl->size();
    std::vector<const SlopeCraft::mc_block_interface *> ret;
    ret.resize(num);
    [[maybe_unused]] const size_t num_ =
        bl->get_blocks(ret.data(), nullptr, ret.size());
    assert(num == num_);
    return ret;
  }

  int rowCount(const QModelIndex &parent = QModelIndex()) const final {
    if (parent.isValid()) {
      return 0;
    }
    auto bl = this->available_block_list();
    if (bl == nullptr) {
      return 0;
    }
    return bl->size();
  }
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const final {
    if (not index.isValid()) {
      return {};
    }
    if (role not_eq Qt::ItemDataRole::DisplayRole) {
      return {};
    }
    const auto blocks = this->available_blocks();
    const int idx = index.row();

    if (idx >= blocks.size() or idx < 0) {
      return {};
    }
    if (blocks[idx] == nullptr) {
      return tr("SlopeCraft 内部错误，方块列表中出现 nullptr");
    }
    if (this->current_lang() == SCL_language::Chinese) {
      return QString::fromUtf8(blocks[idx]->getNameZH());
    }
    return QString::fromUtf8(blocks[idx]->getNameEN());
  }
};

class BLD_block_info_provider : public QAbstractTableModel {
 public:
  const std::function<const SlopeCraft::mc_block_interface *()> selected_block;

 public:
  explicit BLD_block_info_provider(
      QWidget *parent,
      std::function<const SlopeCraft::mc_block_interface *()> &&cb)
      : QAbstractTableModel{parent}, selected_block{std::move(cb)} {}

  int rowCount(const QModelIndex &qmi) const final {
    if (qmi.isValid()) {
      return 0;
    }
    return 6;
  }
  int columnCount(const QModelIndex &qmi) const final {
    if (qmi.isValid()) {
      return 0;
    }
    return 2;
  }

  static QString key_name(int index) noexcept {
    const std::array<QString, 6> keys{tr("最低版本"), tr("依附方块"),
                                      tr("发光"),     tr("末影人可搬走"),
                                      tr("可燃"),     tr("一组数量")};
    if (index < 0 or index >= keys.size()) {
      return {};
    }
    return keys[index];
  }
  /*
   * 0 -> version
   * 1 -> need glass
   * 2 -> do glow
   * 3 -> enderman pickable
   * 4 -> burnable
   * 5 -> stack size
   * */
  static QVariant value_of_attribute(const SlopeCraft::mc_block_interface &blk,
                                     int index) noexcept {
    auto bool_to_str = [](bool val) {
      if (val)
        return "Yes";
      else
        return "No";
    };
    switch (index) {
      case 0: {  // version
        const auto ver = blk.getVersion();
        if (ver < uint8_t(SCL_gameVersion::MC12)) {
          return tr("远古版本");
        }
        if (ver > (uint8_t)SlopeCraft::SCL_maxAvailableVersion()) {
          return tr("未来版本");
        }
        return QStringLiteral("1.%1").arg(int(ver));
      }
      case 1:  // need glass
        return bool_to_str(blk.getNeedGlass());
      case 2:
        return bool_to_str(blk.getDoGlow());
      case 3:
        return bool_to_str(blk.getEndermanPickable());
      case 4:
        return bool_to_str(blk.getBurnable());
      case 5:
        return blk.getStackSize();
    }
    return {};
  }

  QVariant data(const QModelIndex &qmi, int role) const noexcept final {
    if (not qmi.isValid()) {
      return {};
    }
    if (role not_eq Qt::ItemDataRole::DisplayRole) {
      return {};
    }
    const auto current_block = this->selected_block();
    switch (qmi.column()) {
      case 0:
        return key_name(qmi.row());
      case 1: {
        if (current_block == nullptr) {
          return {};
        }
        return value_of_attribute(*current_block, qmi.row());
      }
    }
    return {};
  }
};

BlockListDialog::BlockListDialog(SCWind *parent, BlockListManager *blm)
    : QDialog{parent}, ui{new Ui::BlockListDialog} {
  this->ui->setupUi(this);

  {
    auto get_block_lists = [blm]()
        -> std::vector<
            std::pair<QString, const SlopeCraft::block_list_interface *>> {
      return blm->get_block_lists();
    };
    this->block_list_provider =
        new BLD_block_list_provider{this, get_block_lists};
    this->ui->lv_block_lists->setModel(this->block_list_provider);
  }
  {
    auto get_selected_block_list =
        [this]() -> const SlopeCraft::block_list_interface * {
      const auto qmi = this->ui->lv_block_lists->currentIndex();
      if (not qmi.isValid()) {
        return nullptr;
      }
      const int idx = qmi.row();
      const auto available_lists =
          this->block_list_provider->available_block_lists();
      if (idx < 0 or idx >= available_lists.size()) {
        return nullptr;
      }
      return available_lists[idx].second;
    };
    auto get_lang = [parent]() -> SCL_language { return parent->lang(); };
    this->block_provider =
        new BLD_block_provider{this, get_selected_block_list, get_lang};
    this->ui->lv_blocks->setModel(this->block_provider);
  }
  {
    auto get_selected_block =
        [this]() -> const SlopeCraft::mc_block_interface * {
      const auto qmi = this->ui->lv_blocks->currentIndex();
      if (not qmi.isValid()) {
        return nullptr;
      }
      const int idx = qmi.row();
      const auto available_blocks = this->block_provider->available_blocks();
      if (idx < 0 or idx >= available_blocks.size()) {
        return nullptr;
      }
      return available_blocks[idx];
    };
    this->block_info_provider =
        new BLD_block_info_provider{this, get_selected_block};
    this->ui->tv_block_props->setModel(this->block_info_provider);
  }

  connect(this->ui->lv_block_lists->selectionModel(),
          &QItemSelectionModel::selectionChanged, [this]() {
            this->block_provider->dataChanged({}, {},
                                              {Qt::ItemDataRole::DisplayRole});
          });
  connect(this->ui->lv_blocks->selectionModel(),
          &QItemSelectionModel::selectionChanged, [this]() {
            this->block_info_provider->dataChanged(
                {}, {}, {Qt::ItemDataRole::DisplayRole});

            auto blk = this->block_info_provider->selected_block();
            this->update_info(blk);
          });

  connect(this->ui->pb_ok, &QPushButton::clicked, this, &QDialog::accept);
}

BlockListDialog::~BlockListDialog() {
  // delete this->ui;
}

void BlockListDialog::update_info(
    const SlopeCraft::mc_block_interface *blk) noexcept {
  if (blk == nullptr) {
    this->ui->lb_image->setPixmap({});
    this->ui->le_id->clear();
    this->ui->le_id_old->clear();
    this->ui->le_name_cn->clear();
    this->ui->le_name_en->clear();
    return;
  }
  {
    QImage img{blk->imageCols(), blk->imageRows(), QImage::Format_ARGB32};
    blk->getImage(reinterpret_cast<uint32_t *>(img.scanLine(0)));
    img = img.scaledToHeight(64);
    this->ui->lb_image->setPixmap(QPixmap::fromImage(img));
  }
  this->ui->le_id->setText(blk->getId());
  this->ui->le_id_old->setText(blk->getIdOld());
  this->ui->le_name_cn->setText(QString::fromUtf8(blk->getNameZH()));
  this->ui->le_name_en->setText(QString::fromUtf8(blk->getNameEN()));
}