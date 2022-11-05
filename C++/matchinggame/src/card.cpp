#include "card.h"
#include <iostream>

using namespace std;

Card::Card()
{
	m_value = 0;
	m_active = false;
	m_found = false;
}

Card::~Card() {}

void Card::setValue(int a)
{
	m_value = a;
}

void Card::setActive(bool a)
{
	m_active = a;
}

void Card::setFound(bool a)
{
	m_found = a;
}

int Card::getValue()
{
	return m_value;
}

bool Card::getActive()
{
	return m_active;
}

bool Card::getFound()
{
	return m_found;
}

void Card::draw() // Decide what to draw
{
	if (m_found)
	{
		cout << "     ";
	}
	else if (m_active)
	{
		cout << "[" << m_value << "]  ";
	}
	else
	{
		cout << "[*]  ";
	}
}