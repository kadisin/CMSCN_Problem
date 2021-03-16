#include "SaveProblem.h"

SaveProblem::SaveProblem(string file_name)
{
	this->file_name = file_name;
}

bool SaveProblem::OpenFile()
{
	file.open(file_name, ios::out);
	return file.is_open();
}

void SaveProblem::Save(CMscnProblem* mscn)
{
	file << "D ";
	file << mscn->getAmountOfProvider();

	file << "\nF ";
	file << mscn->getAmountOfFabrics();

	file << "\nM ";
	file << mscn->getAmountOfMagazines();

	file << "\nS ";
	file << mscn->getAmountOfShops();

	file << "\nxd";
	for (int d = 0; d < mscn->getAmountOfProvider(); d++)
	{
		file << "\n";
		for (int f = 0; f < mscn->getAmountOfFabrics(); f++)
		{
			file << mscn->getXD(d, f);
			file << " ";
		}
	}

	file << "\nxf";
	for (int f = 0; f < mscn->getAmountOfFabrics(); f++)
	{
		file << "\n";
		for (int m = 0; m < mscn->getAmountOfMagazines(); m++)
		{
			file << mscn->getXF(f, m);
			file << " ";
		}
	}
	file << "\nxm";
	for (int m = 0; m < mscn->getAmountOfMagazines(); m++)
	{
		file << "\n";
		for (int s = 0; s < mscn->getAmountOfShops(); s++)
		{
			file << mscn->getXM(m, s);
			file << " ";
		}
	}

}

