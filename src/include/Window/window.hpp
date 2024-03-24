#include <SDL2/SDL.h>

const auto WINDOW_FLAGS = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;

class Window {
private:
  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
  SDL_Texture *texture = nullptr;

  SDL_Event event;

  bool isRunning = false;

public:
  ~Window() {
    if (this->window != nullptr) {
      SDL_DestroyWindow(this->window);
    }

    if (this->renderer != nullptr) {
      SDL_DestroyRenderer(this->renderer);
    }

    if (this->texture != nullptr) {
      SDL_DestroyTexture(this->texture);
    }

    SDL_Quit();

    this->window = nullptr;
    this->renderer = nullptr;
    this->texture = nullptr;
  }

  bool initialize();
  void run();

  void render_image(const char *img_path);
};
