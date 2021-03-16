#include "CDiffEvol.h"

CDiffEvol::CDiffEvol(CMscnProblem* mscn)
{
	this->mscn = mscn;
	i_length = mscn->getLengthSolution();
	genotyp = new double[mscn->getLengthSolution()];
	srand(time(NULL));
}

double* CDiffEvol::getRandomInd()
{
	
	int ii = 0; 
	for (; ii < mscn->getAmountOfProvider() * mscn->getAmountOfFabrics(); ii++)
	{
		genotyp[ii] = (rand() % MaxZakresXD) + MinZakresXD;
	}
	for (; ii < (mscn->getAmountOfProvider() * mscn->getAmountOfFabrics()) +
		(mscn->getAmountOfFabrics() * mscn->getAmountOfMagazines()); ii++)
	{
		genotyp[ii] = (rand() % MaxZakresXF) + MinZakresXF;

	}
	for (; ii < mscn->getLengthSolution(); ii++)
	{
		genotyp[ii] = (rand() % MaxZakresXM) + MinZakresXM;
	}
	
	return genotyp;
}

double CDiffEvol::dCheckTheResult()
{
	return mscn->dGetQuality(genotyp);
}

int CDiffEvol::getLengthGenotyp()
{
	return mscn->getLengthSolution();
}

bool CDiffEvol::individualsAreDiffrent(int len, double* ind, double* baseInd, double* addInd0, double* addInd1)
{
	for (int ii = 0; ii < len; ii++)
		if (ind[ii] != baseInd[ii] ||
			ind[ii] != addInd0[ii] ||
			ind[ii] != addInd1[ii] ||
			baseInd[ii] != addInd0[ii] ||
			baseInd[ii] != addInd1[ii] ||
			addInd0[ii] != addInd1[ii])
			return true;
	return false;
}
double CDiffEvol::GetRandomReal(double v_min, double v_max)
{
	v_min = v_min * 100;
	v_max = v_max * 100;

	srand(time(NULL));
	double res = (rand() % (int)v_max) + v_min;
	return res / 100;
}
// jesli solution jest dobre - zwracam true
bool CDiffEvol::check_the_result(double* Solution)
{

	int ii = 0;
	for (; ii < mscn->getAmountOfProvider() * mscn->getAmountOfFabrics(); ii++)
	{
		if (Solution[ii] > MaxZakresXD || Solution[ii] < MinZakresXD)
			return false;
	}
	for (; ii < (mscn->getAmountOfProvider() * mscn->getAmountOfFabrics()) +
		(mscn->getAmountOfFabrics() * mscn->getAmountOfMagazines()); ii++)
	{
		if (Solution[ii] > MaxZakresXF || Solution[ii] < MinZakresXF)
			return false;

	}
	for (; ii < mscn->getLengthSolution(); ii++)
	{
		if (Solution[ii] > MaxZakresXM || Solution[ii] < MinZakresXM)
			return false;
	}

	return true;

}

bool CDiffEvol::check_the_value(int index, double value)
{
	if (index >= 0 && index < mscn->getAmountOfProvider() * mscn->getAmountOfFabrics())
		if (value > MaxZakresXD || value < MinZakresXD)
			return false;
		
	if (index >= mscn->getAmountOfProvider() * mscn->getAmountOfFabrics() &&
		index < (mscn->getAmountOfProvider() * mscn->getAmountOfFabrics()) +
		(mscn->getAmountOfFabrics() * mscn->getAmountOfMagazines()))
		if (value > MaxZakresXF || value < MinZakresXF)
			return false;
	if (index >= (mscn->getAmountOfProvider() * mscn->getAmountOfFabrics()) +
		(mscn->getAmountOfFabrics() * mscn->getAmountOfMagazines()) &&
		index < mscn->getLengthSolution())
		if (value > MaxZakresXM || value < MinZakresXF)
			return false;
	return true;

}

double CDiffEvol::change_the_value(int index)
{
	double val = 0;
	
	if (index >= 0 && index < mscn->getAmountOfProvider() * mscn->getAmountOfFabrics())
		val = (rand() % MaxZakresXD) + MinZakresXD;

	if (index >= mscn->getAmountOfProvider() * mscn->getAmountOfFabrics() &&
		index < (mscn->getAmountOfProvider() * mscn->getAmountOfFabrics()) +
		(mscn->getAmountOfFabrics() * mscn->getAmountOfMagazines()))
		val = (rand() % MaxZakresXF) + MinZakresXF;
	if (index >= (mscn->getAmountOfProvider() * mscn->getAmountOfFabrics()) +
		(mscn->getAmountOfFabrics() * mscn->getAmountOfMagazines()) &&
		index < mscn->getLengthSolution())
		val = (rand() % MaxZakresXM) + MinZakresXM;
	return val;

}


void CDiffEvol::vSetGenotypValue(int index, double value)
{
	if (index >= i_length || index < 0)
		return;
	else
		genotyp[index] = value;

}

CMscnProblem* CDiffEvol::getTheBestCMscn()
{
	//populacja
		double* baseInd = new double[mscn->getLengthSolution()];
		double* addInd0 = new double[mscn->getLengthSolution()];
		double* addInd1 = new double[mscn->getLengthSolution()];
		double* ind = new double[mscn->getLengthSolution()];
		double* newInd = new double[mscn->getLengthSolution()];

		CDiffEvol* cdiff = new CDiffEvol(mscn);
		ind = cdiff->getRandomInd();

		double crossProb = 0.4;

		//while(checkstopcondition)
		while (mscn->dGetQuality(ind) < MIN_VALUE)
		{

			
			baseInd = cdiff->getRandomInd();
			addInd0 = cdiff->getRandomInd();	
			addInd1 = cdiff->getRandomInd();
			if (individualsAreDiffrent(mscn->getLengthSolution(), ind, baseInd, addInd0, addInd1))
			{

				for (int geneOffset = 0; geneOffset < mscn->getLengthSolution(); geneOffset++)
				{
					if (GetRandomReal(0, 1) < crossProb)
					{	
						//mutacja
						double val = baseInd[geneOffset] * (addInd0[geneOffset] - addInd1[geneOffset]);
						// check_the_value sprawdza czy jest prawidlowa wartosc na indeksie
						while (this->check_the_value(geneOffset, val) == false)//3
							val = this->change_the_value(geneOffset);
						newInd[geneOffset] = val;
					}
					else
					{
						int val = ind[geneOffset];
						newInd[geneOffset] = val;

					}


				}
				if (mscn->dGetQuality(newInd) > mscn->dGetQuality(ind))
					ind = newInd;
			



			}


		}

	//	delete baseInd;
	//	delete addInd0;
	//	delete addInd1;
	//	delete newInd;

		mscn->load_solution(ind);
		return mscn;

}
//modyfikacja
CMscnProblem* CDiffEvol::getTheBestCMscn(int M)
{
	double** Ind = new double* [M];
	for (int ii = 0; ii < M; ii++)
		Ind[ii] = new double[mscn->getLengthSolution()];

	double wynik = -5;
	double* solution = new double[M];
	for (int ii = 0; ii < M; ii++)
		solution[ii] = -2;


	while (wynik < MIN_VALUE)
	{
		for (int ii = 0; ii < M; ii++)
			Ind[ii] = this->getRandomInd();



		for (int ii = 0; ii < M; ii++)
		{
			double res = mscn->dGetQuality(Ind[ii]);
			int index = 0;
			while (res < solution[index] && index < mscn->getLengthSolution())
				index++;

			for (; index < mscn->getLengthSolution() -1; index++)
			{
			double sw = solution[index];
			solution[index] = res;
			solution[index + 1] = sw;
			}
		}

		
		wynik = solution[0];

	}
	int ind_1 = -1;
	int ind_2 = -1;
	int ind_3 = -1;
	for (int ii = 0; ii < M; ii++)
	{
		if (mscn->dGetQuality(Ind[ii]) == solution[0])
			ind_1 = ii;
		if (mscn->dGetQuality(Ind[ii]) == solution[1])
			ind_2 = ii;
		if (mscn->dGetQuality(Ind[ii]) == solution[2])
			ind_3 = ii;
	}


	double* srednia = new double[mscn->getLengthSolution()];
	for (int ii = 0; ii < mscn->getLengthSolution(); ii++)
		srednia[ii] = (Ind[ind_1][ii] + Ind[ind_2][ii] + Ind[ind_3][ii]) / 3;
	if (mscn->dGetQuality(srednia) < mscn->dGetQuality(Ind[ind_1]))
		srednia = Ind[ind_1];
	cout << mscn->dGetQuality(srednia);
	mscn->load_solution(srednia);
	return mscn;
}



