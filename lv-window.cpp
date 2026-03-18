#include "lv-window.hpp"
#include <GLFW/glfw3.h>
#include <string>

namespace lv {
  LvWindow::LvWindow(int w, int h, std::string name) : width{w}, height{h}, name{name} { init_window(); }
  LvWindow::~LvWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();  
  }
  
  void LvWindow::init_window() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    }
}
