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
	std::cout << "\n" << name << "-����ʼ" << std::endl;
	e.restart();
}

void sort::end() {
	std::cout << "�������������ʱ���ǣ�" << e.elapsed() << "��" << std::endl;
	if (!compare()) {
		print();
	}	
}

/*
std�Դ���sort�����ڼ����������Ƿ���ȷ
*/
void sort::StdSort() {
	stdVec = sortVec;
	std::sort(stdVec.begin(), stdVec.end());
}

/*
���ڱȽ��������Ƿ���ȷ
*/
bool sort::compare() {
	for (int i = 0; i < nSize; ++i) {
		if (stdVec[i] != cVec[i]) {
			std::cout << "��������������" << std::endl;
			return false;
		}
	}
	std::cout << "��������ȷ" << std::endl;
	return true;
}

/*
1
ð������
���ͣ��ȶ�����
ʱ�临�Ӷȣ�1+2+...+n = ((1+n)*n)/2 = n*n
*/
void sort::BubbleSort() {
	start("ð������");
	//�Ż���
	//��������һ�����Ϊ����ʾǰһ���Ƿ��ƶ������֣����û�����ʾ��һλ����ǰһλ��
	//�������Ѿ�����
	bool flag =  true;
	//ÿ��jѭ����ɺ󣬱�ʾ����ĵ�iλ������������
	for (int i = nSize - 1; i > 0 && flag; --i) {
		flag = false;
		
		//�������һ��ֵ��ʼ
		for (int j = 0; j < i; ++j) {
			//�ͺ�һ��ֵ�Ƚϣ�������ھͽ���λ��
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
ѡ������
���ͣ����ȶ�
ʱ�临�Ӷȣ�1+2+...+n = (n+1)*n/2 = n*2
*/
void sort::SelectSort() {
	start("ѡ������");
	
	//ÿ��jѭ����������ʾ�ҵ�һ����С��ֵ��
	for (int i = 0; i < nSize; ++i) {
		//����mΪ��ǰ��Сֵ���±�λ��
		int m = i;
		//��m������±����ҵ����±�m��ҪС��ֵ
		for (int j = i+1; j < nSize; ++j) {
			if (cVec[m] > cVec[j]) {
				m = j;
			}
		}
		//�������m��ֵ�ı��ˣ��ͽ������ǵ�λ��
		if (m != i) {
			std::swap(cVec[m], cVec[i]);
		}
	}
	end();
}

/*
3
��������
���ͣ��ȶ�
ʱ�临�Ӷȣ�1+2+...+n = (n+1)*n/2 = n*2
*/

void sort::InsertSort() {
	int i,j;
	start("��������");
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
ϣ������
���ͣ����ȶ� :4 2 1 3 3
ʱ�临�Ӷȣ�
*/
void sort::ShellSort() {
	
	start("ϣ������");
	//�������
	for (int i = nSize / 2; i > 0; i/=2) {
		//��ʼ�±꣬����[j]���뵽ǰ��ȥ
		for (int j = 0; j < i ; ++j) {
			//kѭ����ʾ�о�ÿ�������ֵ		
			for (int k = j+i; k < nSize; k += i) {
				//lѭ����ʾ��ǰ���ֵ���ҵ�λ�ò��룬��Ϊj�ǵ�һ��ֵ��λ�ã�����Ҫ������
				for (int l = k; l > j; l -= i) {
					//�����ǰλ�õ�ֵ��ǰһ��λ�õ�С�ͽ���λ�ã�������Ѿ���������
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
��������
���ͣ����ȶ� 5 1 2 3 5 4
ʱ�临�Ӷȣ�
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
	start("��������");
	quickSort(0,nSize-1);
	end();
}

/*
6
������
*/
void sort::buildHeapify(int site,int size) {
	int temp;
	int left = site * 2 + 1;
	int right = site * 2 + 2;
	temp = left;
	while (left < size) {
		//�ҵ��ӽ���бȽϴ���Ǹ�
		if (right < size && cVec[right] > cVec[left]) {
			temp = right;
		}
		//�ٺ�˫�׽��Ƚϴ�С�����С�ڵ��ھͽ���
		if (cVec[site] >= cVec[temp]) {
			break;
		}
		//�������˫�׽��ͽ���λ�ã����������µ���
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
	start("������");
	initHeapify();
	//initHeapify������󶥶ѣ�ͨ����������������ֵ�ƶ��������
//	std::swap(cVec[0], cVec[nSize - 1]);
	for (int i = 0; i < nSize; ++i) {
		std::swap(cVec[0], cVec[nSize - 1 - i]);
		//���¹���󶥶�
		buildHeapify(0,nSize-1-i);
		
	}
	end();
}

/*
7
��������
*/
void sort::RadixSort() {
	;
}

/*
8
�鲢����
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
	start("�鲢����");
	mergeSort(0, nSize-1);
	end();
}
