#include <iostream>

#include "../../include/Window/window.hpp"

bool Window::initialize() {
  if (SDL_Init(SDL_INIT_VIDEO)) {
    std::cout << "Failed to initialize SDL Video: " << SDL_GetError()
              << std::endl;
    return false;
  }

  this->window =
      SDL_CreateWindow("CPP Wavefunction Collapse", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 760, 600, SDL_WINDOW_SHOWN);
  if (this->window == nullptr) {
    std::cout << "Failed to create SDL window: " << SDL_GetError() << std::endl;
    return false;
  }

  this->renderer = SDL_CreateRenderer(this->window, -1, 0);
  if (this->renderer == nullptr) {
    std::cout << "Failed to get SDL window renderer: " << SDL_GetError()
              << std::endl;
    return false;
  }

  SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
  SDL_RenderClear(this->renderer);

  return true;
}

void Window::run() {
  this->isRunning = true;
  while (this->isRunning) {
    SDL_PollEvent(&this->event);
    isRunning = this->event.type != SDL_QUIT;
  }
}
