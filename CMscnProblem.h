#ifndef CMscnProblem_H
#define CMscnProblem_H
#include "MscnDefines.h"
#include <iostream>
#include <time.h>
using namespace std;



class CMscnProblem
{
private:
	static int ErrorCode;
public:
	CMscnProblem();
	CMscnProblem(int am_of_provider, int am_of_fabrics, int am_of_magazines, int am_of_shops);
	~CMscnProblem();

	//gettery
	int getAmountOfProvider() { return amount_of_provider; }
	int getAmountOfFabrics() { return amount_of_fabrics; }
	int getAmountOfMagazines() { return amount_of_magazines; }
	int getAmountOfShops() { return amount_of_shops; }
	double getXD(int numberOfProvider, int numberOfFabric) { return xd[numberOfProvider][numberOfFabric]; }
	double getXF(int numberOfFabric, int numberOfMagazine) { return xf[numberOfFabric][numberOfMagazine]; }
	double getXM(int numberOfMagazine, int numberOfShop) {return xm[numberOfMagazine][numberOfShop];	}

// nie korzystac, nei zmienia wielkosci tablic
	//settery dostawcow etc.
	void vSetAmountOfProvider(int new_amount_of_provider);
	void vSetAmountOfFabrics(int new_amount_of_fabrics);
	void vSetAmountOfMagazines(int new_amount_of_magazines);
	void vSetAmountOfShops(int new_amount_of_shops);

	//ustawianie wartosci tablic
	void vSetValueAtCD(int numberOfProvider, int numberOfFabric, double value);
	void vSetValueAtCF(int numberOfFabric,int numberOfMagazine, double value);
	void vSetValueAtCM(int numberOfMagazine,int numberOfShop, double value);
	void vSetValueAtSD(int numberOfProvider, double value);
	void vSetValueAtSF(int numberOfFabric, double value);
	void vSetValueAtSM(int numberOfMagazine, double value);
	void vSetValueAtSS(int numberOfShop, double value);
	void vSetValueAtUD(int numberOfProvider, double value);
	void vSetValueAtUF(int numberOfFabric, double value);
	void vSetValueAtUM(int numberOfMagazine, double value);
	void vSetValueAtP(int numberOfShop, double value);


	// rozwiazanie dla danego ciagu liczb
	double dGetKT();
	double dGetKU();
	double dGetP();
	double dGetZ();
	double dGetQuality(double* pdSolution);
	
// chujowo
	// zakresy
	double* xdmin();
	double* xdmax();
	double* xfmin();
	double* xfmax();
	double* xmmin();
	double* xmmax();
	

	bool bContraintsSatisfied(double* pdSolution);

	int getLengthSolution();
	int getError() { return ErrorCode; }

	void randomValues();
	void test_szpak();
	void vPrintZ();
	void vPrintAll();
	void load_solution(double* pdSolution);
	
	
	double* dGetSolution();

	void vGenerateInstance(int iInstanceSpeed);

private:
	// Liczba dostawcow, fabryk, magazynow i sklepow
	int amount_of_provider;
	int amount_of_fabrics;
	int amount_of_magazines;
	int amount_of_shops;


	// Tablica dwuwymiarowa kosztow wytworzenia i przewiezienia surowca od dostawcy do fabryki
	// cd[amount_of_provider][amount_of_fabrics]
	double** cd;
	// Tablica dwuwymiarowa kosztow wyprodukowania i przewozu produktu do centrum dystrybucji 
	// cf[amount_of_fabrics][amount_of_magazines]
	double** cf;
	// Tablica dwuwymiarowa kosztów przechowywania w magazynie i transport do sklepu
	// cm[amount_of_magazines][amount_of_shops]
	double** cm;


	// Rzeczywista ilosc surowca wytwarzana u dostawcy i transportowana do fabryki
	// xd[amount_of_provider][amount_of_fabrics]
	double** xd;
	// Rzeczywista ilosc produktow wytwarzana w fabryce i transportowana do magazynu
	// xf[amount_of_fabrics][amount_of_magazines]
	double** xf;
	// Rzeczywista ilosc produktów przechowywana i transportowana do sklepu
	// xm[amount_of_magazines][amount_of_shops]
	double** xm;
	

	// Jednorazowy koszt korzystania z uslug dostawcy
	// ud[amount_of_provider]
	double* ud;
	// Jednorazowy koszt korzystania z uslug fabryki
	// uf[amount_of_fabrics]
	double* uf;
	// Jednorazowy koszt korzystania z uslug magazynu
	// um[amount_of_magazines]
	double* um;

	// Moc produkcyjna(max ilosc wytwarzana) surowca u dostawcy 
	// sd[amount_of_provider]
	double* sd;
	// Moc produkcyjna fabryki 
	// sf[amount_of_fabrics]
	double* sf;
	// Pojemnosc max magazynu
	// sm[amount_of_magazines]
	double* sm;
	// Max ilosc w sklepie
	// ss[amount_of_shops]
	double* ss;

	// Zysk ze sprzedazy produktu
	// p[amount_of_shops]
	double* p;

	bool chceck_the_result();

};


#endif

