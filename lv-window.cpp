#include "lv-window.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>
#include <vulkan/vulkan_core.h>

namespace lv {
LvWindow::LvWindow(int w, int h, std::string name)
    : width{w}, height{h}, name{name} {
  init_window();
}
LvWindow::~LvWindow() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

bool LvWindow::should_close() { return glfwWindowShouldClose(window); }

void LvWindow::create_window_surface(VkInstance instance,
                                     VkSurfaceKHR *surface) {
  if (glfwCreateWindowSurface(instance, window, nullptr, surface) !=
      VK_SUCCESS) {
    throw std::runtime_error("failed to create window surface");
  }
}

void LvWindow::init_window() {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
}
} // namespace lv
