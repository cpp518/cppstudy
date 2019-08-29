// socket_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <winsock2.h>

#define maxlen 200
#define readlen 100

#pragma comment (lib,"ws2_32.lib") //动态连接ws2_32.lib


class myServSOCKET {

	//保存接收的数据
	char buf[maxlen] = { 0 };
	int nSize = sizeof(SOCKADDR);

	SOCKET servSock;
	WSADATA wsadata;
	sockaddr_in sockAddr;
	sockaddr_in clntAddr;


	void f_tcp_CreateSocket() {
		servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	}

	//绑定套接字
	void f_CreateSocketaddr() {
		memset(&sockAddr, 0, sizeof(sockAddr));//初始化
		sockAddr.sin_family = AF_INET;         //同上，即使用ipv4
		sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //说明要监听的ip地址
		sockAddr.sin_port = htons(9000);  //说明要监听的端口号
		//IP和端口与套接字绑定起来，监听sockAddr设置的ip地址和端口号
		bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
		std::cout << "服务器开始监听：" << std::endl;
		//进入监听状态,监听套接字，20是缓冲区长度
		listen(servSock, 20);
	}

public:
	myServSOCKET() {
		//MAKEWORD 将2个byte型合成1个16位的无符号型，第一个参数为低8位的值，第二个参数为高8位的值
		WSAStartup(MAKEWORD(2, 2), &wsadata);  //说明使用winsocket版本号为2.2
		f_tcp_CreateSocket();
		f_CreateSocketaddr();

	}
	~myServSOCKET() {
		std::cout << "服务器已关闭" << std::endl;
		closesocket(servSock);
		WSACleanup();
	}
	/*
	一直接收客户端发送的信息，直到发送exit
	*/
	void f_allRecv() {
		while (1) {
			//接受客户端请求
			
			//使用accept返回的套接字clntSock来与响应的客户端进行交流，即响应客户端的connect
			SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
			
			//确定收到内容的长度
			int len = recv(clntSock, buf, maxlen, 0);
			std::string s(buf);
			if (s.compare("exit") == 0) {
				std::cout << "接收到关闭信息，关闭服务器" << std::endl;
				break;
			}
			std::cout << s << std::endl;
			//char *str = "HelloWorld!";
			//使用改长度
			//send(clntSock, buf,len, NULL);

			//关闭套接字
			closesocket(clntSock);
		}
	}
	/*
	粘包展示
	*/
	void f_visioPacket_Recv() {
		SOCKET client = accept(servSock, (sockaddr*)&clntAddr, &nSize);
		while (1) {
			//接受客户端的连接

			//通过sleep来让客户端信息全部发送到缓冲区，让服务器能够一次读取完
			Sleep(1000);
			//接受到信息
			int len = recv(client, buf, maxlen, 0);
			std::string s(buf);
			if (s.compare("exit") == 0) {
				std::cout << "接收到关闭信息，关闭服务器" << std::endl;
				break;
			}
			std::cout << s << " " << len << std::endl;

		}
		closesocket(client);
	}

	/*
	文件传输
	*/
	void f_fileTransfer_send() {
		std::ifstream infile;

		SOCKET client = accept(servSock, (sockaddr*)&clntAddr, &nSize);
		
		//获取
		do {
			//接收获取的文件名
			recv(client, buf, maxlen, 0);
			std::cout << buf << std::endl;
			//打开文件
			infile.open(buf, std::ios::binary | std::ios::in);
			if (infile.is_open()) {
				break;
			}
			else {
				std::cout << "文件打开失败" << std::endl;
				send(client, "False", 6, 0);
			}
		} while (1);
		


		if (infile.is_open()) {
			//打开文件成功，通知客户端接收文件
			send(client, "True", 5, 0);
			std::cout << "准备发送文件" << std::endl;
			int num = 0;
			//获取文件的大小
			infile.seekg(0, std::ios::end);
			int length = infile.tellg();

			//设置文件指针在第一个位置
			infile.seekg(std::ios::beg);
			//循环读取
			while (length > 0) {
				std::cout << "正在发送文件" << buf << "，目前还剩余" << length << "字节" << std::endl;
				memset(&buf, maxlen, 0);
				//读取内容
				if (length >= readlen) {
					length -= readlen;
					infile.read(buf, readlen);
					num = readlen;
				}
				else {
					num = length;
					infile.read(buf, length);
					length = 0;
				}
				//发送内容
				send(client, buf, num, 0);
			}	
		}	
		else {
			std::cout << "文件打开失败，即将关闭" << std::endl;
		}
		//发送断开连接信息
		shutdown(client, SD_SEND);

		//关闭文件和套接字
		infile.close();
		closesocket(client);
	}
};


int main()
{


	//创建套接字
	//PF_INET AF_INET 使用ipv4
	//SOCK_STREAM 使用面向连接传输方式
	//IPPROTO_TCP 使用TCP协议
	myServSOCKET mysock;


	//mysock.f_allRecv();
	//mysock.f_visioPacket_Recv();
	mysock.f_fileTransfer_send();
	
	return 0;
}




