#include "CRandomSearch.h"

CRandomSearch::CRandomSearch(CMscnProblem* mscn)
{
	srand(time(NULL));

	int length_of_solution = mscn->getAmountOfProvider() * mscn->getAmountOfFabrics() +
		mscn->getAmountOfFabrics() * mscn->getAmountOfMagazines() +
		mscn->getAmountOfMagazines() * mscn->getAmountOfShops();

	first_solution = new double[length_of_solution];
	double* dSolution = mscn->dGetSolution();
	for (int ii = 0; ii < length_of_solution; ii++)
		first_solution[ii] = dSolution[ii];
	len = length_of_solution;
}

void CRandomSearch::findBestSolution(CMscnProblem* mscn)
{
	

	int length_of_solution = mscn->getAmountOfProvider() * mscn->getAmountOfFabrics() +
		mscn->getAmountOfFabrics() * mscn->getAmountOfMagazines() +
		mscn->getAmountOfMagazines() * mscn->getAmountOfShops();
	double* best_solution = new double[length_of_solution];

	

	double* old_solution = mscn->dGetSolution();

	for (int ii = 0; ii < length_of_solution; ii++)
		best_solution[ii] = old_solution[ii];

	
	bool is_better_res = false;
	int number_of_attemps = 1;
	//  zmiana tablicy rozwiazania
	while (is_better_res == false && number_of_attemps <= MAX_NUMBER_OF_ATTEMPS)
	{
		for (int ii = 0; ii < length_of_solution; ii++)
		{
			int change = rand() % 10 - 5;
			if (best_solution[ii] + change < 0)
				best_solution[ii] += 10;
			else best_solution[ii] += change;
		}
		// widac wszystkie proby
//		cout << mscn->dGetQuality(best_solution) << "\n";
		if (mscn->dGetQuality(best_solution) - mscn->dGetQuality(old_solution) > MINIMAL_BETTER_RESULT)
		{
			is_better_res = true;
		}
		number_of_attemps++;
	}

	if (number_of_attemps < MAX_NUMBER_OF_ATTEMPS && is_better_res == true)
	{
		cout << "Znaleziono optymalniejsze rozwiazanie!\n";
		cout << "Tablica rozwiazan: ";
		for (int ii = 0; ii < length_of_solution; ii++)
			cout << best_solution[ii] << " ";
		cout << "dGetQuality: " << mscn->dGetQuality(best_solution) << "\n";
		cout << "Ilosc prob: " << number_of_attemps << "\n";
	}
	else cout << "Nie znaleziono optymalniejszego rozwiazania!\n";

	if (is_better_res == false)
	{
		delete best_solution;
		mscn->load_solution(old_solution);

	}
	else 
	{
		delete old_solution;
		mscn->load_solution(best_solution);

	}
}

void CRandomSearch::Optimalize(int amount, CMscnProblem* mscn)
{
	for (int ii = 0; ii < amount; ii++)
		this->findBestSolution(mscn);
//	this->vPrintChangedResults(mscn);
}
//modyfikacja z zajec
void CRandomSearch::vPrintChangedResults(CMscnProblem* mscn)
{
	cout << "Podsumowanie: \n";
	cout << "Wypisana tablica bedzie % wartosci maxymalnej\n\n";
	cout << "Stara tablica: ";
	
	double* new_solution = mscn->dGetSolution();
	int ii = 0;
	for (; ii < mscn->getAmountOfProvider() * mscn->getAmountOfFabrics(); ii++)
		cout << (first_solution[ii]-MinZakresXD) / (MaxZakresXD-MinZakresXD) * 100 << "% ";
	for (; ii < (mscn->getAmountOfProvider() * mscn->getAmountOfFabrics()) + (mscn->getAmountOfFabrics() * mscn->getAmountOfMagazines()); ii++)
		cout << (first_solution[ii]- MinZakresXF) / (MaxZakresXF-MinZakresXF) * 100 << "% ";
	for (; ii < len; ii++)
		cout << (first_solution[ii]- MinZakresXM) / (MaxZakresXM-MinZakresXM) * 100 << "% ";
	cout << "\nNowa Tablica: ";
	ii = 0;
	for (; ii < mscn->getAmountOfProvider() * mscn->getAmountOfFabrics(); ii++)
		cout << (new_solution[ii]-MinZakresXD) /(MaxZakresXD-MinZakresXD) * 100 << "% ";
	for (; ii < (mscn->getAmountOfProvider() * mscn->getAmountOfFabrics()) + (mscn->getAmountOfFabrics() * mscn->getAmountOfMagazines()); ii++)
		cout << (new_solution[ii]- MinZakresXF) / (MaxZakresXF-MinZakresXF) * 100 << "% ";
	for (; ii < len; ii++)
		cout << (new_solution[ii]-MinZakresXM) / (MaxZakresXM-MinZakresXM) * 100 << "% ";

	cout << "\n\n\n";

}
