#pragma once
#include "Creatures.h"
#include <iostream>

using namespace std;

class GabesArmada : public Creatures
{
public:
	GabesArmada();
	~GabesArmada();

	int getHealth();
	void setHealth(int nHealth);

	int getAttack();
	void setAttack(int nAttack);


protected:

	int m_nHealth;
	int m_nAttack;

};

