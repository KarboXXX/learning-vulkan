#pragma once

#include "engine_device.hpp"
#include <cstdint>
#include <string>
#include <vector>
#include <vulkan/vulkan_core.h>
namespace lv {
struct PipelineConfigInfo {};
class LvPipeline {

public:
  LvPipeline(LvDevice &device, const std::string &vert_filepath,
             const std::string &frag_filepath,
             const PipelineConfigInfo &pipeline_config);
  ~LvPipeline() {}

  LvPipeline(const LvPipeline &) = delete;
  void operator=(const LvPipeline &) = delete;

  static PipelineConfigInfo default_pipeline_config_info(uint32_t width,
                                                         uint32_t height);

private:
  static std::vector<char> read_file(const std::string &filepath);

  void create_pipeline(const std::string &vert_filepath,
                       const std::string &frag_filepath,
                       const PipelineConfigInfo &pipeline_config);
  void create_shader_module(const std::vector<char> &code,
                            VkShaderModule *module);

  LvDevice &device;
  VkPipeline graphics_pipeline;
  VkShaderModule vert_shader_module;
  VkShaderModule frag_shader_module;
};
} // namespace lv
