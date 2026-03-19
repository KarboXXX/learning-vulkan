#include "lv-pipeline.hpp"
#include "engine_device.hpp"
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <vulkan/vulkan_core.h>

namespace lv {
LvPipeline::LvPipeline(lv::LvDevice &device, const std::string &vert_filepath,
                       const std::string &frag_filepath,
                       const PipelineConfigInfo &pipeline_config)
    : device{device} {
  create_pipeline(vert_filepath, frag_filepath, pipeline_config);
}

std::vector<char> LvPipeline::read_file(const std::string &filepath) {
  std::ifstream file{filepath, std::ios::ate | std::ios::binary};

  if (!file.is_open()) {
    throw std::runtime_error("failed to open file. " + filepath);
  }

  size_t size = static_cast<size_t>(file.tellg());
  std::vector<char> buf(size);

  file.seekg(0);
  file.read(buf.data(), size);
  return buf;
}

void LvPipeline::create_pipeline(const std::string &vert_filepath,
                                 const std::string &frag_filepath,
                                 const PipelineConfigInfo &pipeline_config) {
  auto vert_code = read_file(vert_filepath);
  auto frag_code = read_file(frag_filepath);

  std::cout << "vert size: " << vert_code.size() << std::endl;
  std::cout << "frag size: " << frag_code.size() << std::endl;
}

void LvPipeline::create_shader_module(const std::vector<char> &code,
                                      VkShaderModule *module) {
  VkShaderModuleCreateInfo create_info{};
  create_info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
  create_info.codeSize = code.size();
  create_info.pCode = reinterpret_cast<const uint32_t *>(code.data());

  if (vkCreateShaderModule(device.device(), &create_info, nullptr, module) !=
      VK_SUCCESS) {
    throw std::runtime_error("failed to create shader module");
  }
}

  PipelineConfigInfo LvPipeline::default_pipeline_config_info(uint32_t width,
                                                            uint32_t height) {
  PipelineConfigInfo config{};
  return config;
}
} // namespace lv
