#include "LoadSolution.h"

LoadSolution::LoadSolution(string name_file)
{
	this->name_file = name_file;

}

bool LoadSolution::openFile()
{
	file = ifstream(name_file, ios::in);
	return file.is_open();
}

double* LoadSolution::LoadSol()
{
	int amount_of_provider;
	int amount_of_fabrics;
	int amount_of_magazines;
	int amount_of_shops;

	string new_str;
	int act_int;
	double act_double;
	
	file >> new_str;
	file >> act_int;

	amount_of_provider = act_int;

	file >> new_str;
	file >> act_int;

	amount_of_fabrics = act_int;

	file >> new_str;
	file >> act_int;

	amount_of_magazines = act_int;

	file >> new_str;
	file >> act_int;

	amount_of_shops = act_int;

	int size_of_solution = amount_of_provider * amount_of_fabrics + amount_of_fabrics * amount_of_magazines +
		amount_of_magazines * amount_of_shops;

	double* pdSolution = new double[size_of_solution];

	file >> new_str;
	int act_index = 0;
	for (; act_index < amount_of_provider * amount_of_fabrics; ++act_index)
	{
		file >> act_double;
		pdSolution[act_index] = act_double;
	}
	file >> new_str;
	for (; act_index < (amount_of_provider * amount_of_fabrics) + (amount_of_fabrics * amount_of_magazines); ++act_index)
	{
		file >> act_double;
		pdSolution[act_index] = act_double;
	}
	file >> new_str;
	for (; act_index < size_of_solution; ++act_index)
	{
		file >> act_double;
		pdSolution[act_index] = act_double;
	}
	return pdSolution;
}


