#ifndef SaveProblem_H
#define SaveProblem_H

#include <fstream>
#include "CMscnProblem.h"


class SaveProblem
{
public:
	SaveProblem(string file_name);
	~SaveProblem() { if (file.is_open() == true) file.close(); }
	bool OpenFile();
	void Save(CMscnProblem* mscn);
private:
	string file_name;
	ofstream file;
};

#endif

