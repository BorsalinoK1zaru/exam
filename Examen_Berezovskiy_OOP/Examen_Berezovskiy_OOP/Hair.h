#pragma once
#include "Reader.h"
#define random(a,b) a+rand()%(b-a+1)
class Hair
{
	friend Reader;
	bool sex;
	string pricheska;
	string URL;
public:
	Hair() {};
	Hair(bool sex) {
		if (sex == 1) {
			Reader f1("Examen_Berezovskiy_OOP/pricheskaW");
			vector<string> itog = splitString(f1, 1, f1.getCounter());
			pricheska= itog[0];
			URL = itog[1];
		}
		else {
			Reader f1("Examen_Berezovskiy_OOP/pricheskaM");
			vector<string> itog = splitString(f1, 1, f1.getCounter());
			pricheska = itog[0];
			URL = itog[1];
		}
		
	}
private:
	vector<string>splitString(Reader f1, int a, int b) {
		vector<string> dop = f1.getZnachenia();
		vector<string> itog;
		string str = dop[random(a, b)];
		string st1;
		for (int i = 0, k; i < str.size(); i++) {
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

