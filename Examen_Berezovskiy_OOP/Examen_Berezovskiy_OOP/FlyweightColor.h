#pragma once
#include"Reader.h"
class FlyweightColor
{
	friend Reader;
	string color;
	Reader f1;
	string path;
};

