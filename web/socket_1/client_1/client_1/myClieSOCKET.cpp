//#pragma once

#include "stdafx.h"

myClieSOCKET::myClieSOCKET()
{
	std::cout << "����client" << std::endl;
	WSAStartup(MAKEWORD(2, 2), &wsdata);
	f_CreateSocketAddr();
}


myClieSOCKET::~myClieSOCKET()
{
	std::cout << "�رտͻ��˳ɹ�" << std::endl;
	//�ر�dll
	WSACleanup();
}

void myClieSOCKET::f_CreateSocketAddr() {
	memset(&servAddr, 0, sizeof(sockaddr_in));
	//servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr.s_addr);
	servAddr.sin_port = htons(9000);
	servAddr.sin_family = AF_INET;
}

void myClieSOCKET::f_tcp_CreateSocket() {
	client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

void myClieSOCKET::f_udp_CreateSocket() {
	client = socket(AF_INET, SOCK_DGRAM, 0);
}

/*
һֱ�ڷ�����Ϣȥ������
*/
void myClieSOCKET::f_tcp_AllSend() {
	f_tcp_CreateSocket();
	connect(client, (sockaddr*)&servAddr, sizeof(sockaddr_in));
	//ѭ��
	while (1) {
		std::string s;

		//����
		std::cout << "���������ݣ�����Ϊ100���ַ�����";
		std::cin >> s;
		//	std::getline(std::cin, s);
		send(client, s.c_str(), s.size() + 1, 0);
		if (s.compare("exit") == 0) {
			break;
		}

		//	i++;
	}
	//�ر��׽���
	closesocket(client);
}
/*
ճ������
num�����͵Ĵ���
*/
void myClieSOCKET::f_tcp_visiopacket_send(int num) {
	f_tcp_CreateSocket();
	connect(client, (sockaddr*)&servAddr, sizeof(sockaddr));
	std::string s("123456789A");
	for (int i = 0; i < num; ++i)
		//send()
		std::cout << send(client, s.c_str(), s.size(), 0) << std::endl;
//	send(client, "\0", 1, 0);
	//�÷�����ȶ�ȡ��ǰ��������ڷ��ͽ���
	Sleep(4000);
	s = "exit";
	std::cout << send(client, s.c_str(), s.size() + 1, 0) << std::endl;
	//Sleep(50000);
	closesocket(client);
}

/*
�����ļ�
*/
void myClieSOCKET::f_tcp_fileTransfer_recv() {

	std::ofstream f;
	std::string fileName;
	//����client���������ӷ����
	f_tcp_CreateSocket();

	//���ӵ������
	connect(client, (sockaddr*)&servAddr, sizeof(sockaddr));
	while (1) {
		memset(buf, maxlen, 0);
		std::cout << "������Ҫ���ص��ļ����ƣ�";
		//�����ļ�����
		std::cin >> fileName;
		send(client, fileName.c_str(), fileName.size() + 1, 0);
		recv(client, buf, readlen, 0);
		if (strcmp(buf, "True") == 0) {
			break;
		}
	}
	//���ļ�
	f.open(fileName.c_str(), std::ios::binary | std::ios::out);

	while (1) {
		int nlen = recv(client, buf, readlen, 0);
		if (nlen <= 0) {
			std::cout << "�ļ�������ϣ�" << std::endl;
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

void myClieSOCKET::f_udp_send() {
	f_udp_CreateSocket();
	int nSize = sizeof(sockaddr);
	while (1) {

		std::string sendMessage;
		std::cout << "����Ҫ���͵����ݣ�����exit��������";
		std::cin >> sendMessage;
		sendto(client, sendMessage.c_str(), sendMessage.size() + 1, 0, (sockaddr*)&servAddr, sizeof(sockaddr));
		if (sendMessage.compare("exit") == 0) {
			//	std::cout << "�˳��ͻ���" << std::endl;
			break;
		}
		recvfrom(client, buf, readlen, 0, (sockaddr*)&servAddr, &nSize);
		std::cout << "���յ��˷������ģ�" << buf << std::endl;
	}
}