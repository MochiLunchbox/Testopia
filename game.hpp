#pragma once

#ifdef _WIN32 // SDL imports for Windows
#include <SDL.h>
#endif

#ifdef __linux__ // SDL imports for Linux
#include <SDL2/SDL.h>
#endif

class Game {
 public:
  Game();
  ~Game();
  Game(const Game&) = delete;
  Game& operator=(const Game&) = delete;
  Game(Game&&) = delete;
  Game& operator=(Game&&) = delete;

  void Render();
  void Update();
  void HandleEvents();

  bool running() const {
    return running_;
  }

 private:
  SDL_Window* window_;
  SDL_Renderer* renderer_;

  bool running_;
};
