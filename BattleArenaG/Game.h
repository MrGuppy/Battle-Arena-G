#pragma once
#include "GoblinSpawn.h"
#include "GabesArmada.h"
class Game
{
public:
	Game(int nGoblinCount, int nArmadaCount);
	~Game();

	void sortFaction();
	bool gameStart();
	void Menu();
	bool checkAliveGoblin();
	bool checkAliveArmada();
private:
	GoblinSpawn** m_apGoblin;
	GabesArmada** m_apArmada;

	GoblinSpawn* tempGoblin;
	GabesArmada* tempArmada;

	int m_nArmadaCount;
	int m_nArmadaLeft;

	int m_nGoblinCount;
	int m_nGoblinLeft;


};
