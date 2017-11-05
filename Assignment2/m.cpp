#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "globals.h"
#include "game.h"
#include "utilities.cpp"


int decodeDirection(char dir);
void clearScreen();



int main()
{
	// Initialize the random number generator.  (You don't need to
	// understand how this works.)
	srand(static_cast<unsigned int>(time(0)));

	// Create a game
	// Use this instead to create a mini-game:   Game g(3, 3, 2);
	Game g(15, 18, 80);

	// Play the game
	g.play();
}
