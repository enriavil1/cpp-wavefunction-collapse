#include <SDL2/SDL.h>

class Window {
private:
  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
  SDL_Event event;

  bool isRunning = false;

public:
  ~Window() {
    if (this->window == nullptr) {
      SDL_DestroyWindow(this->window);
    }

    SDL_Quit();

    this->window = nullptr;
    this->renderer = nullptr;
  }

  bool initialize();
  void run();
};
