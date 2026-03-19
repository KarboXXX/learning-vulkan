#pragma once

#include "engine_device.hpp"
#include "lv-pipeline.hpp"
#include "lv-window.hpp"

namespace lv {
class VulkanApp {
public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  void run();

private:
  LvWindow lv_window{WIDTH, HEIGHT, "vulkan example app"};
  LvDevice device{lv_window};
  LvPipeline lv_pipeline{device, "shaders/shader.vert.spv", "shaders/shader.frag.spv", LvPipeline::default_pipeline_config_info(WIDTH, HEIGHT)};
};
} // namespace lv
