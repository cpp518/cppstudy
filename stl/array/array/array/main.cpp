// array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "array.h"

int main()
{
	myArray myArr(1,100,10);
	
	myArr.OperatorEqual();
	myArr.At(5);
	myArr.OperatorBracket(5);
	myArr.Front();
	myArr.Back();
	myArr.Data();

	myArr.Begin();
	myArr.End();
	myArr.Rbegin();
	myArr.Rend();

	myArr.Size();
	myArr.Max_Size();

	myArr.Fill(8);
	myArr.Swap();

    return 0;
}

