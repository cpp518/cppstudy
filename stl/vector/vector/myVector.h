#pragma once
#include <vector>
class myVector
{
	std::vector<int> vec;
	std::vector<int> tempVec;
	int vecSize;
public:
	myVector(int,int,int);
	~myVector();
	friend void Print(std::vector<int>);
	std::vector<int> GetVec();
	
	void OperatorEqual();
	void Assign();

	//Ԫ�ط���
	void At(int);
	void OperatorBracket(int);
	void Front();
	void Back();
	void Data();

	//������
	void Begin();
	void Rbegin();
	void End();
	void Rend();

	//����
	void Empty();
	void Size();
	void Max_Size();
	void Reserve(int);
	void Capacity();
	void Shrink_to_fit();

	//�޸���
	void Clear();
	void Insert();
	void Emplace();
	void Erase();
	void Push_back(int);
	void Emplace_back();
	void Pop_back();
	void Resize(int);
	void Swap();
};

