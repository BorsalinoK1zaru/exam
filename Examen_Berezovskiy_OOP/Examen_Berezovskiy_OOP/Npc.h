#pragma once
#include "Reader.h"
#include"Clothes.h"
#include"Hair.h"
#include"Obuw.h"
#include"Tors.h"
#define random(a,b) a+rand()%(b-a+1)

class Npc
{
	bool sex;
	bool makeUp;
	string kojaColor;
	Tors tors;
	Clothes *clothes;
	Hair *hair;
	Obuw *obuv;

public:
	Npc() {
		sex = random(0, 1);
		this->clothes = new Clothes(sex);
		this->hair = new Hair(sex);
		this->obuv = new Obuw(sex);
		this->tors = new Tors(sex);
		Reader f1("Examen_Berezovskiy_OOP/humanColor.csv");
		vector<string>koja = splitString(f1, 1, f1.getCounter());
		kojaColor = koja[0];
		if (sex == 1) {
			if (random(0, 1) == 1) {
				makeUp = 1;
			}
			else makeUp = 0;
		}
	}
	string getSex() {
		if (sex == 1) {
			return "Woman";
		}
		else return "man";
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

