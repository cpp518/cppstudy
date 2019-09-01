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

	//元素访问
	void At(int);
	void OperatorBracket(int);
	void Front();
	void Back();
	void Data();

	//迭代器
	void Begin();
	void Rbegin();
	void End();
	void Rend();

	//容量
	void Empty();
	void Size();
	void Max_Size();
	void Reserve(int);
	void Capacity();
	void Shrink_to_fit();

	//修改器
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

