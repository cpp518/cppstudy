// vector.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "myVector.h"


int main()
{
	myVector myVec(1, 100, 20); //生成随机数来填充vector
	std::cout << "我是myVec：" << std::endl;
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

