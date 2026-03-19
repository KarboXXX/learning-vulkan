#include "lv-pipeline.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace lv {

LvPipeline::LvPipeline(const std::string &vert_filepath,
                       const std::string &frag_filepath) {
  create_pipeline(vert_filepath, frag_filepath);
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
                                 const std::string &frag_filepath) {
  auto vert_code = read_file(vert_filepath);
  auto frag_code = read_file(frag_filepath);

  std::cout << "vert size: " << vert_code.size() << std::endl;
  std::cout << "frag size: " << frag_code.size() << std::endl;
}
} // namespace lv
