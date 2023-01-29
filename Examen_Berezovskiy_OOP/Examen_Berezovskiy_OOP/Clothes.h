#pragma once
#define random(a,b) a+rand()%(b-a+1)
#include "Reader.h"
class Clothes
{
	friend Reader;
	bool sex;
	string verh;
	string niz;
	string dop;
	string URLverh;
	string URLniz;
	string URLdop;
	string colorVerh;
	string colorNiz;
	string colorDop;
public:
	Clothes() {};
	Clothes(bool sex) {
		this->sex = sex;
		if (sex == 1) {
			Reader f1("Examen_Berezovskiy_OOP/odejdaW");
			Reader f2("Examen_Berezovskiy_OOP/clothesColor");
			vector<string>itog = splitString(f1, 3, 6);
			vector<string>color = splitString(f2, 1, 4);
			verh = itog[0];
			URLverh = itog[1];
			colorVerh = color[0];
			if (verh != "platie_v_pol") {
				itog = splitString(f1, 1, 2);
				color = splitString(f2, 3, 4);
				niz = itog[0];
				URLniz = itog[1];
				colorNiz = color[0];
				if (random(0, 1) == 1) {
					itog = splitString(f1, 6);
					color = splitString(f2, 1, 4);
					dop = itog[0];
					URLdop = itog[1];
					colorDop = color[0];
				}
			}
		}
		else {
			Reader f1("Examen_Berezovskiy_OOP/odejdaM");
			Reader f2("Examen_Berezovskiy_OOP/clothesColor");
			vector<string>itog = splitString(f1, 1,2);
			vector<string>color = splitString(f2, 3, 4);
			niz = itog[0];
			URLniz = itog[1];
			colorNiz = color[0];
			if (random(0, 1) == 1) {
				itog = splitString(f1, 3);
				color = splitString(f2, 1, 4);
				verh = itog[0];
				URLverh = itog[1];
				colorVerh = color[0];
				if (random(0, 1) == 1) {
					itog = splitString(f1, 4);
					color = splitString(f2, 1, 4);
					dop = itog[0];
					URLdop = itog[1];
					colorVerh = color[0];
				}
			}
		}
	}
	string getVerh() {
		if (verh.empty() == 0)return verh;
		else return "empty";
	}
	string getNiz() {
		if (niz.empty() == 0)return niz;
		else return "empty";
	}
	string getDop() {
		if (dop.empty() == 0)return dop;
		else return "empty";
	}
	string getColorverh() {
		if (colorVerh.empty() == 0)return colorVerh;
		else return "empty";
	}
	string getColorNiz() {
		if (colorNiz.empty() == 0)return colorNiz;
		else return "empty";
	}
	string getColorDop() {
		if (colorDop.empty() == 0)return colorDop;
		else return "empty";
	}



private:
	vector<string>splitString(Reader f1,int a,int b) {
		vector<string> dop=f1.getZnachenia();
		vector<string> itog;
		string str = dop[random(a,b)];
		string st1;
		for (int i = 0,k=0; i < str.size(); i++) {
			if (str[i] != ',' && k==0) {
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
public:
	string getVerh() {
		return verh;
	}

};

