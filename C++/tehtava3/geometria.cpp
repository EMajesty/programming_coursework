#include <iostream>
#include "geometria.h"

using namespace std;

int laskeKolmio(int kanta, int korkeus)
{
	int kAla = kanta * korkeus / 2;
	return kAla;
}

int laskeYmpyra(int sade)
{
	double pi = 2 * acos(0.0);
	sade *= sade;
	int yAla = pi * sade;
	return yAla;
}