#pragma once
#include "stdafx.h"

class myServSOCKET {

	//������յ�����
	char buf[maxlen] = { 0 };
	int nSize = sizeof(SOCKADDR);
	std::string type;

	SOCKET servSock;
	WSADATA wsadata;
	sockaddr_in sockAddr;
	sockaddr_in clntAddr;


	void f_tcp_CreateSocket();
	void f_udp_CreateSocket();

	//���׽���
	void f_CreateSocketaddr();

public:
	myServSOCKET(std::string input_type);
	~myServSOCKET();
	/*
	һֱ���տͻ��˷��͵���Ϣ��ֱ������exit
	*/
	void f_tcp_allRecv();
	/*
	ճ��չʾ
	*/
	void f_tcp_visioPacket_Recv();
	/*
	���ճ������
	*/
	void f_tcp_solveVisioPacket_Recv();
	/*
	�ļ�����
	*/
	void f_tcp_fileTransfer_send();

	/*
	udpģʽ����
	*/
	void f_udp_recv();
};

