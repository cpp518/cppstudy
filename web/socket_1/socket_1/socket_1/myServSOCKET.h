#pragma once
#include "stdafx.h"

class myServSOCKET {

	//保存接收的数据
	char buf[maxlen] = { 0 };
	int nSize = sizeof(SOCKADDR);
	std::string type;

	SOCKET servSock;
	WSADATA wsadata;
	sockaddr_in sockAddr;
	sockaddr_in clntAddr;


	void f_tcp_CreateSocket();
	void f_udp_CreateSocket();

	//绑定套接字
	void f_CreateSocketaddr();

public:
	myServSOCKET(std::string input_type);
	~myServSOCKET();
	/*
	一直接收客户端发送的信息，直到发送exit
	*/
	void f_tcp_allRecv();
	/*
	粘包展示
	*/
	void f_tcp_visioPacket_Recv();
	/*
	解决粘包问题
	*/
	void f_tcp_solveVisioPacket_Recv();
	/*
	文件传输
	*/
	void f_tcp_fileTransfer_send();

	/*
	udp模式发包
	*/
	void f_udp_recv();
};

