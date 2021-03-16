#ifndef LoadProblem_H
#define LoadProblem_H

#include "CMscnProblem.h"
#include "fstream"
#include "string.h"
#include <iostream>

using namespace std;

class LoadProblem
{
public:
	LoadProblem(string name_file);
	~LoadProblem() { if (file.is_open() == true) file.close(); };
	bool bOpenFile();
	CMscnProblem* LoadFile();

	
private:
	string name_file;
	basic_ifstream<char> file;
	
};



#endif

