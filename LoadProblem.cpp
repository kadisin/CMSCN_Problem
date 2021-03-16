#include "LoadProblem.h"

LoadProblem::LoadProblem(string name_file)
{
	this->name_file = name_file;
}
bool LoadProblem::bOpenFile()
{
	file = ifstream(name_file, ios::in);
	return file.is_open();

}

CMscnProblem* LoadProblem::LoadFile()
{
	string act_string;
	int act_int;
	double act_double;

	int amountOfProvider;
	int amountOfFabrics;
	int amountOfMagazines;
	int amountOfShops;

	file >> act_string;
	file >> act_int;
	amountOfProvider = act_int;

	file >> act_string;
	file >> act_int;
	amountOfFabrics = act_int;

	file >> act_string;
	file >> act_int;
	amountOfMagazines = act_int;

	file >> act_string;
	file >> act_int;
	amountOfShops = act_int;

	CMscnProblem* mcsn = new CMscnProblem(amountOfProvider, amountOfFabrics, amountOfMagazines, amountOfShops);

	// SD SF SM SS

	file >> act_string;
	for (int d = 0; d < amountOfProvider; d++)
	{
		file >> act_double;
		mcsn->vSetValueAtSD(d, act_double);
	}
	file >> act_string;
	for (int f = 0; f < amountOfFabrics; f++)
	{
		file >> act_double;
		mcsn->vSetValueAtSF(f, act_double);
	}
	file >> act_string;
	for (int m = 0; m < amountOfMagazines; m++)
	{
		file >> act_double;
		mcsn->vSetValueAtSM(m, act_double);
	}
	file >> act_string;
	for (int s = 0; s < amountOfShops; s++)
	{
		file >> act_double;
		mcsn->vSetValueAtSS(s, act_double);

	}

	// CD CF CM 
	file >> act_string;
	for (int d = 0 ; d < amountOfProvider ; d++ )
		for (int f = 0; f < amountOfFabrics; f++)
		{
			file >> act_double;
			mcsn->vSetValueAtCD(d, f, act_double);
		}

	file >> act_string;
	for (int f = 0 ; f < amountOfFabrics ; f++)
		for (int m = 0; m < amountOfMagazines; m++)
		{
			file >> act_double;
			mcsn->vSetValueAtCF(f, m, act_double);
		}
	file >> act_string;
	for (int m = 0 ; m < amountOfMagazines ; m++)
		for (int s = 0; s < amountOfShops; s++)
		{
			file >> act_double;
			mcsn->vSetValueAtCM(m, s, act_double);
		}
	
	// ud uf um
	file >> act_string;
	for (int d = 0; d < amountOfProvider; d++)
	{
		file >> act_double;
		mcsn->vSetValueAtUD(d, act_double);
	}
	file >> act_string;
	for (int f = 0; f < amountOfFabrics; f++)
	{
		file >> act_double;
		mcsn->vSetValueAtUF(f, act_double);
	}
	file >> act_string;
	for (int m = 0; m < amountOfMagazines; m++)
	{
		file >> act_double;
		mcsn->vSetValueAtUM(m, act_double);
	}
	file >> act_string;
	for (int s = 0; s < amountOfShops; s++)
	{
		file >> act_double;
		mcsn->vSetValueAtP(s, act_double);
	}
	return mcsn;
}



