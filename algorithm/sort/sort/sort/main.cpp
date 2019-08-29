// sort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "sort.h"
#include "readFile.h"


int main()
{
	int num;
	sort arr;
	while (1) {
		std::cout << "������Ҫ���ɵ�����������-1�˳���-2ʹ�þ��ļ�����";
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

