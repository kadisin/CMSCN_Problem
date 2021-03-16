#include "CMscnProblem.h"
#include "SaveSolution.h"
#include "LoadSolution.h"
#include "LoadProblem.h"
#include "CRandom.h"
#include "CRandomSearch.h"
#include "CDiffEvol.h"

void vTestRandom();
void vTestEvol();
void vXD();
int main()
{
/*
	//vTestRandom();
	cout << "Przyk³ad 1: Losowe dane: \n\n";
	CMscnProblem* cmscnproblem = new CMscnProblem(2, 3, 3, 5);
	cmscnproblem->randomValues();
	cout <<"KT: "<< cmscnproblem->dGetKT() << "!\n";
	cout <<"KU: " << cmscnproblem->dGetKU() << "!\n";
	cout <<"P : " << cmscnproblem->dGetP() << "!\n";
	cout << "Z : " << cmscnproblem->dGetZ() << "!\n";
	cmscnproblem->vPrintZ();
	delete cmscnproblem;

	cout << "\n\n\n";
	cout << "Przyklad 2: Tworze problem 1/2/1/4, wypelniam go jak poprzednio,\n"<<
		"wypisuje wynik, a nastepnie wczytuje wynik i rozwiazanie z pliku i wypisuje wynik";
	CMscnProblem* cmscnproblem_2 = new CMscnProblem(1,2,1,4);
	cmscnproblem_2->randomValues();
	cout << "Pierwszy wynik! : \n";
	cmscnproblem_2->vPrintZ();

	
	LoadProblem* loadprob = new LoadProblem("Save_Szpak_Answer.txt");
	loadprob->bOpenFile();
	cmscnproblem_2 = loadprob->LoadFile();
	LoadSolution* loadsol = new LoadSolution("Save_Szpak_Solution");
	loadsol->openFile();
	cout << "Drugi wynik: "  << cmscnproblem_2->dGetQuality(loadsol->LoadSol()) << "!\n";
	cmscnproblem_2->vPrintZ();
	delete loadsol;
	delete cmscnproblem_2;


	cout << "\n\nTrzeci przyklad, tworze obiekt jak z przykladu i zapisuje wynik:\n\n";
	CMscnProblem* cms = new CMscnProblem(1,2,1,4);
	cms->test_szpak();
	cout << "KT: " << cms->dGetKT() << "!\n";
	cout << "KU: " << cms->dGetKU() << "!\n";
	cout << "P : " << cms->dGetP() << "!\n";
	cms->vPrintZ();

	SaveSolution* save_szpak = new SaveSolution("Save_Szpak_Solution.txt");
	save_szpak->OpenFile();
	save_szpak->Save(cms);
	delete save_szpak;

	delete cms;
	cout << "\n\nLOSOWE PRZESZUKIWANIE!\n\n\n";
	
	CMscnProblem* cms_2 = new CMscnProblem(1, 2, 1, 4);
	LoadProblem* load_problem = new LoadProblem("Save_Szpak_Answer.txt");
	load_problem->bOpenFile();
	cms_2 = load_problem->LoadFile();
	LoadSolution* loadsolution = new LoadSolution("Save_Szpak_Solution");
	loadsolution->openFile();
	cms_2->load_solution(loadsolution->LoadSol());
	cout << "Problem do optymalizacji: ";
	cms_2->vPrintAll();
	CRandomSearch* crandom = new CRandomSearch(cms_2);
	cout << "Wylosowane rozwiazanie: ";
	crandom->Optimalize(10, cms_2);
	cout << "Po optymalizacji: ";
	cms_2->vPrintAll();
	cout << "Ostateczny(najlepszy) wynik: ";
	cms_2->vPrintZ();
	
	cout << "KT: " << cms_2->dGetKT() << "!\n";
	cout << "KU: " << cms_2->dGetKU() << "!\n";
	cout << "P : " << cms_2->dGetP() << "!\n";

	delete cms_2;
	delete load_problem;
	delete loadsolution;
	delete crandom;
*/

//	vTestEvol();
	vXD();
	return 0;
}


void vTestRandom()
{
	CRandom* crand = new CRandom();
	cout << "Calkowita: " << crand->Random(1, 50) << "\n";
	cout << "Rzeczywista: " << crand->Random(1.5, 12.5) << "\n";
	delete crand;

}



void vTestEvol()
{

	CMscnProblem* cms = new CMscnProblem(1, 2, 1, 4);


	LoadProblem* load_problem = new LoadProblem("Save_Szpak_Answer.txt");
	load_problem->bOpenFile();
	cms = load_problem->LoadFile();
	//cms->vPrintAll();

	cout << "Ewolucja roznicowa: \n";
	CDiffEvol* cdiff = new CDiffEvol(cms);
	cms = cdiff->getTheBestCMscn();
	cms->vPrintAll();
	cms->vPrintZ();
	cout << "\nModyfikacja: \n";
	cms = cdiff->getTheBestCMscn(10);

}

void vXD()
{
	CMscnProblem* cms = new CMscnProblem(1, 2, 1, 4);


	LoadProblem* load_problem = new LoadProblem("Save_Szpak_Answer.txt");
	load_problem->bOpenFile();
	cms = load_problem->LoadFile();

	LoadSolution* loadsol = new LoadSolution("Save_Szpak_Solution");
	loadsol->openFile();
	cout << ": " << cms->dGetQuality(loadsol->LoadSol()) << "!\n";
	cms->vGenerateInstance(5);
	cms->dGetQuality(loadsol->LoadSol());

}