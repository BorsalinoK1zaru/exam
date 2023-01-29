#pragma once
#include "Reader.h"
#include "Npc.h"

class Tors
{
	string type;
	string URL;
public:
	Tors() {};
	Tors(bool sex) {
		if (sex == 1) {
			Reader f1("Examen_Berezovskiy_OOP/torsW");
			vector<string> itog = splitString(f1, 1);
			type = itog[0];
			URL = itog[1];
		}
		else {
			Reader f1("Examen_Berezovskiy_OOP/torsM");
			vector<string> itog = splitString(f1, 1);
			type = itog[0];
			URL = itog[1];
		}
	}
	string getType() {
		return type;
	}
	string getURL() {
		return URL;
	}
private:
	vector<string>splitString(Reader f1, int a, int b) {
		vector<string> dop = f1.getZnachenia();
		vector<string> itog;
		string str = dop[random(a, b)];
		string st1;
		for (int i = 0, k = 0; i < str.size(); i++) {
			if (str[i] != ',' && k == 0) {
				st1 += str[i];
			}
			else {
				itog.push_back(st1);
				k++;
				st1 = "";
			}
			if (k == 1) {
				st1 += str[i];
			}
		}
		itog.push_back(st1);
		return itog;
	}
	vector<string>splitString(Reader f1, int a) {
		vector<string> dop = f1.getZnachenia();
		vector<string> itog;
		string str = dop[a];
		string st1;
		for (int i = 0, k = 0; i < str.size(); i++) {
			if (str[i] != ',' && k == 0) {
				st1 += str[i];
			}
			else {
				itog.push_back(st1);
				k++;
				st1 = "";
			}
			if (k == 1) {
				st1 += str[i];
			}
		}
		itog.push_back(st1);
		return itog;
	}
};

