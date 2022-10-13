#include <iostream>
#include <stdexcept>

#ifdef _WIN32 // SDL imports for Windows
#include <SDL.h>
#endif

#ifdef __linux__ // SDL imports for Linux
#include <SDL2/SDL.h>
#endif

#include "game.hpp"

using namespace std;

int main() {
  try {
    Game game{};
    while (game.running()) {
      game.HandleEvents();
      game.Update();
      game.Render();
    }
  } catch (std::exception& ex) {
    cout << "Exception!\n" << ex.what() << endl;
  }
}
