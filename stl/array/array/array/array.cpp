#include "stdafx.h"
#include "array.h"

void Print(std::array<int,20> arr) {
	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << " ";
	}
//	std::cout << std::endl;
}

myArray::myArray(int begin, int end, int num) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> uid(begin,end);
	for (int i = 0; i < num; ++i) {
		arr[i] = uid(gen);
	}
	std::cout << "我是arr：\n";
	Print(arr);
	std::cout << "\n";
}

myArray::~myArray() {

}

void myArray::OperatorEqual() {
	std::cout << "\n这个是 operator= ：\n";
	std::cout << "执行前tempArr是：";
	Print(tempArr);
	tempArr = arr;
	std::cout << "\n执行后tempArr是：";
	Print(arr);
	std::cout << "\n";
}

void myArray::At(int num) {
	std::cout << "\n这个是 at ：\n";
	std::cout << "打印第" << num << "个位置的值：" << arr.at(num) << "std::endl";
}

void myArray::OperatorBracket(int num) {
	std::cout << "\n这个是 operator[] ：\n";
	std::cout << "打印第" << num << "个位置的值：" << arr[num] << "std::endl";

}

void myArray::Front() {
	std::cout << "\n这个是 front ：\n";
	std::cout << "打印第一个位置的值：" << arr.front() << std::endl;
}

void myArray::Back() {
	std::cout << "\n这个是 back ：\n";
	std::cout << "打印最后一个位置的值：" << arr.back() << std::endl;

}

void myArray::Data() {
	std::cout << "\n这个是 data ：\n";
	std::cout << "打印第一个位置的地址：" << arr.data() << "它的值是" << *arr.data() << std::endl;

}


void myArray::Begin() {
	std::cout << "\n这个是 begin ：\n";
	auto ite = tempArr.begin();
	std::cout << "打印第二个元素：" << *++ite << std::endl;
	std::cout << "这个是 cbegin ：\n";
	auto cIte = tempArr.cbegin(); 
	std::cout << "打印第一个元素：" << *cIte << std::endl;
}

void myArray::End() {
	std::cout << "\n这个是 end ：\n";
	auto ite = tempArr.end();
	std::cout << "打印第二个元素：" << *--ite << std::endl;
	std::cout << "这个是 cbegin ：\n";
	for (auto cIte = tempArr.begin(); cIte != tempArr.cend(); ++cIte) {
		std::cout << *cIte << " ";
	}
	std::cout << std::endl;
}

void myArray::Rbegin() {
	std::cout << "\n这个是 rbegin ：\n";
	auto ite = tempArr.rbegin();
	std::cout << "打印倒数第二个元素：" << *++ite << std::endl;
	std::cout << "这个是 cbegin ：\n";
	auto cIte = tempArr.crbegin();
	std::cout << "打印最后一个元素：" << *cIte << std::endl;
}

void myArray::Rend() {
	std::cout << "\n这个是 rend ：\n";
	auto ite = tempArr.rend();
	std::cout << "打印第一个元素：" << *--ite << std::endl;
	std::cout << "这个是 crend ：\n";
	for (auto cIte = tempArr.rbegin(); cIte != tempArr.crend(); ++cIte) {
		std::cout << *cIte << " ";
	}
	std::cout << std::endl;
}

void myArray::Empty() {
	std::cout << "\n这个是 empty ：\n";
	if (!arr.empty()) {
		std::cout << "arr不为空\n";
	}
	else {
		std::cout << "arr为空\n";
	}
}

void myArray::Size() {
	std::cout << "\n这个是 size ：\n";
	std::cout << "arr的当前元素个数为 "<< arr.size() <<"\n";
}

void myArray::Max_Size() {
	std::cout << "\n这个是 size ：\n";
	std::cout << "arr的容纳元素个数最多为 " << arr.size() << "\n";

}

void myArray::Fill(int num) {
	std::cout << "\n这个是 fill ：\n";
	std::cout << "执行前：";
	Print(tempArr);
	std::cout << "\n执行后：";
	tempArr.fill(num);
	Print(tempArr);
	std::cout << std::endl;
}

void myArray::Swap() {
	std::cout << "\n这个是 swap ：\n";
	std::cout << "交换前：\n";
	std::cout << "arr：";
	Print(arr);
	std::cout << "\ntempArr:";
	Print(tempArr);
	std::cout << "\n交换后：\n";
	tempArr.swap(arr);
	std::cout << "arr：";
	Print(arr);
	std::cout << "\ntempArr:";
	Print(tempArr);

}
