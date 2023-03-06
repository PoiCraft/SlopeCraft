#ifndef SLOPECRAFT_VCCL_INTERNAL_H
#define SLOPECRAFT_VCCL_INTERNAL_H

#include <VisualCraftL.h>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

struct inputs {

  // resource
  std::vector<std::string> zips;
  std::vector<std::string> jsons;

  // colors
  SCL_gameVersion version;
  uint8_t layers{1};
  VCL_face_t face;
  SCL_convertAlgo algo;
  bool dither{false};
  bool show_color_num{false};
  VCL_biome_t biome{VCL_biome_t::the_void};
  bool leaves_transparent{false};
  //  images
  std::vector<std::string> images;

  // exports
  std::string prefix;
  bool make_converted_image{false};
  bool make_flat_diagram{false};
  int flat_diagram_splitline_margin_row{16};
  int flat_diagram_splitline_margin_col{16};
  bool make_litematic{false};
  bool make_schematic{false};
  bool make_structure{false};
  bool structure_is_air_void{true};

  inline bool need_to_read() const noexcept { return true; }

  inline bool need_to_convert() const noexcept {
    return this->make_converted_image || this->make_flat_diagram ||
           this->need_to_build();
  }
  inline bool need_to_build() const noexcept {
    return this->make_litematic || this->make_schematic || this->make_structure;
  }
  // compute
  uint16_t num_threads;
  bool benchmark{false};

  // gpu
  bool prefer_gpu{false};
  bool show_gpu{false};
  uint8_t platform_idx{0};
  uint8_t device_idx{0};
  bool list_gpu{false};

  // others
  bool disable_config{false};
  bool list_supported_formats{false};
  bool list_blockstates{false};
  bool list_models{false};
  bool list_textures{false};
};

int run(const inputs &input) noexcept;
int set_resource(VCL_Kernel *kernel, const inputs &input) noexcept;
int set_allowed(VCL_block_state_list *bsl, const inputs &input) noexcept;

SCL_convertAlgo str_to_algo(std::string_view str, bool &ok) noexcept;

int list_gpu();

struct config {
  std::vector<std::string> default_zips_12;
  std::vector<std::string> default_zips_latest;
  std::vector<std::string> default_jsons;
};

bool load_config(std::string_view filename, config &cfg) noexcept;

void list_supported_formats() noexcept;

#endif // #ifndef SLOPECRAFT_VCCL_INTERNAL_H