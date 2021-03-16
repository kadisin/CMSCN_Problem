#ifndef CDiffEvol_H
#define CDiffEvol_H


#include "CMscnProblem.h"
#include <time.h>

#define MIN_VALUE 4500

class CDiffEvol
{
public:
	CDiffEvol(CMscnProblem* mscn);
	double* getRandomInd();
	double* getGenotyp() { return genotyp;  }
	double dCheckTheResult();
	int getLengthGenotyp();
	void vSetGenotypValue(int index, double value);
	CMscnProblem* getTheBestCMscn();
	CMscnProblem* getTheBestCMscn(int M);


private:
	double* genotyp;
	int i_length;
	CMscnProblem* mscn;

	bool individualsAreDiffrent(int len, double* ind, double* baseInd, double* addInd0, double* addInd1);
	double GetRandomReal(double v_min, double v_max);
	bool check_the_result(double* Solution);
	bool check_the_value(int index, double value);
	double change_the_value(int index);

};


#endif