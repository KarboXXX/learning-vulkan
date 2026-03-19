#pragma once

#include <string>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace lv {
class LvWindow {

public:
  LvWindow(int w, int h, std::string name);
  ~LvWindow();

  LvWindow(const LvWindow &) = delete;
  LvWindow &operator=(const LvWindow &) = delete;

  bool should_close();
  void create_window_surface(VkInstance instance, VkSurfaceKHR *surface);  
  
  private:
    GLFWwindow *window;
    void init_window();
    const int width;
    const int height;
    const std::string name;
  };
}
