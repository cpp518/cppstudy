// vector.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "myVector.h"


int main()
{
	myVector myVec(1, 100, 20); //��������������vector
	std::cout << "����myVec��" << std::endl;
	Print(myVec.GetVec());
	
	myVec.OperatorEqual();
	myVec.Assign();
	
	myVec.At(5);
	myVec.OperatorBracket(0);
	myVec.Front();
	myVec.Back();
	myVec.Data();

	myVec.Begin();
	myVec.End();
	myVec.Rbegin();
	myVec.Rend();

	myVec.Empty();
	myVec.Size();
	myVec.Max_Size();
	myVec.Reserve(50);
	myVec.Capacity();
	myVec.Shrink_to_fit();

	myVec.Clear();
	myVec.Insert();
	myVec.Emplace();
	myVec.Erase();
	myVec.Push_back(10);
	//myVec.Emplace_back();
	myVec.Pop_back();
	myVec.Resize(10);
	myVec.Swap();

    return 0;
}

