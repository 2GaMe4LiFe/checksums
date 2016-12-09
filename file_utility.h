#ifndef FILEUTILITY_H
#define	FILEUTILITY_H

#include <iostream>
#include <vector>

using namespace std;

extern vector<string> read_textfile(string filename);
extern void write_textfile(string filename, vector<string> data);

#endif
