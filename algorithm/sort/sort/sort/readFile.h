#pragma once
#include "stdafx.h"
#include <boost/random.hpp>

class readFile
{
	static std::vector<unsigned int> vec;
	static void read();
	static void CreateNumbersFile(int num);
public:
	readFile();
	~readFile();
	static void CreateNewNumbersFile(bool,int);
	static std::vector<unsigned int> getVector(bool,int);
};