#include <iostream>

#include "../../include/Window/window.hpp"
#include "SDL_render.h"
#include "SDL_surface.h"

bool Window::initialize() {
  if (SDL_Init(SDL_INIT_VIDEO)) {
    std::cout << "Failed to initialize SDL Video: " << SDL_GetError()
              << std::endl;
    return false;
  }

  this->window =
      SDL_CreateWindow("CPP Wavefunction Collapse", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 760, 600, WINDOW_FLAGS);
  if (this->window == nullptr) {
    std::cout << "Failed to create SDL window: " << SDL_GetError() << std::endl;
    return false;
  }

  this->renderer =
      SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
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
    while (SDL_PollEvent(&this->event)) {
      isRunning = this->event.type != SDL_QUIT;
    }
  }
}

void Window::render_image(const char *img_path) {
  SDL_RenderClear(this->renderer);
  SDL_Surface *surface = SDL_LoadBMP(img_path);

  if (surface == nullptr) {
    std::cout << "Failed to load image: " << SDL_GetError() << std::endl;
    return;
  }

  this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
  if (this->texture == nullptr) {
    std::cout << "Failed to create texture from surface: " << SDL_GetError()
              << std::endl;
    return;
  }

  SDL_FreeSurface(surface);
  SDL_RenderCopy(this->renderer, this->texture, NULL, NULL);
  SDL_RenderPresent(this->renderer);
}
