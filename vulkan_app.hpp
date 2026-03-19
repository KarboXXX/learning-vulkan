#pragma once

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
  LvPipeline lv_pipeline{"shaders/shader.vert.spv", "shaders/shader.frag.spv"};
};
} // namespace lv
