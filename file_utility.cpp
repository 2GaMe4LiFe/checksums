#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


vector<string> read_textfile(string filename) {

	string line;
	vector<string> output;

	ifstream infile{filename};

	while(getline(infile, line)) output.push_back(line);
	
	infile.close();

	return output;
}


void write_textfile(string filename, vector<string> data) {

	ofstream infile;

	infile.open(filename + ".chk");

	if(infile.fail()) perror(filename.c_str());

	for (auto content : data) {
		infile << content << endl;
	}

	infile.close();
}
