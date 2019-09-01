#include "stdafx.h"
#include "myVector.h"


myVector::myVector(int a,int b,int num)
{
	
	std::random_device rd;  //����α���������������
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(a, b);
	for (int i = 0; i < num; ++i) {
	//	std::cout << vec.size() << std::endl;
		vec.push_back(dis(gen));

	}
	vecSize = num;
}


myVector::~myVector()
{
}

void Print(std::vector<int> vec) {
	//std::cout << vecSize << std::endl;

	for (unsigned int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

std::vector<int> myVector::GetVec() {
	return vec;
}

void myVector::OperatorEqual() {
	std::cout << "\n����� = ��" << std::endl;
	tempVec = vec;
	Print(tempVec);
}

void myVector::Assign() {
	std::cout << "\n����� assign��" << std::endl;
	tempVec = vec;
	std::cout << "����ǰ��\n";
	Print(tempVec);
	std::cout << "���ú�\n";
	tempVec.assign(10, 6);
	Print(tempVec);
}

void myVector::At(int site) {
	std::cout << "\n����� at ��" << std::endl;
	std::cout << "��" << site << "��Ԫ���ǣ�" << vec.at(site) << std::endl;
}

void myVector::OperatorBracket(int site) {
	std::cout << "\n����� [] ��" << std::endl;
	std::cout << "��" << site << "��Ԫ���ǣ�" << vec[site] << "�����ĵ�ַ�ǣ�" << &vec[site] << std::endl;
}

void myVector::Front() {
	std::cout << "\n����� front ��" << std::endl;
	std::cout << "��һ��Ԫ���ǣ�" << vec.front() << std::endl;
}

void myVector::Back() {
	std::cout << "\n����� back ��" << std::endl;
	std::cout << "���һ��Ԫ���ǣ�" << vec.back() << std::endl;
}

void myVector::Data() {
	std::cout << "\n����� data ��" << std::endl;
	std::cout << "��һ��Ԫ�ص�ַ�ǣ�" << vec.data() << " ������ֵ�ǣ�" << *vec.data() << std::endl;
}

void myVector::Begin() {
	std::cout << "\n����� begin ��" << std::endl;
	std::vector<int>::iterator itr = vec.begin();
	std::cout << "�ڶ���Ԫ���ǣ�" << *(++itr) << std::endl;
	std::vector<int>::const_iterator cItr = vec.cbegin();
	std::cout << "����� cbegin ��" << std::endl;
	std::cout << "��һ��Ԫ���ǣ�" << *cItr << std::endl;
	cItr = itr;
	std::cout << "�ı�ָ��Ķ����ˣ�" << *cItr << std::endl;

}

void myVector::End() {
	std::cout << "\n����� end ��" << std::endl;
	std::vector<int>::iterator itr = vec.end();
	std::cout << "���һ��Ԫ���ǣ�" << *(--itr) << std::endl;
	std::cout << "����� rend ��" << std::endl;
	std::vector<int>::const_iterator cItr = vec.cend();
	std::cout << "˳���ӡvec��" << std::endl;
	for (std::vector<int>::iterator i = vec.begin(); i != vec.cend(); ++i) {
		std::cout << *i << " ";
	}
	std::cout<<std::endl;
}

void myVector::Rbegin() {
	std::cout << "\n����� rbegin ��" << std::endl;
	std::vector<int>::reverse_iterator itr = vec.rbegin();
	std::cout << "�����ڶ���Ԫ���ǣ�" << *(++itr) << std::endl;
	std::cout << "����� crbegin ��" << std::endl;
	std::vector<int>::const_reverse_iterator cItr = vec.crbegin();
	std::cout << "���һ��Ԫ���ǣ�" << *cItr << std::endl;

}

void myVector::Rend() {
	std::cout << "\n����� rend ��" << std::endl;
	std::vector<int>::reverse_iterator itr = vec.rend();
	std::cout << "��һ��Ԫ���ǣ�" << *(--itr) << std::endl;
	std::cout << "����� crend ��" << std::endl;
	std::vector<int>::const_reverse_iterator cItr = vec.crend();
	std::cout << "˳���ӡvec��" << std::endl;
	for (itr = vec.rbegin(); itr != cItr; ++itr) {
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
}

void myVector::Empty() {
	std::cout << "\n����� empty ��" << std::endl;
	if (vec.empty()) {
		std::cout << "vecΪ�գ�\n";
	}
	else {
		std::cout << "vec��Ϊ�գ�\n";
	}
}

void myVector::Size() {
	std::cout << "\n����� size ��" << std::endl;
	std::cout << "vec��ǰԪ�ظ���Ϊ��" << vec.size() << std::endl;
}

void myVector::Max_Size() {
	std::cout << "\n����� max_size ��" << std::endl;
	std::cout << "vec���Ԫ�����ɸ���Ϊ��" << vec.max_size() << std::endl;
}

void myVector::Reserve(int count) {
	std::cout << "\n����� reserve ��" << std::endl;
	std::cout << "vec��ǰ�洢������" << vec.capacity() << std::endl;
	std::cout << "���·���������С\n";
	vec.reserve(count);
	std::cout << "vec��ǰ�洢������" << vec.capacity() << std::endl;
}

void myVector::Capacity() {
	std::cout << "\n����� capacity ��" << std::endl;
	std::cout << "vec��ǰ�洢������" << vec.capacity() << std::endl;

}

void myVector::Shrink_to_fit() {
	std::cout<< "\n����� shrink_to_fit ��" << std::endl;
	std::cout << "vec��ǰ�洢������" << vec.capacity() << std::endl;
	vec.shrink_to_fit();
	std::cout << "vec��ǰ�洢������" << vec.capacity() << std::endl;
}

void myVector::Clear() {
	std::cout << "\n����� clear ��" << std::endl;
	tempVec = vec;
	std::cout << "vec��ǰԪ�ظ�����" << tempVec.size() << std::endl;
	tempVec.clear();
	std::cout << "vecִ�к�Ԫ�ظ�����" << tempVec.size() << std::endl;
}

void myVector::Insert() {
	std::cout << "\n����� insert ��" << std::endl;
	tempVec = vec;
	std::cout << "����֮ǰ��\n";
	Print(tempVec);
	std::cout << "�ڵ�3��λ�ò���4��" << std::endl;
	tempVec.insert(tempVec.begin() + 3, 4);
	Print(tempVec);
	std::cout << "�ڵ�3��λ�ò���4��5��\n";
	tempVec.insert(tempVec.begin() + 3, 4, 5 );
	Print(tempVec);
}

void myVector::Erase() {
	std::cout << "\n����� Erase ��" << std::endl;
	tempVec = vec;
	std::cout << "ɾ��֮ǰ��\n";
	Print(tempVec);
	std::cout << "ɾ����3��λ�õ�ֵ֮��\n";
	tempVec.erase(tempVec.begin()+3);
	Print(tempVec);
	std::cout << "ɾ��������0����5��Ԫ�أ�\n";
	tempVec.erase(tempVec.begin(), tempVec.begin() + 5);
	Print(tempVec);
}

void myVector::Emplace() {
	;
}

void myVector::Push_back(int num) {
	std::cout << "\n����� push_back ��" << std::endl;
	std::cout << "���Ԫ��ǰ��\n";
	tempVec = vec;
	Print(tempVec);
	std::cout << "���Ԫ�غ�\n";
	tempVec.push_back(num);
	Print(tempVec);
}

void myVector::Pop_back() {
	std::cout << "\n����� pop_back ��" << std::endl;
	std::cout << "ɾ��Ԫ��ǰ��\n";
	tempVec = vec;
	Print(tempVec);
	std::cout << "ɾ��Ԫ�غ�\n";
	tempVec.pop_back();
	Print(tempVec);
}

void myVector::Resize(int num) {
	std::cout << "\n����� resize ��" << std::endl;
	std::cout << "������Сǰ��\n";
	tempVec = vec;
	Print(tempVec);
	std::cout << "������С��\n";
	tempVec.resize(num);
	Print(tempVec);
	std::cout << "������15��Ԫ�أ���5��Ϊ0��\n";
	tempVec.resize(15);
	Print(tempVec);
	std::cout << "������20��Ԫ�أ���5��Ϊ999��\n";
	tempVec.resize(20,999);
	Print(tempVec);
}

void myVector::Swap() {
	std::cout << "\n����� swap ��" << std::endl;
	std::cout << "����ǰ��\n";
	std::cout << "vec��";
	Print(vec);
	std::cout << "tempVec:";
	Print(tempVec);
	tempVec.swap(vec);
	std::cout << "������\n";
	std::cout << "vec��";
	Print(vec);
	std::cout << "tempVec:";
	Print(tempVec);

}