#include "stdafx.h"
#include "myVector.h"


myVector::myVector(int a,int b,int num)
{
	
	std::random_device rd;  //用于伪随机数引擎获得种子
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
	std::cout << "\n这个是 = ：" << std::endl;
	tempVec = vec;
	Print(tempVec);
}

void myVector::Assign() {
	std::cout << "\n这个是 assign：" << std::endl;
	tempVec = vec;
	std::cout << "调用前：\n";
	Print(tempVec);
	std::cout << "调用后：\n";
	tempVec.assign(10, 6);
	Print(tempVec);
}

void myVector::At(int site) {
	std::cout << "\n这个是 at ：" << std::endl;
	std::cout << "第" << site << "个元素是：" << vec.at(site) << std::endl;
}

void myVector::OperatorBracket(int site) {
	std::cout << "\n这个是 [] ：" << std::endl;
	std::cout << "第" << site << "个元素是：" << vec[site] << "，它的地址是：" << &vec[site] << std::endl;
}

void myVector::Front() {
	std::cout << "\n这个是 front ：" << std::endl;
	std::cout << "第一个元素是：" << vec.front() << std::endl;
}

void myVector::Back() {
	std::cout << "\n这个是 back ：" << std::endl;
	std::cout << "最后一个元素是：" << vec.back() << std::endl;
}

void myVector::Data() {
	std::cout << "\n这个是 data ：" << std::endl;
	std::cout << "第一个元素地址是：" << vec.data() << " ，它的值是：" << *vec.data() << std::endl;
}

void myVector::Begin() {
	std::cout << "\n这个是 begin ：" << std::endl;
	std::vector<int>::iterator itr = vec.begin();
	std::cout << "第二个元素是：" << *(++itr) << std::endl;
	std::vector<int>::const_iterator cItr = vec.cbegin();
	std::cout << "这个是 cbegin ：" << std::endl;
	std::cout << "第一个元素是：" << *cItr << std::endl;
	cItr = itr;
	std::cout << "改变指向的对象了：" << *cItr << std::endl;

}

void myVector::End() {
	std::cout << "\n这个是 end ：" << std::endl;
	std::vector<int>::iterator itr = vec.end();
	std::cout << "最后一个元素是：" << *(--itr) << std::endl;
	std::cout << "这个是 rend ：" << std::endl;
	std::vector<int>::const_iterator cItr = vec.cend();
	std::cout << "顺序打印vec：" << std::endl;
	for (std::vector<int>::iterator i = vec.begin(); i != vec.cend(); ++i) {
		std::cout << *i << " ";
	}
	std::cout<<std::endl;
}

void myVector::Rbegin() {
	std::cout << "\n这个是 rbegin ：" << std::endl;
	std::vector<int>::reverse_iterator itr = vec.rbegin();
	std::cout << "倒数第二个元素是：" << *(++itr) << std::endl;
	std::cout << "这个是 crbegin ：" << std::endl;
	std::vector<int>::const_reverse_iterator cItr = vec.crbegin();
	std::cout << "最后一个元素是：" << *cItr << std::endl;

}

void myVector::Rend() {
	std::cout << "\n这个是 rend ：" << std::endl;
	std::vector<int>::reverse_iterator itr = vec.rend();
	std::cout << "第一个元素是：" << *(--itr) << std::endl;
	std::cout << "这个是 crend ：" << std::endl;
	std::vector<int>::const_reverse_iterator cItr = vec.crend();
	std::cout << "顺序打印vec：" << std::endl;
	for (itr = vec.rbegin(); itr != cItr; ++itr) {
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
}

void myVector::Empty() {
	std::cout << "\n这个是 empty ：" << std::endl;
	if (vec.empty()) {
		std::cout << "vec为空！\n";
	}
	else {
		std::cout << "vec不为空！\n";
	}
}

void myVector::Size() {
	std::cout << "\n这个是 size ：" << std::endl;
	std::cout << "vec当前元素个数为：" << vec.size() << std::endl;
}

void myVector::Max_Size() {
	std::cout << "\n这个是 max_size ：" << std::endl;
	std::cout << "vec最大元素容纳个数为：" << vec.max_size() << std::endl;
}

void myVector::Reserve(int count) {
	std::cout << "\n这个是 reserve ：" << std::endl;
	std::cout << "vec当前存储容量：" << vec.capacity() << std::endl;
	std::cout << "重新分配容量大小\n";
	vec.reserve(count);
	std::cout << "vec当前存储容量：" << vec.capacity() << std::endl;
}

void myVector::Capacity() {
	std::cout << "\n这个是 capacity ：" << std::endl;
	std::cout << "vec当前存储容量：" << vec.capacity() << std::endl;

}

void myVector::Shrink_to_fit() {
	std::cout<< "\n这个是 shrink_to_fit ：" << std::endl;
	std::cout << "vec当前存储容量：" << vec.capacity() << std::endl;
	vec.shrink_to_fit();
	std::cout << "vec当前存储容量：" << vec.capacity() << std::endl;
}

void myVector::Clear() {
	std::cout << "\n这个是 clear ：" << std::endl;
	tempVec = vec;
	std::cout << "vec当前元素个数：" << tempVec.size() << std::endl;
	tempVec.clear();
	std::cout << "vec执行后元素个数：" << tempVec.size() << std::endl;
}

void myVector::Insert() {
	std::cout << "\n这个是 insert ：" << std::endl;
	tempVec = vec;
	std::cout << "插入之前：\n";
	Print(tempVec);
	std::cout << "在第3个位置插入4：" << std::endl;
	tempVec.insert(tempVec.begin() + 3, 4);
	Print(tempVec);
	std::cout << "在第3个位置插入4个5：\n";
	tempVec.insert(tempVec.begin() + 3, 4, 5 );
	Print(tempVec);
}

void myVector::Erase() {
	std::cout << "\n这个是 Erase ：" << std::endl;
	tempVec = vec;
	std::cout << "删除之前：\n";
	Print(tempVec);
	std::cout << "删除第3个位置的值之后：\n";
	tempVec.erase(tempVec.begin()+3);
	Print(tempVec);
	std::cout << "删除容器第0到第5个元素：\n";
	tempVec.erase(tempVec.begin(), tempVec.begin() + 5);
	Print(tempVec);
}

void myVector::Emplace() {
	;
}

void myVector::Push_back(int num) {
	std::cout << "\n这个是 push_back ：" << std::endl;
	std::cout << "添加元素前：\n";
	tempVec = vec;
	Print(tempVec);
	std::cout << "添加元素后：\n";
	tempVec.push_back(num);
	Print(tempVec);
}

void myVector::Pop_back() {
	std::cout << "\n这个是 pop_back ：" << std::endl;
	std::cout << "删除元素前：\n";
	tempVec = vec;
	Print(tempVec);
	std::cout << "删除元素后：\n";
	tempVec.pop_back();
	Print(tempVec);
}

void myVector::Resize(int num) {
	std::cout << "\n这个是 resize ：" << std::endl;
	std::cout << "调整大小前：\n";
	tempVec = vec;
	Print(tempVec);
	std::cout << "调整大小后：\n";
	tempVec.resize(num);
	Print(tempVec);
	std::cout << "调整到15个元素，后5个为0：\n";
	tempVec.resize(15);
	Print(tempVec);
	std::cout << "调整到20个元素，后5个为999：\n";
	tempVec.resize(20,999);
	Print(tempVec);
}

void myVector::Swap() {
	std::cout << "\n这个是 swap ：" << std::endl;
	std::cout << "交换前：\n";
	std::cout << "vec：";
	Print(vec);
	std::cout << "tempVec:";
	Print(tempVec);
	tempVec.swap(vec);
	std::cout << "交换后：\n";
	std::cout << "vec：";
	Print(vec);
	std::cout << "tempVec:";
	Print(tempVec);

}