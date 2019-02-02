#include "game.hpp"

int main() {
	Game game;
	while(!game.GetWindow()->IsDone()) {
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();	// Restarting our clock
	}

	return 0;
}