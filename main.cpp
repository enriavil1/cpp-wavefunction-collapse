#include "src/include/Window/window.hpp"

int main() {
  Window window;

  auto succesful = window.initialize();
  if (!succesful) {
    return -1;
  }

  window.run();
  return 0;
}
