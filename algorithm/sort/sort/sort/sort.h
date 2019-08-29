#pragma once

#include <vector>
#include <boost/timer.hpp>
//#include <iostream>

//template<typename T>
class sort
{
	std::vector<unsigned int> cVec;
	std::vector<unsigned int> sortVec;
	std::vector<unsigned int> stdVec;
	boost::timer e;
	int nSize;
	void quickSort(int,int);
	void buildHeapify(int,int);
	void initHeapify();
	void mergeSort(int,int);
	void mergeArray(int,int,int);
	bool compare();

public:
	sort();
	~sort();

	void StdSort();

	void BubbleSort();
	void SelectSort();
	void InsertSort();
	void ShellSort();
	void QuickSort();
	void MergeSort();
	void HeapSort();
	void RadixSort();
		
	void print();
	void start(std::string);
	void end();
	void init(unsigned int sourArray[], int arraySize);
	void init(std::vector<unsigned int> sourArray);
	

};

