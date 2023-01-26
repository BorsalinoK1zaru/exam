#pragma once
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Reader
{
	vector<string> znachenia;
	string path;
	int counter = 0;
public:
	Reader(){}
	Reader(string path) {
		vector<string>znachenia = readFile(path);
		for (int i = 0; znachenia.size(); i++) {
			this->znachenia[i] = znachenia[i];
			counter++;
		}
	}
	vector<string> getZnachenia() {
		return znachenia;
	}
	int getCounter() {
		return counter;
	}
private:
		vector<string> readFile(string path) {
		ifstream in(path);
		string line;
		vector<string> znachenia;
		int counter = 0;
		if (in.is_open()) {
			while (getline(in, line)) {
				znachenia.push_back(line);
				counter++;
			}
		}
		in.close();
		return znachenia;
	}
};

