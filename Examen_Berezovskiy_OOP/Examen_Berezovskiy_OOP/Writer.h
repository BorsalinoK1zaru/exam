#pragma once
#include "Npc.h"
#include "fstream"
class Writer
{
	string path;
public:
	Writer(string path) {
		this->path = path;
	}
	void writeFile() {
		setlocale(LC_ALL, "Russian");
		//string str1 = "���,������,������,����,������,�����,��������,���������,��������,��������,URL";
		string str2;
		Npc npc();
	}
};

