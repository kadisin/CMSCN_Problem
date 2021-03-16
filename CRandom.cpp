#include "CRandom.h"



CRandom::CRandom()
{
	srand(time(NULL));
}

int CRandom::Random(int min, int max)
{
	
	int value = (rand() % max) + min;
	return value;
}

double CRandom::Random(double min, double max)
{
	double value = (rand() % (int)max) + min;
	return value;
}

