#ifndef SLOPECRAFT_VISUALCRAFTL_TOKIVC_H
#define SLOPECRAFT_VISUALCRAFTL_TOKIVC_H

#include "BlockStateList.h"
#include "ParseResourcePack.h"
#include "VisualCraftL.h"

#include <utilities/ColorManip/colorset_optical.hpp>
#include <utilities/ColorManip/imageConvert.hpp>

#include <variant>

#include <shared_mutex>

class TokiVC : public VCL_Kernel {
public:
  TokiVC();
  virtual ~TokiVC();

  VCL_Kernel_step step() const noexcept override;

  bool set_image(const int64_t rows, const int64_t tcols,
                 const uint32_t *const img_argb,
                 const bool is_row_major) noexcept override;

  int64_t rows() const noexcept override;
  int64_t cols() const noexcept override;

  const uint32_t *raw_image(int64_t *const rows, int64_t *const cols,
                            bool *const is_row_major) const noexcept override;

public:
  static libImageCvt::template ImageCvter<false>::basic_colorset_t
      colorset_basic;
  static libImageCvt::template ImageCvter<false>::allowed_colorset_t
      colorset_allowed;

  static VCL_resource_pack pack;
  static VCL_block_state_list bsl;
  static SCL_gameVersion version;
  static VCL_face_t exposed_face;
  static int max_block_layers;

  static bool update_color_set_no_lock() noexcept;

private:
  static std::vector<
      std::variant<const VCL_block *, std::vector<const VCL_block *>>>
      LUT_basic_color_idx_to_blocks;

private:
  VCL_Kernel_step _step{VCL_Kernel_step::VCL_wait_for_resource};

  libImageCvt::ImageCvter<false> img_cvter;
};

namespace TokiVC_internal {
extern std::shared_mutex global_lock;
extern bool is_basic_color_set_ready;
extern bool is_allowed_color_set_ready;
} // namespace TokiVC_internal

#endif // SLOPECRAFT_VISUALCRAFTL_TOKIVC_H