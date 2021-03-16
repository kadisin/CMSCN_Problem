#include "CMscnProblem.h"


int CMscnProblem::ErrorCode = ErrAllGood;

CMscnProblem::CMscnProblem()
{

	// Inicjalizacja ilosci
	amount_of_provider = 0;
	amount_of_fabrics = 0;
	amount_of_magazines = 0;
	amount_of_shops = 0;


	// Tablice dwuwymiarowe kosztow
	cd = new double*[amount_of_provider];
	for (int ii = 0; ii < amount_of_provider; ii++)
		cd[ii] = new double[amount_of_fabrics];

	cf = new double* [amount_of_fabrics];
	for (int ii = 0; ii < amount_of_fabrics; ii++)
		cf[ii] = new double[amount_of_magazines];

	cm = new double* [amount_of_magazines];
	for (int ii = 0; ii < amount_of_magazines; ii++)
		cm[ii] = new double[amount_of_shops];

	// Tablice dwuwymiarowe realnych ilosci
	xd = new double* [amount_of_provider];
	for (int ii = 0; ii < amount_of_provider; ii++)
		xd[ii] = new double[amount_of_fabrics];

	xf = new double* [amount_of_fabrics];
	for (int ii = 0; ii < amount_of_fabrics; ii++)
		xf[ii] = new double[amount_of_magazines];

	xm = new double* [amount_of_magazines];
	for (int ii = 0; ii < amount_of_magazines; ii++)
		xm[ii] = new double[amount_of_shops];

	// Jednorazowe koszty
	ud = new double[amount_of_provider];
	uf = new double[amount_of_fabrics];
	um = new double[amount_of_magazines];

	//Moc produkcyjna
	sd = new double[amount_of_provider];
	sf = new double[amount_of_fabrics];
	sm = new double[amount_of_magazines];
	ss = new double[amount_of_shops];

	p = new double[amount_of_shops];

}

CMscnProblem::CMscnProblem(int am_of_provider, int am_of_fabrics, int am_of_magazines, int am_of_shops)
{
	if (am_of_provider > 0 && am_of_fabrics > 0 && am_of_magazines > 0 && am_of_shops > 0)
	{
		// Inicjalizacja ilosci
		amount_of_provider = am_of_provider;
		amount_of_fabrics = am_of_fabrics;
		amount_of_magazines = am_of_magazines;
		amount_of_shops = am_of_shops;
		
		
		// Tablice dwuwymiarowe kosztow
		cd = new double*[amount_of_provider];
		for (int ii = 0; ii < amount_of_provider; ii++)
			cd[ii] = new double[amount_of_fabrics];

		cf = new double*[amount_of_fabrics];
		for (int ii = 0; ii < amount_of_fabrics; ii++)
			cf[ii] = new double[amount_of_magazines];

		cm = new double* [amount_of_magazines];
		for (int ii = 0; ii < amount_of_magazines; ii++)
			cm[ii] = new double[amount_of_shops];

		// Tablice dwuwymiarowe realnych ilosci
		xd = new double* [amount_of_provider];
		for (int ii = 0; ii < amount_of_provider; ii++)
			xd[ii] = new double[amount_of_fabrics];

		xf = new double* [amount_of_fabrics];
		for (int ii = 0; ii < amount_of_fabrics; ii++)
			xf[ii] = new double[amount_of_magazines];

		xm = new double* [amount_of_magazines];
		for (int ii = 0; ii < amount_of_magazines; ii++)
			xm[ii] = new double[amount_of_shops];
		
		// Jednorazowe koszty
		ud = new double[amount_of_provider];
		uf = new double[amount_of_fabrics];
		um = new double[amount_of_magazines];

		//Moc produkcyjna
		sd = new double[amount_of_provider];
		sf = new double[amount_of_fabrics];
		sm = new double[amount_of_magazines];
		ss = new double[amount_of_shops];

		p = new double[amount_of_shops];

	}
	else
	{
		ErrorCode = ErrorConstructor;
		CMscnProblem();
	}
}
CMscnProblem::~CMscnProblem()
{
	for (int ii = 0; ii < amount_of_provider; ii++)
		delete[] cd[ii];
	delete cd;

	for (int ii = 0; ii < amount_of_fabrics; ii++)
		delete[] cf[ii];
	delete cf;

	for (int ii = 0; ii < amount_of_magazines; ii++)
		delete[] cm[ii];
	delete cm;

	//
	//
	//

	for (int ii = 0; ii < amount_of_provider; ii++)
		delete[] xd[ii];
	delete xd;

	for (int ii = 0; ii < amount_of_fabrics; ii++)
		delete[] xf[ii];
	delete xf;

	for (int ii = 0; ii < amount_of_magazines; ii++)
		delete[] xm[ii];
	delete xm;

	//
	//
	//

	delete[] ud;
	delete[] uf;
	delete[] um;

	//
	//
	//
	delete[] sd;
	delete[] sf;
	delete[] sm;
	delete[] ss;

	delete[] p;
	//	cout << "All good";

}

//
// 2
// 
void CMscnProblem::vSetAmountOfProvider(int new_amount_of_provider)
{
	if (new_amount_of_provider <= 0)
	{
		ErrorCode = ErrWrongNumberOfAmountsProvider;
		return;
	}
	else
	{
		for (int ii = 0; ii < amount_of_provider; ii++)
			delete[] cd[ii];
		delete cd;
		
		double** new_cd = new double*[new_amount_of_provider];
		for (int ii = 0; ii < new_amount_of_provider; ii++)
			new_cd[ii] = new double[amount_of_fabrics];
		
		
		delete sd;
		double* new_sd = new double[new_amount_of_provider];

		cd = new_cd;
		sd = new_sd;
		amount_of_provider = new_amount_of_provider;
		ErrorCode = ErrAllGood;
	}
}

void CMscnProblem::vSetAmountOfFabrics(int new_amount_of_fabrics)
{
	if (new_amount_of_fabrics <= 0)
	{
		ErrorCode = ErrWrongNumberOfAmountsFabrics;
		return;
	}
	else
	{
		for (int ii = 0; ii < amount_of_fabrics; ii++)
			delete[] cf[ii];
		delete cf;

		double** new_cf = new double* [new_amount_of_fabrics];
		for (int ii = 0; ii < new_amount_of_fabrics; ii++)
			new_cf[ii] = new double[amount_of_magazines];


		delete sf;
		double* new_sf = new double[new_amount_of_fabrics];

		cf = new_cf;
		sf = new_sf;
		amount_of_fabrics = new_amount_of_fabrics;
		ErrorCode = ErrAllGood;
	}

}

void CMscnProblem::vSetAmountOfMagazines(int new_amount_of_magazines)
{
	if (new_amount_of_magazines <= 0)
	{
		ErrorCode = ErrWrongNumberOfAmountsMagazines;
		return;
	}
	else
	{
		for (int ii = 0; ii < amount_of_magazines ; ii++)
			delete[] cm[ii];
		delete cm;

		double** new_cm = new double* [new_amount_of_magazines];
		for (int ii = 0; ii < new_amount_of_magazines; ii++)
			new_cm[ii] = new double[amount_of_shops];


		delete sm;
		double* new_sm = new double[new_amount_of_magazines];

		cm = new_cm;
		sm = new_sm;
		amount_of_magazines = new_amount_of_magazines;
		ErrorCode = ErrAllGood;
	}

}

void CMscnProblem::vSetAmountOfShops(int new_amount_of_shops)
{
	if (new_amount_of_shops <= 0)
	{
		ErrorCode = ErrWrongNumberOfAmountsShops;
		return;
	}
	else
	{
		delete ss;
		double* new_ss = new double[new_amount_of_shops];

		ss = new_ss;
		amount_of_shops = new_amount_of_shops;
		ErrorCode = ErrAllGood;
	}
}
//
// 2
// 


//
// 3
//

void CMscnProblem::vSetValueAtCD(int numberOfProvider, int numberOfFabric, double value)
{
	if (numberOfProvider < 0 || numberOfProvider >= amount_of_provider)
	{
		ErrorCode = ErrWrongNumberProvider;
		return;
	}
	else if (numberOfFabric < 0 || numberOfFabric >= amount_of_fabrics)
	{
		ErrorCode = ErrWrongNumberFabrics;
		return;
	}
	else if (value < 0 )
	{
		ErrorCode = ErrWrongNumber;
		return;
	}
	else
	{
		cd[numberOfProvider][numberOfFabric] = value;
		ErrorCode = ErrAllGood;
	}

}


void CMscnProblem::vSetValueAtCF(int numberOfFabric, int numberOfMagazine, double value)
{
	if (numberOfFabric < 0 || numberOfFabric >= amount_of_fabrics)
	{
		ErrorCode = ErrWrongNumberFabrics;
		return;
	}
	else if (numberOfMagazine < 0 || numberOfMagazine >= amount_of_magazines)
	{
		ErrorCode = ErrWrongNumberMagazines;
		return;
	}
	else if (value < 0)
	{
		ErrorCode = ErrWrongNumber;
		return;
	}
	else
	{
		cf[numberOfFabric][numberOfMagazine] = value;
		ErrorCode = ErrAllGood;
	}
}

void CMscnProblem::vSetValueAtCM(int numberOfMagazine, int numberOfShop, double value)
{
	if (numberOfMagazine < 0 || numberOfMagazine >= amount_of_magazines)
	{
		ErrorCode = ErrWrongNumberMagazines;
		return;
	}
	else if (numberOfShop < 0 || numberOfShop >= amount_of_shops)
	{
		ErrorCode = ErrWrongNumberShops;
		return;
	}
	else if (value < 0)
	{
		ErrorCode = ErrWrongNumber;
		return;
	}
	else
	{
		cm[numberOfMagazine][numberOfShop] = value;
		ErrorCode = ErrAllGood;
	}
}
void CMscnProblem::vSetValueAtSD(int numberOfProvider, double value)
{
	if (numberOfProvider < 0 || numberOfProvider >= amount_of_provider)
	{
		ErrorCode = ErrWrongNumberProvider;
		return;
	}
	else if (value < 0)
	{
		ErrorCode = ErrWrongNumber;
		return;
	}
	else
	{
		sd[numberOfProvider] = value;
		ErrorCode = ErrAllGood;
	}
}

void CMscnProblem::vSetValueAtSF(int numberOfFabric, double value)
{
	if (numberOfFabric < 0 || numberOfFabric >= amount_of_fabrics)
	{
		ErrorCode = ErrWrongNumberFabrics;
		return;
	}
	else if (value < 0)
	{
		ErrorCode = ErrWrongNumber;
		return;
	}
	else
	{
		sf[numberOfFabric] = value;
		ErrorCode = ErrAllGood;
	}

}

void CMscnProblem::vSetValueAtSM(int numberOfMagazine, double value)
{
	if (numberOfMagazine < 0 || numberOfMagazine >= amount_of_magazines)
	{
		ErrorCode = ErrWrongNumberMagazines;
		return;
	}
	else if (value < 0)
	{
		ErrorCode = ErrWrongNumber;
		return;
	}
	else
	{
		sm[numberOfMagazine] = value;
		ErrorCode = ErrAllGood;
	}

}

void CMscnProblem::vSetValueAtSS(int numberOfShop, double value)
{
	if (numberOfShop < 0 || numberOfShop >= amount_of_shops)
	{
		ErrorCode = ErrWrongNumberShops;
		return;
	}
	else if (value < 0)
	{
		ErrorCode = ErrWrongNumber;
		return;
	}
	else
	{
		ss[numberOfShop] = value;
		ErrorCode = ErrAllGood;
	}

}
//
// 3
//


void CMscnProblem::vSetValueAtUD(int numberOfProvider, double value)
{
	if (numberOfProvider < 0 || numberOfProvider >= amount_of_provider)
	{
		ErrorCode = ErrWrongNumberProvider;
		return;
	}
	else if (value < 0)
	{
		ErrorCode = ErrWrongNumber;
		return;
	}
	else
	{
		ud[numberOfProvider] = value;
		ErrorCode = ErrAllGood;
	}
}

void CMscnProblem::vSetValueAtUF(int numberOfFabric, double value)
{
	if (numberOfFabric < 0 || numberOfFabric >= amount_of_fabrics)
	{
		ErrorCode = ErrWrongNumberFabrics;
		return;
	}
	else if (value < 0)
	{
		ErrorCode = ErrWrongNumber;
		return;
	}
	else
	{
		uf[numberOfFabric] = value;
		ErrorCode = ErrAllGood;
	}
}

void CMscnProblem::vSetValueAtUM(int numberOfMagazine, double value)
{
	if (numberOfMagazine < 0 || numberOfMagazine >= amount_of_magazines)
	{
		ErrorCode = ErrWrongNumberMagazines;
		return;
	}
	else if (value < 0)
	{
		ErrorCode = ErrWrongNumber;
		return;
	}
	else
	{
		um[numberOfMagazine] = value;
		ErrorCode = ErrAllGood;
	}

}

void CMscnProblem::vSetValueAtP(int numberOfShop, double value)
{
	if (numberOfShop < 0 || numberOfShop >= amount_of_shops)
	{
		ErrorCode = ErrWrongNumberShops;
		return;
	}
	else if (value < 0)
	{
		ErrorCode = ErrWrongNumber;
		return;
	}
	else
	{
		p[numberOfShop] = value;
		ErrorCode = ErrAllGood;
	}
}

void CMscnProblem::randomValues()
{
	for (int ii = 0; ii < amount_of_provider; ii++)
		for (int kk = 0; kk < amount_of_fabrics; kk++)
		{
			cd[ii][kk] = 10;
			xd[ii][kk] = 20;
		}
	for (int ii = 0; ii < amount_of_fabrics; ii++)
		for (int kk = 0; kk < amount_of_magazines; kk++)
		{
			cf[ii][kk] = 10;
			xf[ii][kk] = 20;
		}
	for (int ii = 0; ii < amount_of_magazines; ii++)
		for (int kk = 0; kk < amount_of_shops; kk++)
		{
			cm[ii][kk] = 10;
			xm[ii][kk] = 20;
		}

	for (int ii = 0; ii < amount_of_provider; ii++)
	{
		ud[ii] = 5;
		sd[ii] = 1000;
	}
	for (int ii = 0; ii < amount_of_fabrics; ii++)
	{
		uf[ii] = 5;
		sf[ii] = 1000;
	}
	for (int ii = 0; ii < amount_of_magazines; ii++)
	{
		um[ii] = 5;
		sm[ii] = 1000;
	}
	for (int ii = 0; ii < amount_of_shops; ii++)
	{
		ss[ii] = 1000;
		p[ii] = 30;
	}

	if (this->chceck_the_result() == true)
	{
		ErrorCode = ErrAllGood;
	}
	else ErrorCode = ErrorWrongResult;

}

void CMscnProblem::test_szpak()
{
	this->vSetAmountOfProvider(1);
	this->vSetAmountOfFabrics(2);
	this->vSetAmountOfMagazines(1);
	this->vSetAmountOfShops(4);

	this->vSetValueAtSD(0, 190);
	
	this->vSetValueAtSF(0, 50.3);
	this->vSetValueAtSF(1, 105.8);

	this->vSetValueAtSM(0, 130.6);

	this->vSetValueAtSS(0, 5.5);
	this->vSetValueAtSS(1, 62);
	this->vSetValueAtSS(2, 11);
	this->vSetValueAtSS(3, 23.8);

	this->vSetValueAtCD(0,0,3);
	this->vSetValueAtCD(0,1,5);

	this->vSetValueAtCF(0, 0, 7);
	this->vSetValueAtCF(1, 0, 4);

	this->vSetValueAtCM(0, 0, 1);
	this->vSetValueAtCM(0, 1, 1.2);
	this->vSetValueAtCM(0, 2, 0.8);
	this->vSetValueAtCM(0, 3, 0.5);

	ud[0] = 10;
	uf[0] = 5;
	uf[1] = 8;
	um[0] = 2;

	p[0] = 70;
	p[1] = 65;
	p[2] = 20;
	p[3] = 95;

	xd[0][0] = 36;
	xd[0][1] = 82;

	xf[0][0] = 32;
	xf[1][0] = 71;

	xm[0][0] = 4.2;
	xm[0][1] = 54.7;
	xm[0][2] = 8.0;
	xm[0][3] = 15.5;

}


void CMscnProblem::vPrintZ()
{
	if (ErrorCode == 0)
		cout << "Zysk: " << this->dGetZ() << "!\n";
	else cout << "Nieprawidlowe rozwiazanie!\n";
}

void CMscnProblem::vPrintAll()
{
	cout << "\n";
	cout << "D " << amount_of_provider << "\n";
	cout << "F " << amount_of_fabrics << "\n";
	cout << "M " << amount_of_magazines << "\n";
	cout << "S " << amount_of_shops << "\n";

	cout << "sd:\n";
	for (int d = 0; d < amount_of_provider; d++)
		cout << sd[d] << " ";
	cout << "\nsf:\n";
	for (int f = 0; f < amount_of_fabrics; f++)
		cout << sf[f] << " ";
	cout << "\nsm:\n";
	for (int m = 0; m < amount_of_magazines; m++)
		cout << sm[m] << " ";
	cout << "\nss:\n";
	for (int s = 0; s < amount_of_shops; s++)
		cout << ss[s] << " ";
	cout << "\ncd:\n";
	for (int d = 0; d < amount_of_provider; d++)
	{
		for (int f = 0; f < amount_of_fabrics; f++)
			cout << cd[d][f] << " ";
		cout << "\n";
	}
	cout << "\ncf:\n";
	for (int f = 0; f < amount_of_fabrics; f++)
	{
		for (int m = 0; m < amount_of_magazines; m++)
			cout << cf[f][m] << " ";
		cout << "\n";
	}
	cout << "\ncm:\n";
	for (int m = 0; m < amount_of_magazines; m++)
	{
		for (int s = 0; s < amount_of_shops; s++)
			cout << cm[m][s] << " ";
		cout << "\n";
	}
	cout << "\nud:\n";
	for (int d = 0; d < amount_of_provider; d++)
		cout << ud[d] << " ";
	cout << "\nuf:\n";
	for (int f = 0; f < amount_of_fabrics; f++)
		cout << uf[f] << " ";
	cout << "\num:\n";
	for (int m = 0; m < amount_of_magazines; m++)
		cout << um[m] << " ";
	cout << "\np:\n";
	for (int s = 0; s < amount_of_shops; s++)
		cout << p[s] << " ";
	cout << "\nxd:\n";
	for (int d = 0; d < amount_of_provider; d++)
		for(int f = 0; f < amount_of_fabrics ; f++)
		cout << xd[d][f] << " ";
	cout << "\nxf:\n";
	for (int f = 0; f < amount_of_fabrics; f++)
		for(int m = 0 ; m < amount_of_magazines ; m++)
		cout << xf[f][m] << " ";
	cout << "\nxm:\n";
	for (int m = 0; m < amount_of_magazines; m++)
		for(int s = 0 ; s < amount_of_shops ;s++)
		cout << xm[m][s] << " ";
	cout << "\n\n";
}

void CMscnProblem::load_solution(double* pdSolution)
{
	int index = 0;
	for (int d = 0; d < amount_of_provider; d++)
		for (int f = 0; f < amount_of_fabrics; f++)
			xd[d][f] = pdSolution[index++];
	for (int f = 0; f < amount_of_fabrics; f++)
		for (int m = 0; m < amount_of_magazines; m++)
			xf[f][m] = pdSolution[index++];
	
	for (int m = 0; m < amount_of_magazines; m++)
		for (int s = 0; s < amount_of_shops; s++)
			xm[m][s] = pdSolution[index++];
}

bool CMscnProblem::chceck_the_result()
{
	// Jesli rozwiazanie jest nieprawidlowe, zwracam false

	if (xd == nullptr || xf == nullptr || xm == nullptr ||
		cd == nullptr || cf == nullptr || cm == nullptr ||
		ud == nullptr || uf == nullptr || um == nullptr)
		return false;
	else
	{
		// Moc produkcyjna dostawcy nie moze byc mniejsza od ilosci surowcow zamowionej
		for (int d = 0; d < amount_of_provider; d++)
		{
			int result = 0;
			for (int f = 0; f < amount_of_fabrics; f++)
				result += xd[d][f];
			if (sd[d] < result) return false;
		}
		// Moc produkcyjna fabryki nie moze byc mniejsza od ilosci produktow zamowionej
		for (int f = 0; f < amount_of_fabrics; f++)
		{
			int result = 0;
			for (int m = 0; m < amount_of_magazines; m++)
				result += xf[f][m];
			if (sf[f] < result) return false;
		}
		// Pojemnosc magazynu nie moze byc mniejsza od ilosci zamowionej w magazynie
		for (int m = 0; m < amount_of_magazines; m++)
		{
			int result = 0;
			for (int s = 0; s < amount_of_shops; s++)
				result += xm[m][s];
			if (sm[m] < result) return false;
		}
		// Zapotrzebowanie rynku nie moze byc mniejsze od ilosci produktow dostarczonej do sklepu	
		for (int s = 0; s < amount_of_shops; s++)
		{
			int result = 0;
			for (int m = 0; m < amount_of_magazines; m++)
				result += xm[m][s];
			if (ss[s] < result) return false;
		}

		return true;

	}


}

double CMscnProblem::dGetKT()
{
	double result = 0;
	for ( int d = 0 ; d < amount_of_provider ; d++)
		for (int f = 0; f < amount_of_fabrics; f++)
		{
			result += (cd[d][f] * xd[d][f]);
		}
	for ( int f = 0 ; f < amount_of_fabrics ; f++ )
		for (int m = 0; m < amount_of_magazines; m++)
		{
			result += (cf[f][m] * xf[f][m]);
		}
	for (int m = 0 ; m < amount_of_magazines ; m++ )
		for (int s = 0; s < amount_of_shops; s++)
		{
			result += (cm[m][s] * xm[m][s]);
		}

	return result;
}

double CMscnProblem::dGetKU()
{
	double result = 0;
	
	// Tablica pomocnicza, sluzaca do pilnowania, zeby jeden dostawca byl liczony tylko raz
	// np 1 dostawca 2 fabryki 
	// sam warunek xd[d][f] > 0 bo x[0][0] > 0 i x[0][1] > 0 wiec naliczy sie podwojnie oplata jednorazowa
	bool* was_provider = new bool[amount_of_provider];
	for (int d = 0; d < amount_of_provider; d++)
		was_provider[d] = false;

	for (int d = 0; d < amount_of_provider; d++)
		for (int f = 0; f < amount_of_fabrics; f++)
		{
			if (xd[d][f] > 0 && was_provider[d] == false)
			{
				was_provider[d] = true;
				result += ud[d];
			}
		}
	delete was_provider;

	bool* was_fabric = new bool[amount_of_fabrics];
	for (int f = 0; f < amount_of_fabrics; f++)
		was_fabric[f] = false;

	for (int f = 0; f < amount_of_fabrics; f++)
		for (int m = 0; m < amount_of_magazines; m++)
		{
			if (xf[f][m] > 0 && was_fabric[f] == false)
			{
				was_fabric[f] = true;
				result += uf[f];
			}
		}

	delete was_fabric;

	bool* was_magazine = new bool[amount_of_magazines];
	for (int m = 0; m < amount_of_magazines; m++)
		was_magazine[m] = false;

	for (int m = 0; m < amount_of_magazines; m++)
		for (int s = 0; s < amount_of_shops; s++)
		{
			if (xm[m][s] > 0 && was_magazine[m] == false) {
				result += um[m];
				was_magazine[m] = true;
			}
		}
	delete was_magazine;
	return result;
}

double CMscnProblem::dGetP()
{
	double result = 0;

	for (int m = 0; m < amount_of_magazines; m++)
		for (int s = 0; s < amount_of_shops; s++)
			result += p[s] * xm[m][s];


	return result;
}

double CMscnProblem::dGetZ()
{
	if (ErrorCode != 0) return -1;
	else
	{
		double result = 0;
		result = this->dGetP() - (this->dGetKT() + this->dGetKU());
		return result;
	}
	
}

double CMscnProblem::dGetQuality(double* pdSolution)
{
	
	if (pdSolution == nullptr)
	{
		ErrorCode = ErrorNullTable;
		return -1;
	}
	
	int length_of_solution = amount_of_provider * amount_of_fabrics + amount_of_fabrics * amount_of_magazines +
		amount_of_magazines * amount_of_shops;
	for (int ii = 0 ; ii < length_of_solution ; ii ++ )
		if (pdSolution[ii] < 0) {
			ErrorCode = ErrWrongNumber;
			return -1;
		}
	int actual_index_of_solution = 0;
	for (int d = 0; d < amount_of_provider; d++)
		for (int f = 0; f < amount_of_fabrics; f++)
			xd[d][f] = pdSolution[actual_index_of_solution++];
	
	for (int f = 0; f < amount_of_fabrics; f++)
		for (int m = 0; m < amount_of_magazines; m++)
			xf[f][m] = pdSolution[actual_index_of_solution++];

	for (int m = 0; m < amount_of_magazines; m++)
		for (int s = 0; s < amount_of_shops; s++)
			xm[m][s] = pdSolution[actual_index_of_solution++];
	if (this->chceck_the_result() == true)
		return this->dGetZ();
	else return -1;
}

double* CMscnProblem::xdmin()
{
	double* xdmin = new double[amount_of_provider];
	for (int d = 0; d < amount_of_provider; d++)
		xdmin[d] = 0;
	return xdmin;
}

double* CMscnProblem::xdmax()
{
	double* xdmax = new double[amount_of_provider];
	int result = 0;
	for (int d = 0; d < amount_of_provider; d++)
	{		
		for (int f = 0; f < amount_of_fabrics; f++)
		{
			result += xd[d][f];
		}
		xdmax[d] = result;
		result = 0;
	}
	return xdmax;
}

double* CMscnProblem::xfmin()
{
	double* xfmin = new double[amount_of_fabrics];
	for (int f = 0; f < amount_of_fabrics; f++)
		xfmin[f] = 0;
	return xfmin;
}

double* CMscnProblem::xfmax()
{
	double* xfmax = new double[amount_of_fabrics];
	int result = 0;
	for (int f = 0; f < amount_of_fabrics; f++)
	{
		for (int m = 0; m < amount_of_magazines; m++)
		{
			result += xf[f][m];
		}
		xfmax[f] = result;
		result = 0;
	}
	return xfmax;
}

double* CMscnProblem::xmmin()
{
	double* xmmin = new double[amount_of_magazines];
	for (int m = 0; m < amount_of_magazines; m++)
		xmmin[m] = 0;
	return xmmin;
}

double* CMscnProblem::xmmax()
{
	double* xmmax = new double[amount_of_magazines];
	int result = 0;
	for (int m = 0; m < amount_of_magazines; m++)
	{
		for (int s = 0; s < amount_of_shops; s++)
		{
			result += xm[m][s];
		}
		xmmax[m] = result;
		result = 0;
	}
	return xmmax;
}




bool CMscnProblem::bContraintsSatisfied(double* pdSolution)
{
	if (pdSolution == nullptr)
	{
		ErrorCode = ErrorNullTable;
		return false;
	}

	int length_of_solution = amount_of_provider * amount_of_fabrics + amount_of_fabrics * amount_of_magazines +
		amount_of_magazines * amount_of_shops;
	for (int ii = 0; ii < length_of_solution; ii++)
		if (pdSolution[ii] < 0) {
			ErrorCode = ErrWrongNumber;
			return false;
		}
	return true;
}

int CMscnProblem::getLengthSolution()
{
	int length_of_solution = amount_of_provider * amount_of_fabrics + amount_of_fabrics * amount_of_magazines +
		amount_of_magazines * amount_of_shops;
	return length_of_solution;
}

double* CMscnProblem::dGetSolution()
{
	int length_of_solution = amount_of_provider * amount_of_fabrics + amount_of_fabrics * amount_of_magazines +
		amount_of_magazines * amount_of_shops;
	double* solution = new double[length_of_solution];
	int index = 0;
	for (int d = 0; d < amount_of_provider; d++)
		for (int f = 0; f < amount_of_fabrics; f++)
			solution[index++] = xd[d][f];
	for (int f = 0; f < amount_of_fabrics; f++)
		for (int m = 0; m < amount_of_magazines; m++)
			solution[index++] = xf[f][m];
	for (int m = 0; m < amount_of_magazines; m++)
		for (int s = 0; s < amount_of_shops; s++)
			solution[index++] = xm[m][s];
	return solution;
}
// chyba nie
void CMscnProblem::vGenerateInstance(int iInstanceSpeed)
{
	srand(time(NULL));

	for (int d = 0; d < amount_of_provider; d++)
		for (int f = 0; f < amount_of_fabrics; f++)
			cd[d][f] = (rand() % MaxValueCD);

	for (int f = 0; f < amount_of_fabrics; f++)
		for (int m = 0; m < amount_of_fabrics; f++)
			cf[f][m] = (rand() % MaxValueCF);

	for (int m = 0; m < amount_of_magazines; m++)
		for (int s = 0; s < amount_of_shops; s++)
			cm[m][s] = (rand() % MaxValueCM);

	for (int d = 0; d < amount_of_provider; d++)
	{
		ud[d] = (rand() % MaxValueUD);
		sd[d] = (rand() % MaxValueSD);
	}
	for (int f = 0; f < amount_of_fabrics; f++)
	{
		uf[f] = (rand() % MaxValueUF);
		sf[f] = (rand() % MaxValueSF);
	}
	for (int m = 0; m < amount_of_magazines; m++)
	{
		um[m] = (rand() % MaxValueUM);
		sm[m] = (rand() % MaxValueSM);
	}
	for (int s = 0; s < amount_of_shops; s++)
	{
		ss[s] = (rand() % MaxValueSS);
	}
	


}



	
	



