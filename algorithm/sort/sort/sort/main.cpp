// sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "sort.h"
#include "readFile.h"


int main()
{
	int num;
	sort arr;
	while (1) {
		std::cout << "请输入要生成的数字数量（-1退出，-2使用旧文件）：";
		std::cin >> num;
		bool use = true;
		if (num == 0) {
			num = 100;
		}
		else if (num == -2) {
			use = false;
		}
		else if (num <= -1) {
			break;
		}
		else {
			use = true;
		}
		arr.init(readFile::getVector(use, num));
		arr.BubbleSort();
		arr.SelectSort();
		arr.InsertSort();
		arr.ShellSort();
		arr.QuickSort();
		arr.HeapSort();
		arr.MergeSort();
		arr.RadixSort();
		std::cout << std::endl;
	}
    return 0;
}

