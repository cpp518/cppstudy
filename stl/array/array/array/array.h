#pragma once
#include <array>

class myArray {

	std::array<int,20> arr;
	std::array<int,20> tempArr;

public:
	myArray(int,int,int);
	~myArray();


	//隐式成员函数
	void OperatorEqual();

	//元素访问
	void At(int);
	void OperatorBracket(int);
	void Front();
	void Back();
	void Data();

	//迭代器
	void Begin();
	void End();
	void Rbegin();
	void Rend();

	//容量
	void Empty();
	void Size();
	void Max_Size();

	//操作
	void Fill(int);
	void Swap();

};