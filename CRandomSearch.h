#ifndef CRandomSearch_H
#define CRandomSearch_H

#include "MscnDefines.h"
#include <iostream>
#include <time.h>
#include "CMscnProblem.h"
using namespace std;

#define MINIMAL_BETTER_RESULT 200
#define MAX_NUMBER_OF_ATTEMPS 10000

class CRandomSearch
{
public:
	CRandomSearch(CMscnProblem* mscn);
	void findBestSolution(CMscnProblem* mscn);
	void Optimalize(int amount, CMscnProblem* mscn);
	void vPrintChangedResults(CMscnProblem* mscn);

private:
	double* first_solution;
	int len;

};

#endif