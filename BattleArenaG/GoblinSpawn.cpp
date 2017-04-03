#include "GoblinSpawn.h"
#include <iostream>

using namespace std;

GoblinSpawn::GoblinSpawn()
{
	m_nAttack = rand() % 50;
	m_nHealth = 100;

}

GoblinSpawn::~GoblinSpawn()
{
}

int GoblinSpawn::getHealth()
{
	return m_nHealth;
}

void GoblinSpawn::setHealth(int nHealth)
{
	m_nHealth = nHealth;
}



int GoblinSpawn::getAttack()
{
	return m_nAttack;
}

void GoblinSpawn::setAttack(int nAttack)
{
	m_nAttack = nAttack;
}

