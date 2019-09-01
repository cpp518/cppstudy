#include "stdafx.h"
#include "array.h"

void Print(std::array<int,20> arr) {
	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << " ";
	}
//	std::cout << std::endl;
}

myArray::myArray(int begin, int end, int num) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> uid(begin,end);
	for (int i = 0; i < num; ++i) {
		arr[i] = uid(gen);
	}
	std::cout << "����arr��\n";
	Print(arr);
	std::cout << "\n";
}

myArray::~myArray() {

}

void myArray::OperatorEqual() {
	std::cout << "\n����� operator= ��\n";
	std::cout << "ִ��ǰtempArr�ǣ�";
	Print(tempArr);
	tempArr = arr;
	std::cout << "\nִ�к�tempArr�ǣ�";
	Print(arr);
	std::cout << "\n";
}

void myArray::At(int num) {
	std::cout << "\n����� at ��\n";
	std::cout << "��ӡ��" << num << "��λ�õ�ֵ��" << arr.at(num) << "std::endl";
}

void myArray::OperatorBracket(int num) {
	std::cout << "\n����� operator[] ��\n";
	std::cout << "��ӡ��" << num << "��λ�õ�ֵ��" << arr[num] << "std::endl";

}

void myArray::Front() {
	std::cout << "\n����� front ��\n";
	std::cout << "��ӡ��һ��λ�õ�ֵ��" << arr.front() << std::endl;
}

void myArray::Back() {
	std::cout << "\n����� back ��\n";
	std::cout << "��ӡ���һ��λ�õ�ֵ��" << arr.back() << std::endl;

}

void myArray::Data() {
	std::cout << "\n����� data ��\n";
	std::cout << "��ӡ��һ��λ�õĵ�ַ��" << arr.data() << "����ֵ��" << *arr.data() << std::endl;

}


void myArray::Begin() {
	std::cout << "\n����� begin ��\n";
	auto ite = tempArr.begin();
	std::cout << "��ӡ�ڶ���Ԫ�أ�" << *++ite << std::endl;
	std::cout << "����� cbegin ��\n";
	auto cIte = tempArr.cbegin(); 
	std::cout << "��ӡ��һ��Ԫ�أ�" << *cIte << std::endl;
}

void myArray::End() {
	std::cout << "\n����� end ��\n";
	auto ite = tempArr.end();
	std::cout << "��ӡ�ڶ���Ԫ�أ�" << *--ite << std::endl;
	std::cout << "����� cbegin ��\n";
	for (auto cIte = tempArr.begin(); cIte != tempArr.cend(); ++cIte) {
		std::cout << *cIte << " ";
	}
	std::cout << std::endl;
}

void myArray::Rbegin() {
	std::cout << "\n����� rbegin ��\n";
	auto ite = tempArr.rbegin();
	std::cout << "��ӡ�����ڶ���Ԫ�أ�" << *++ite << std::endl;
	std::cout << "����� cbegin ��\n";
	auto cIte = tempArr.crbegin();
	std::cout << "��ӡ���һ��Ԫ�أ�" << *cIte << std::endl;
}

void myArray::Rend() {
	std::cout << "\n����� rend ��\n";
	auto ite = tempArr.rend();
	std::cout << "��ӡ��һ��Ԫ�أ�" << *--ite << std::endl;
	std::cout << "����� crend ��\n";
	for (auto cIte = tempArr.rbegin(); cIte != tempArr.crend(); ++cIte) {
		std::cout << *cIte << " ";
	}
	std::cout << std::endl;
}

void myArray::Empty() {
	std::cout << "\n����� empty ��\n";
	if (!arr.empty()) {
		std::cout << "arr��Ϊ��\n";
	}
	else {
		std::cout << "arrΪ��\n";
	}
}

void myArray::Size() {
	std::cout << "\n����� size ��\n";
	std::cout << "arr�ĵ�ǰԪ�ظ���Ϊ "<< arr.size() <<"\n";
}

void myArray::Max_Size() {
	std::cout << "\n����� size ��\n";
	std::cout << "arr������Ԫ�ظ������Ϊ " << arr.size() << "\n";

}

void myArray::Fill(int num) {
	std::cout << "\n����� fill ��\n";
	std::cout << "ִ��ǰ��";
	Print(tempArr);
	std::cout << "\nִ�к�";
	tempArr.fill(num);
	Print(tempArr);
	std::cout << std::endl;
}

void myArray::Swap() {
	std::cout << "\n����� swap ��\n";
	std::cout << "����ǰ��\n";
	std::cout << "arr��";
	Print(arr);
	std::cout << "\ntempArr:";
	Print(tempArr);
	std::cout << "\n������\n";
	tempArr.swap(arr);
	std::cout << "arr��";
	Print(arr);
	std::cout << "\ntempArr:";
	Print(tempArr);

}
