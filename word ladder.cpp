#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <sstream>


using namespace std;

vector<string> alphabet{ "a","b","c","d","e","f","g","h","i","j","k","l","m",
                         "n","o","p","q","r","s","t","u","v","w","x","y","z" };



int main() 
try {
	string;
	int num;
	bool quit = false;
	while (1) {
		cout << "Please input the number of letters of suffix:" << endl;
		cin >> num;

		ifstream infile("dictionary.txt");
		map<string, vector<string>> suffixlist;
		string line;
		string suffix;

		while (!infile.eof()) {
			getline(infile, line);
			int a = line.size();
			if (a - num > 0) {
				suffix = line.substr(line.size() - num);
				suffixlist[suffix].push_back(line);
			}
		}
		if (suffixlist.size() == 0) {
			cout << "This suffix doesn't exist!" << endl;
			continue;
		}

		map<string, int>top_suffixlist;
		vector<int> top_ten_suffix_pos;
		vector<int> numbers;

		map<string, vector<string>>::iterator it;
		it = suffixlist.begin();

		while (it != suffixlist.end()) {
			numbers.push_back(it->second.size());
			++it;
		}

		for (int j = 0; j < 10; ++j) {
			int max = 0;
			for (int i = 0; i < numbers.size(); ++i) {
				if (numbers[i] >= numbers[max]) {
					max = i;
				}
			}
			top_ten_suffix_pos.push_back(max);
			numbers[max] = 0;
		}

		for (int i = 0; i < 10; ++i) {
			it = suffixlist.begin();
			int pos = top_ten_suffix_pos[i];
			for (int j = 0; j < pos; j++) {
				it++;
			}
			top_suffixlist[it->first] = it->second.size();
			cout << "suffix: " << it->first << "  number: " << it->second.size() << endl;
		}
		cout << "Please enter a suffix: " << endl;
		string given_suffix;
		cin >> given_suffix;
		cout << suffixlist.size() << endl;
		it = suffixlist.begin();
		it = suffixlist.find(given_suffix);
		if (it == suffixlist.end()) {
			cout << "Wrong suffix!" << endl;
		}
		else {
			cout << "suffix: " << given_suffix;
			cout << "number: " << it->second.size() << endl;
			cout << "words: " << endl;
			for (int i = it->second.size()-1; i > 0; i--) {
				cout << it->second[i] << endl;
			}
		}
	}
	system("pause");
}
catch (exception&e) {
	cerr << e.what() << endl;
}