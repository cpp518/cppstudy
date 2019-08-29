// client_1.cpp : �������̨Ӧ�ó������ڵ㡣
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
		std::cout << "����client" << std::endl;
		WSAStartup(MAKEWORD(2, 2), &wsdata);
		f_CreateSocketAddr();
		
	}
	~myClieSOCKET() {
		std::cout << "�رտͻ��˳ɹ�" << std::endl;
		//�ر�dll
		WSACleanup();
	}
	//����Ҫ���ӵķ�������ַ�Ͷ˿�
	/*
	һֱ�ڷ�����Ϣȥ������
	*/
	void f_tcp_AllSend() {
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
	void f_tcp_visiopacket_send(int num) {
		f_tcp_CreateSocket();
		connect(client, (sockaddr*)&servAddr, sizeof(sockaddr));
		std::string s("1234");
		for (int i = 0; i < num;++i)
			std::cout<<send(client, s.c_str(), s.size(), 0)<<std::endl;
		send(client, "\0", 1, 0);
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
	void f_tcp_fileTransfer_recv() {

		std::ofstream f;
		std::string fileName;
		//����client���������ӷ����
		f_tcp_CreateSocket();

		//���ӵ������
		connect(client, (sockaddr*)&servAddr, sizeof(sockaddr));
		while (1) {
			memset(buf, maxlen, 0);
			std::cout << "������Ҫ���ص��ļ����ƣ�" ;
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

	void f_udp_send() {
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

};

int main()
{
	myClieSOCKET mysock;
	mysock.f_tcp_AllSend();
	//mysock.f_visiopacket_send(5);
	//mysock.f_udp_send();
	return 0;
}

