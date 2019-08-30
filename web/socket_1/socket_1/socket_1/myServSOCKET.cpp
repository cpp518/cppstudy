#include "stdafx.h"
#include "myServSOCKET.h"
#pragma comment (lib,"ws2_32.lib") //动态连接ws2_32.lib
#define _WINSOCK_DEPRECATED_NO_WARNINGS

myServSOCKET::myServSOCKET(std::string input_type) :type(input_type) {
	//MAKEWORD 将2个byte型合成1个16位的无符号型，第一个参数为低8位的值，第二个参数为高8位的值
	WSAStartup(MAKEWORD(2, 2), &wsadata);  //说明使用winsocket版本号为2.2
	if (type.compare("tcp") == 0) {
		f_tcp_CreateSocket();
	}
	else if (type.compare("udp") == 0) {
		f_udp_CreateSocket();
	}
	f_CreateSocketaddr();

}
myServSOCKET::~myServSOCKET() {
	std::cout << "服务器已关闭" << std::endl;
	closesocket(servSock);
	WSACleanup();
}

void myServSOCKET::f_tcp_CreateSocket() {
	servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}
void myServSOCKET::f_udp_CreateSocket() {
	servSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
}

void myServSOCKET::f_CreateSocketaddr() {
	memset(&sockAddr, 0, sizeof(sockAddr));//初始化
	sockAddr.sin_family = AF_INET;         //同上，即使用ipv4
	inet_pton(AF_INET,"127.0.0.1", &sockAddr.sin_addr.s_addr); //说明要监听的ip地址
	sockAddr.sin_port = htons(9000);  //说明要监听的端口号
									  //IP和端口与套接字绑定起来，监听sockAddr设置的ip地址和端口号
	bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	std::cout << "服务器开始监听：" << std::endl;

	if (type.compare("tcp") == 0) {
		//进入监听状态,监听套接字，20是缓冲区长度
		listen(servSock, 20);
	}
	else if (type.compare("udp") == 0) {
		;
	}

}

/*
一直接收客户端发送的信息，直到发送exit
*/
void myServSOCKET::f_tcp_allRecv() {

	memset(&clntAddr, sizeof(SOCKADDR), 0);
	//使用accept返回的套接字clntSock来与响应的客户端进行交流，即响应客户端的connect
	SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
	while (1) {
		//接受客户端请求


		//确定收到内容的长度
		int len = recv(clntSock, buf, maxlen, 0);
		std::string s(buf);
		if (s.compare("exit") == 0) {
			std::cout << "接收到关闭信息，关闭服务器" << std::endl;
			break;
		}
		std::cout << s << std::endl;
		//std::cout <<clntAddr.sin_addr.s_addr<<" "<< 
		//char *str = "HelloWorld!";
		//使用改长度
		//send(clntSock, buf,len, NULL);

	}
	//关闭套接字
	closesocket(clntSock);

}
/*
粘包展示
*/
void myServSOCKET::f_tcp_visioPacket_Recv() {
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
void myServSOCKET::f_tcp_fileTransfer_send() {
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
			std::cout << "正在发送文件，目前还剩余" << length << "字节" << std::endl;
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

/*
udp模式发包
*/
void myServSOCKET::f_udp_recv() {
	while (1) {
		//udp接收信息
		int recvlen = recvfrom(servSock, buf, readlen, 0, (sockaddr*)&clntAddr, &nSize);
		if (strcmp(buf, "exit") == 0) {
			break;
		}
		std::cout << clntAddr.sin_port << " " << "收到的信息是：" << buf << std::endl;
		//将接收的数据处理一下，再发回去
		buf[recvlen / 2] = 0;
		sendto(servSock, buf, recvlen, 0, (sockaddr*)&clntAddr, nSize);
	}

}