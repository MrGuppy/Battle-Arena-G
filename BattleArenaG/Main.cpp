#include <iostream>
#include "Game.h"
#include "GoblinSpawn.h"
#include "time.h"
using namespace std;

void main()
{
	//create menu

	srand((int)time(0));
	Game* playGame = new Game(10, 10);
	playGame->Menu();
	while (playGame->gameStart())
	{

	}
	system("pause");
	delete playGame;
}