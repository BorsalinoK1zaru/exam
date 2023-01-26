#pragma once
#define random(a,b) a+rand()%(b-a+1)
#include "Reader.h"
class Clothes
{
	friend Reader;
	Reader f1;
	bool sex;
	string path;
	string verh;
	string niz;
	string dop;
	string URL;
	string colorVerh;
	string colorNiz;
	string colorDop;

protected:
	Clothes(string path,bool sex) {
		Reader f1(path);
		this->sex = sex;
		if (sex == true) {
			vector<string>cloth = splitString(f1,4,7);
			verh= cloth[1];
			URL = cloth[2];
			if (verh != "platie_v_pol") {
				cloth = splitString(f1, 1, 2);
				niz = cloth[1];
				URL = cloth[2];
				if (random(0, 1) == true) {
					cloth = splitString(f1, 7,7);
					dop = cloth[1];
					URL = cloth[2];
				}
			}
		}
		else {
			vector<string>cloth = splitString(f1, 1, 2);
			niz = cloth[1];
			URL = cloth[2];
			bool ran=random(0,1);
			if (ran == 0) {
				cloth = splitString(f1, 5,6 );
				verh = cloth[1];
				URL = cloth[2];
			}
			else {
				cloth = splitString(f1, 7);
				verh = cloth[1];
				URL = cloth[2];
			}
		}
		
	}
private:
	vector<string>splitString(Reader f1,int a,int b) {
		Reader f1(path);
		vector<string> dop=f1.getZnachenia();
		vector<string> itog;
		string str = dop[random(a,b)];
		string st1;
		for (int i = 0,k; i < str.size(); i++) {
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
		Reader f1(path);
		vector<string> dop = f1.getZnachenia();
		vector<string> itog;
		string str = dop[a];
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

