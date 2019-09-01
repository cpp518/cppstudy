#pragma once
#include <array>

class myArray {

	std::array<int,20> arr;
	std::array<int,20> tempArr;

public:
	myArray(int,int,int);
	~myArray();


	//��ʽ��Ա����
	void OperatorEqual();

	//Ԫ�ط���
	void At(int);
	void OperatorBracket(int);
	void Front();
	void Back();
	void Data();

	//������
	void Begin();
	void End();
	void Rbegin();
	void Rend();

	//����
	void Empty();
	void Size();
	void Max_Size();

	//����
	void Fill(int);
	void Swap();

};