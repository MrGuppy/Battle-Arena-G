#include "GabesArmada.h"
#include <iostream>

using namespace std;


GabesArmada::GabesArmada()
{
	m_nAttack = rand() % 50;
	m_nHealth = 100;
}

GabesArmada::~GabesArmada()
{
}

int GabesArmada::getHealth()
{
	return m_nHealth;
}

void GabesArmada::setHealth(int nHealth)
{
	m_nHealth = nHealth;
}

int GabesArmada::getAttack()
{
	return m_nAttack;
}

void GabesArmada::setAttack(int nAttack)
{
	m_nAttack = nAttack;
}


