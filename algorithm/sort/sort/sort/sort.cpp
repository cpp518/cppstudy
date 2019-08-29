#include "stdafx.h"
#include "sort.h"


void sort::init(std::vector<unsigned int> sourArray) {
	sortVec.clear();
	sortVec = sourArray;
	nSize = sortVec.size();
	StdSort();
}

void sort::init(unsigned int sourArray[], int arraySize) {
	sortVec.clear();
	for (int i = 0; i < arraySize; ++i) {
		sortVec.push_back(sourArray[i]);
	}
	nSize = sortVec.size();
	StdSort();
}

sort::sort() {

}

sort::~sort()
{
}


void sort::print() {
	for (int i = 0; i < nSize; ++i) {
		std::cout << cVec[i] << " ";
	}
	std::cout << std::endl;
}

void sort::start(std::string name) {
	cVec = sortVec;
	std::cout << "\n" << name << "-排序开始" << std::endl;
	e.restart();
}

void sort::end() {
	std::cout << "排序结束，所花时间是：" << e.elapsed() << "秒" << std::endl;
	if (!compare()) {
		print();
	}	
}

/*
std自带的sort，用于检验排序结果是否正确
*/
void sort::StdSort() {
	stdVec = sortVec;
	std::sort(stdVec.begin(), stdVec.end());
}

/*
用于比较排序结果是否正确
*/
bool sort::compare() {
	for (int i = 0; i < nSize; ++i) {
		if (stdVec[i] != cVec[i]) {
			std::cout << "排序结果有误，请检查" << std::endl;
			return false;
		}
	}
	std::cout << "排序结果正确" << std::endl;
	return true;
}

/*
1
冒泡排序：
类型：稳定排序
时间复杂度：1+2+...+n = ((1+n)*n)/2 = n*n
*/
void sort::BubbleSort() {
	start("冒泡排序");
	//优化：
	//可以设置一个标记为，表示前一轮是否移动过数字，如果没有则表示后一位均比前一位大
	//即数组已经有序
	bool flag =  true;
	//每次j循环完成后，表示数组的第i位是数组里最大的
	for (int i = nSize - 1; i > 0 && flag; --i) {
		flag = false;
		
		//从数组第一个值开始
		for (int j = 0; j < i; ++j) {
			//和后一个值比较，如果大于就交换位置
			if (cVec[j] > cVec[j + 1]) {
				std::swap(cVec[j], cVec[j + 1]);
				flag = true;
			}
		}
	}
	end();
}

/*
2
选择排序：
类型：非稳定
时间复杂度：1+2+...+n = (n+1)*n/2 = n*2
*/
void sort::SelectSort() {
	start("选择排序");
	
	//每次j循环结束，表示找到一个最小的值了
	for (int i = 0; i < nSize; ++i) {
		//假设m为当前最小值的下标位置
		int m = i;
		//在m后面的下标中找到比下标m还要小的值
		for (int j = i+1; j < nSize; ++j) {
			if (cVec[m] > cVec[j]) {
				m = j;
			}
		}
		//发现这个m的值改变了，就交换他们的位置
		if (m != i) {
			std::swap(cVec[m], cVec[i]);
		}
	}
	end();
}

/*
3
插入排序：
类型：稳定
时间复杂度：1+2+...+n = (n+1)*n/2 = n*2
*/

void sort::InsertSort() {
	int i,j;
	start("插入排序");
	for ( i = 1; i < nSize; ++i) {
		for (j = 0; j < i; ++j) {
			if (cVec[i] < cVec[j]) {
				unsigned int temp = cVec[i];
				for (int k = i - 1; k >= j; --k) {
					cVec[k + 1] = cVec[k];
				}
				cVec[j] = temp;
				break;
			}
		}

	}
	end();
}

/*
4
希尔排序：
类型：非稳定 :4 2 1 3 3
时间复杂度：
*/
void sort::ShellSort() {
	
	start("希尔排序");
	//分组距离
	for (int i = nSize / 2; i > 0; i/=2) {
		//起始下标，即将[j]插入到前面去
		for (int j = 0; j < i ; ++j) {
			//k循环表示列举每个分组的值		
			for (int k = j+i; k < nSize; k += i) {
				//l循环表示在前面的值中找到位置插入，因为j是第一个值的位置，所以要大于他
				for (int l = k; l > j; l -= i) {
					//如果当前位置的值比前一个位置的小就交换位置，否则就已经是有序了
					if (cVec[l] < cVec[l - i]) {
						std::swap(cVec[l], cVec[l - i]);
					}
					else {
						break;
					}
				}
			}
		}
	}
	end();
}

/*
5
快速排序
类型：非稳定 5 1 2 3 5 4
时间复杂度：
*/
void sort::quickSort(int b,int e) {
	if (b >= e) {
		return;
	}
	unsigned int flag = cVec[b];
	int bsite = b, esite = e;
	while (b < e) {
		while (b<e && flag <= cVec[e]) {
			--e;
		}
		if (flag > cVec[e]) {
			std::swap(cVec[b], cVec[e]);
			++b;
		}
		while (b < e && flag >= cVec[b]) {
			++b;
		}
		if (flag < cVec[b]) {
			std::swap(cVec[b], cVec[e]);
			--e;
		}
	}
		quickSort(e + 1, esite);
		quickSort(bsite, b-1);
	
}

void sort::QuickSort() {
	start("快速排序");
	quickSort(0,nSize-1);
	end();
}

/*
6
堆排序
*/
void sort::buildHeapify(int site,int size) {
	int temp;
	int left = site * 2 + 1;
	int right = site * 2 + 2;
	temp = left;
	while (left < size) {
		//找到子结点中比较大的那个
		if (right < size && cVec[right] > cVec[left]) {
			temp = right;
		}
		//再和双亲结点比较大小，如果小于等于就结束
		if (cVec[site] >= cVec[temp]) {
			break;
		}
		//如果大于双亲结点就交换位置，并继续往下调整
		std::swap(cVec[temp], cVec[site]);
		site = temp;
		left = site * 2 + 1;
		right = site * 2 + 2;
		temp = left;
	}

}

void sort::initHeapify() {
	int half = nSize / 2;
	for (int j = half; j >= 0; --j) {
		buildHeapify(j,nSize);
	}
}


void sort::HeapSort() {
	start("堆排序");
	initHeapify();
	//initHeapify构造出大顶堆，通过交换来让这个最大值移动到最后面
//	std::swap(cVec[0], cVec[nSize - 1]);
	for (int i = 0; i < nSize; ++i) {
		std::swap(cVec[0], cVec[nSize - 1 - i]);
		//重新构造大顶堆
		buildHeapify(0,nSize-1-i);
		
	}
	end();
}

/*
7
基数排序
*/
void sort::RadixSort() {
	;
}

/*
8
归并排序
*/

void sort::mergeArray(int l,int r,int mid){
	std::vector<unsigned int> tempArray;
	int left = l;
	int right = mid+1;
	while (left <= mid&&right <= r) {
		while (left <= mid && cVec[left] <= cVec[right]) {
			tempArray.push_back(cVec[left++]);
		}
		while (right <= r && cVec[left] > cVec[right]) {
			tempArray.push_back(cVec[right++]);
		}
	}

	while (left <= mid) {
		tempArray.push_back(cVec[left++]);
	}
	while (right <= r) {
		tempArray.push_back(cVec[right++]);
	}
	for (int i = 0; i <tempArray.size(); i++) {
		cVec[l + i] = tempArray[i];
	}
}
void sort::mergeSort(int l,int r) {
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	mergeSort(l, mid);
	mergeSort(mid + 1, r);
	mergeArray(l,r,mid);

}


void sort::MergeSort() {
	start("归并排序");
	mergeSort(0, nSize-1);
	end();
}
