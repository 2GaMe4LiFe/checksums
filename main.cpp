#include <iostream>
#include <bitset>
#include <cstdint>
#include <vector>
#include "checksums.h"
#include "file_utility.h"

using namespace std;

int main() {

	string answer;
	string filename;
	bool on = true;
	vector<uint8_t> data;
	vector<uint8_t> data2;

	while (on == true) {

		cout << "Checksummen überprüfen (1)" << endl;
		cout << "Checksummen erstellen  (2)" << endl;
		cout << "Programm beenden       (q)" << endl;
		cout << ">>> ";
		getline(cin, answer);

		while (answer == "") {

			cout << "\r" << "                              <-- <Return> gedrückt!" << endl;
			cout << ">>> ";
			getline(cin, answer);
		}

		if (answer == "1") {

			cout << "\nDateiname: ";
			getline(cin, filename);

			auto cont = read_textfile(filename);
			for (auto content : cont) {
				for (auto content2 : content) {
					data.push_back(content2);
				}
			}

			uint16_t sum = fletcher16(data);
			string str = to_string(sum);
			vector<string> erg = {str};
			data = {};

			auto cont2 = read_textfile(filename + ".chk");

			if (erg == cont2) cout << "Checksummen sind gleich!\n" << endl;
		}

		else if (answer == "2") {

			cout << "\nDateiname: ";
			getline(cin, filename);

			auto cont = read_textfile(filename);
			for (auto content : cont) {
				for (auto content2 : content) {
					data.push_back(content2);
				}
			}

			uint16_t sum = fletcher16(data);
			string str = to_string(sum);
			data = {};
			vector<string> erg = {str};
			write_textfile(filename, erg);
			
			cout << "Checksummen in " << filename << ".chk erstellt: " << str << "\n" <<  endl;
		}

		else if (answer == "q") {

			on = false;
		}

		else {

			cout << "Ungültige Eingabe!\n" << endl;
			cout << "" << endl;
		}
	}

	return 0;
}
