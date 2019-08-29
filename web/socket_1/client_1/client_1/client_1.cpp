// client_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <WinSock2.h>

#define readlen 100
#define maxlen 200
#pragma comment (lib,"ws2_32.lib")

class myClieSOCKET {

	char buf[maxlen];

	WSADATA wsdata;
	SOCKET client;
	sockaddr_in servAddr;

	void f_CreateSocketAddr() {
		memset(&servAddr, 0, sizeof(sockaddr_in));
		servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
		servAddr.sin_port = htons(9000);
		servAddr.sin_family = PF_INET;
	}

	void f_tcp_CreateSocket() {
		client = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	}

	void f_udp_CreateSocket() {
		client = socket(PF_INET, SOCK_DGRAM, 0);
	}

public:
	myClieSOCKET() {
		std::cout << "我是client" << std::endl;
		WSAStartup(MAKEWORD(2, 2), &wsdata);
		f_CreateSocketAddr();
		
	}
	~myClieSOCKET() {
		std::cout << "关闭客户端成功" << std::endl;
		//关闭dll
		WSACleanup();
	}
	//配置要连接的服务器地址和端口
	/*
	一直在发送消息去服务器
	*/
	void f_tcp_AllSend() {
		f_tcp_CreateSocket();
		connect(client, (sockaddr*)&servAddr, sizeof(sockaddr_in));
		//循环
		while (1) {
			std::string s;
			
			//连接
			std::cout << "请输入内容（长度为100个字符）：";
			std::cin >> s;
		//	std::getline(std::cin, s);
			send(client, s.c_str(), s.size() + 1, 0);
			if (s.compare("exit") == 0) {
				break;
			}
			
			//	i++;
		}
		//关闭套接字
		closesocket(client);
	}
	/*
	粘包发送
	num：发送的次数
	*/
	void f_tcp_visiopacket_send(int num) {
		f_tcp_CreateSocket();
		connect(client, (sockaddr*)&servAddr, sizeof(sockaddr));
		std::string s("1234");
		for (int i = 0; i < num;++i)
			std::cout<<send(client, s.c_str(), s.size(), 0)<<std::endl;
		send(client, "\0", 1, 0);
		//让服务端先读取完前面的内容在发送结束
		Sleep(4000);
		s = "exit";
		std::cout << send(client, s.c_str(), s.size() + 1, 0) << std::endl;
		//Sleep(50000);
		closesocket(client);
	}
	
	/*
	接收文件
	*/
	void f_tcp_fileTransfer_recv() {

		std::ofstream f;
		std::string fileName;
		//创建client，用于连接服务端
		f_tcp_CreateSocket();

		//连接到服务端
		connect(client, (sockaddr*)&servAddr, sizeof(sockaddr));
		while (1) {
			memset(buf, maxlen, 0);
			std::cout << "请输入要下载的文件名称：" ;
			//输入文件名称
			std::cin >> fileName;
			send(client, fileName.c_str(), fileName.size() + 1, 0);
			recv(client, buf, readlen, 0);
			if (strcmp(buf, "True") == 0) {
				break;
			}
		}
		//打开文件
		f.open(fileName.c_str(), std::ios::binary | std::ios::out);

		while (1) {
			int nlen = recv(client, buf, readlen, 0);
			if (nlen <= 0) {
				std::cout << "文件接收完毕！" << std::endl;
				break;
			}
			else {
				f.write(buf, nlen);
				f.flush();
			}
		}
		f.close();
		closesocket(client);
	}

	void f_udp_send() {
		f_udp_CreateSocket();
		int nSize = sizeof(sockaddr);
		while (1) {
			
			std::string sendMessage;
			std::cout << "输入要发送的内容（输入exit结束）：";
			std::cin >> sendMessage;
			sendto(client, sendMessage.c_str(), sendMessage.size() + 1, 0, (sockaddr*)&servAddr, sizeof(sockaddr));
			if (sendMessage.compare("exit") == 0) {
			//	std::cout << "退出客户端" << std::endl;
				break;
			}
			recvfrom(client, buf, readlen, 0, (sockaddr*)&servAddr, &nSize);
			std::cout << "我收到了服务器的：" << buf << std::endl;
		}
	} 

};

int main()
{
	myClieSOCKET mysock;
	mysock.f_tcp_AllSend();
	//mysock.f_visiopacket_send(5);
	//mysock.f_udp_send();
	return 0;
}

