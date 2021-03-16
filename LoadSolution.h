#ifndef LoadSolution_H
#define LoadSolution_H


#include <string>
#include <fstream>
using namespace std;


class LoadSolution
{

public:
	LoadSolution(string name_file);
	~LoadSolution() { if (file.is_open() == true) file.close(); }
	bool openFile();
	double* LoadSol();

private:
	string name_file;
	basic_ifstream<char> file;

	


};


#endif
