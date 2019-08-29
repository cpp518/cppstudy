#include "stdafx.h"
#include "readFile.h"
#include <random>

std::vector<unsigned int> readFile::vec;

readFile::readFile()
{
}


readFile::~readFile()
{
}

void readFile::read() {
	std::ifstream input;
	unsigned int num;
	vec.clear();
	input.open("numbers.txt", std::ios::in);
	while (!input.eof()) {
		input >> num;
		vec.push_back(num);
	}
	input.close();
}

void readFile::CreateNumbersFile(int num) {
	std::default_random_engine e;
	std::ofstream output;
	output.open("numbers.txt", std::ios::out);
	for (int i = 1; i < num; ++i) {
		output << e() << " ";
	}
	output << e();
	output.flush();
	output.close();
}

void readFile::CreateNewNumbersFile(bool flag,int number) {
	if (flag) {
		std::cout << "��ʼ����" << number << "�������" << std::endl;
		CreateNumbersFile(number);
		std::cout << "�ļ��������" << std::endl;
	}
	else {
		std::cout << "ʹ�þ��ļ�" << std::endl;
	}
}

std::vector<unsigned int> readFile::getVector(bool flag,int number = 100) {
	CreateNewNumbersFile(flag,number);
	read();
	return vec;
}

