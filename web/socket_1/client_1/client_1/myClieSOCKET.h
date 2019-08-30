#pragma once
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>

#define readlen 100
#define maxlen 200
#pragma comment (lib,"ws2_32.lib")

class myClieSOCKET {

	char buf[maxlen];

	WSADATA wsdata;
	SOCKET client;
	sockaddr_in servAddr;

	void f_CreateSocketAddr();

	void f_tcp_CreateSocket();

	void f_udp_CreateSocket();

public:
	myClieSOCKET();
	~myClieSOCKET();
	
	/*
	һֱ�ڷ�����Ϣȥ������
	*/
	void f_tcp_AllSend();
	/*
	ճ������
	num�����͵Ĵ���
	*/
	void f_tcp_visiopacket_send(int num);

	/*
	�����ļ�
	*/
	void f_tcp_fileTransfer_recv();

	void f_udp_send();

};
