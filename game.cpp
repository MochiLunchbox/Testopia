#include "game.hpp"

#include <stdexcept>
#include <string>

#ifdef _WIN32 // SDL imports for Windows
#include <SDL.h>
#endif

#ifdef __linux__ // SDL imports for Linux
#include <SDL2/SDL.h>
#endif

using namespace std;

Game::Game()
    : window_{NULL},
      renderer_{NULL},
      running_{false} {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    throw runtime_error{"SDL could not initialize! SDL error: "
                        + static_cast<string>(SDL_GetError())};
  }

  // Initalize window
  window_ = SDL_CreateWindow("Testopia", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, 1280, 800,
                             SDL_WINDOW_SHOWN);
  if (!window_) {
    throw runtime_error{"Window could not be created! SDL error: "
                        + static_cast<string>(SDL_GetError())};
  }

  // Create renderer
  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED |
                                 SDL_RENDERER_PRESENTVSYNC);
  if (!renderer_) {
    throw runtime_error{"Renderer could not be created! SDL error: "
                        + static_cast<string>(SDL_GetError())};
  }
  SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);

  running_ = true;
}

Game::~Game() {
  // Free window and renderer
  if (window_) {
    SDL_DestroyWindow(window_);
    window_ = NULL;
  }
  if (renderer_) {
    SDL_DestroyRenderer(renderer_);
    renderer_ = NULL;
  }

  // Quit SDL
  SDL_Quit();
}

void Game::Render() {
  // Clear the window
  SDL_RenderClear(renderer_);

  // Show what has been drawn
  SDL_RenderPresent(renderer_);
}

void Game::Update() {
  // placeholder
}

void Game::HandleEvents() {
  SDL_Event e;
  while (SDL_PollEvent(&e) != 0) {
    if (e.type == SDL_QUIT) {
      running_ = false;
    }
  }
}
