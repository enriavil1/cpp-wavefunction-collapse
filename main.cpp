#include "src/include/Window/window.hpp"
#include <iostream>

const std::string BMP_POSTFIX = ".bmp";

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "Missing bitmap image" << std::endl;
    return -1;
  }

  // argument with the path to the bitmap image
  std::string img_bmp_path = argv[1];
  if (img_bmp_path.size() <= BMP_POSTFIX.size() ||
      !img_bmp_path.ends_with(BMP_POSTFIX)) {
    std::cout << "Inputted argument path is invalid, expected: bitmap got: "
              << img_bmp_path << std::endl;
    return -1;
  }

  Window window;

  auto succesful = window.initialize();
  if (!succesful) {
    return -1;
  }

  window.render_image(img_bmp_path.c_str());
  window.run();
  return 0;
}
