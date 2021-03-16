#ifndef SaveSolution_H
#define SaveSolution_H

#include <fstream>
#include "CMscnProblem.h"


class SaveSolution
{
public:
	SaveSolution(string file_name);
	~SaveSolution() { if (file.is_open() == true) file.close(); }
	bool OpenFile();
	void Save(CMscnProblem *mscn);
private:
	string file_name;
	ofstream file;
};

#endif

