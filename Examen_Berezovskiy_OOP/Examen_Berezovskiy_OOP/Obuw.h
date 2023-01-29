#pragma once
#include "Reader.h"
#include "Clothes.h"
#define random(a,b) a+rand()%(b-a+1)
class Obuw
{
	string type;
	string URL;
	string color;
public:
	Obuw() {};
	Obuw(Clothes odejka) {
		Reader f1("Examen_Berezovskiy_OOP/obuv.csv");
		if (odejka.getVerh() != "platie_v_pol") {
			vector<string> itog = splitString(f1, 1, 3);
			type = itog[0];
			URL = itog[1];
			if (type == "krosovki") {
				Reader f2("Examen_Berezovskiy_OOP/clothesColor");
				vector<string> colors = splitString(f2, 1, 6);
				color = colors[0];
			}
			else {
				Reader f2("Examen_Berezovskiy_OOP/clothesColor");
				vector<string> colors = splitString(f2, 1, 4);
				color = colors[0];
			}
		}
		else {
			vector<string> itog = splitString(f1, 1, 2);
			type = itog[0];
			URL = itog[1];
			Reader f2("Examen_Berezovskiy_OOP/clothesColor");
			vector<string> colors = splitString(f2, 1, 4);
			color = colors[0];
		}
	
	};
private:
	vector<string>splitString(Reader f1, int a, int b) {
		vector<string> dop = f1.getZnachenia();
		vector<string> itog;
		string str = dop[random(a, b)];
		string st1;
		for (int i = 0, k=0; i < str.size(); i++) {
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

