#include <iostream>

#include <SDL2/SDL.h>

int main() {
  SDL_Window *window = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO)) {
    std::cout << "Failed to initialize SDL Video: " << SDL_GetError()
              << std::endl;
    return -1;
  }

  window = SDL_CreateWindow("CPP Wavefunction Collapse", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    std::cout << "Failed to create SDL window " << SDL_GetError() << std::endl;
    return -1;
  }

  SDL_UpdateWindowSurface(window);
  SDL_Delay(20000);

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
