#include "Game.h"
#include <iostream>
using namespace std;


Game::Game(int nGoblinCount, int nArmadaCount)
{
	m_apGoblin = new GoblinSpawn*[nGoblinCount];

	for (int i = 0; i < nGoblinCount; ++i)
	{
		m_apGoblin[i] = new GoblinSpawn();
	}
	m_nGoblinCount = nGoblinCount;
	m_nGoblinLeft = nGoblinCount;

	m_apArmada = new GabesArmada*[nArmadaCount];

	for (int i = 0; i < nArmadaCount; ++i)
	{
		m_apArmada[i] = new GabesArmada();
	}
	m_nArmadaCount = nArmadaCount;
	m_nArmadaLeft = nArmadaCount;
}

Game::~Game()
{
	for (int i = 0; i < m_nGoblinCount; ++i)
	{
		delete[] m_apGoblin[i];
	}
	delete m_apGoblin;

	for (int i = 0; i < m_nArmadaCount; ++i)
	{
		delete[] m_apArmada[i];
	}
	delete m_apArmada;
}

void Game::Menu()
{
	cout << "                 welcome to the BATTLE ARENA!!" << endl << endl;
	cout << "    May the battle between the Goblins and Gabes spanish Armada fleet begin!" << endl;
	system("pause");
}

void Game::sortFaction()
{
	//bubblesort
	for (int i = 0; i < m_nGoblinCount - 1; ++i)
	{
		for (int j = 0; j < m_nGoblinCount - 1; ++j)
		{
			if (m_apGoblin[j]->getHealth() > m_apGoblin[j + 1]->getHealth())
			{
				tempGoblin = m_apGoblin[j];
				m_apGoblin[j] = m_apGoblin[j + 1];
				m_apGoblin[j + 1] = tempGoblin;
			}
		}
	}
	//seperate!
	for (int i = 0; i < m_nArmadaCount - 1; ++i)

	{
		for (int j = 0; j < m_nArmadaCount - 1; ++j)
		{
			if (m_apArmada[j]->getHealth() > m_apArmada[j + 1]->getHealth())
			{
				tempArmada = m_apArmada[j];
				m_apArmada[j] = m_apArmada[j + 1];
				m_apArmada[j + 1] = tempArmada;
			}
		}
	}
}

bool Game::gameStart()
{
	int nGoblin = (rand() % m_nGoblinCount); //initializing a random Goblin in array
	int nArmada = (rand() % m_nArmadaCount); // initializing a random Armada in array

	if (checkAliveGoblin() && checkAliveArmada())
	{
		if (m_apGoblin[nGoblin]->getHealth() > 0 && m_apArmada[nArmada]->getHealth() > 0)
		{

			int nGoblinAttack = m_apGoblin[nGoblin]->getAttack(); //intializing Goblin Attack
			int nGoblinHealth = m_apGoblin[nGoblin]->getHealth(); //initializing Goblin Health

			int nArmadaAttack = m_apArmada[nArmada]->getAttack(); //intializing Armada Attack
			int nArmadaHealth = m_apArmada[nArmada]->getHealth();//intializing Armada Health
			int nNewGoblinHealth = nGoblinAttack - nArmadaAttack;
			int nNewArmadaHealth = nArmadaHealth - nGoblinAttack;



			if (nNewGoblinHealth <= 0)
			{
				--m_nGoblinLeft;
				nNewGoblinHealth = 0;
			}
			if (nNewArmadaHealth <= 0)
			{
				--m_nArmadaLeft;
				nNewArmadaHealth = 0;
			}
			m_apGoblin[nGoblin]->setHealth(nNewGoblinHealth);
			m_apArmada[nArmada]->setHealth(nNewArmadaHealth);
			if (nGoblin != nArmada)
			{
				cout << "---------------------------------------------------------------------------------------" << endl;
				cout << " the wicked, slimy Goblin kicks sand at the Spanish Armada fleet.  the creature delt " << endl;
				cout << nGoblinAttack << " damage? The Spanish warship now has " << nNewArmadaHealth << " hp " << endl;
				cout << "until they abondon ship!" << endl;
				cout << "---------------------------------------------------------------------------------------" << endl;


				cout << "-----------------------------------------------------------------------------------------------------" << endl;
				cout << "  The full frontier of the Spanish military fired Cannons at the Goblins on the beach. The Armada delt" << endl;
				cout << nArmadaAttack << " damage!! The Goblins screaming, and hiding over sand dunes now have " << nNewGoblinHealth << endl;
				cout << " hp. They realise they have to retaliate." << endl;
				cout << "-----------------------------------------------------------------------------------------------------" << endl;

				sortFaction();

				for (int i = 0; i < 10; ++i)
				{
					if (m_apGoblin[i]->getHealth() == 0)
					{
						cout << "goblin dies" << endl;
					}
					if (m_apArmada[i]->getHealth() == 0)
					{
						cout << "ship is destroyed" << endl;
					}
					cout << "Goblin Health; " << m_apGoblin[i]->getHealth() << "HP" <<  endl << endl;;
					cout << "Armada Warship" << m_apArmada[i]->getHealth() << "HP" << endl;
					
				}
			}
			system("pause");
		}
			
	}

	else
	{
		for (int i = 0; i < 10; ++i)
		{
			if (m_apGoblin[i] > 0)
			{
				cout << "SPAIN RULES WONCE AGAIN!" << endl;

				return false;
			}
			if (m_apArmada[i] > 0)
			{
				cout << "Appearantly throwing sand at warships save the day!" << endl;
				cout << "Goblins win!" << endl;

				return false;
			}
			if (m_apArmada[i] > 0 && m_apGoblin[i])
			{
				cout << "SPAIN RULES WONCE AGAIN!" << endl;

				return false;
			}
		}
	}
	return true;
}	

bool Game::checkAliveGoblin()
{
	for (int i = 0; i < 10; ++i)
	{
		if (m_apGoblin[i]->getHealth() > 0)
		{
			return true;
		}
	}
	return false;
}

bool Game::checkAliveArmada()
{
	for (int i = 0; i < 10; ++i)
	{
		if (m_apArmada[i]->getHealth() > 0)
		{
			return true;
		}
	}
	return false;
}