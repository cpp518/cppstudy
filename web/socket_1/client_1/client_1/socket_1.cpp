// socket_1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <winsock2.h>

#define maxlen 200
#define readlen 100

#pragma comment (lib,"ws2_32.lib") //��̬����ws2_32.lib


class myServSOCKET {

	//������յ�����
	char buf[maxlen] = { 0 };
	int nSize = sizeof(SOCKADDR);

	SOCKET servSock;
	WSADATA wsadata;
	sockaddr_in sockAddr;
	sockaddr_in clntAddr;


	void f_tcp_CreateSocket() {
		servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	}

	//���׽���
	void f_CreateSocketaddr() {
		memset(&sockAddr, 0, sizeof(sockAddr));//��ʼ��
		sockAddr.sin_family = AF_INET;         //ͬ�ϣ���ʹ��ipv4
		sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //˵��Ҫ������ip��ַ
		sockAddr.sin_port = htons(9000);  //˵��Ҫ�����Ķ˿ں�
		//IP�Ͷ˿����׽��ְ�����������sockAddr���õ�ip��ַ�Ͷ˿ں�
		bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
		std::cout << "��������ʼ������" << std::endl;
		//�������״̬,�����׽��֣�20�ǻ���������
		listen(servSock, 20);
	}

public:
	myServSOCKET() {
		//MAKEWORD ��2��byte�ͺϳ�1��16λ���޷����ͣ���һ������Ϊ��8λ��ֵ���ڶ�������Ϊ��8λ��ֵ
		WSAStartup(MAKEWORD(2, 2), &wsadata);  //˵��ʹ��winsocket�汾��Ϊ2.2
		f_tcp_CreateSocket();
		f_CreateSocketaddr();

	}
	~myServSOCKET() {
		std::cout << "�������ѹر�" << std::endl;
		closesocket(servSock);
		WSACleanup();
	}
	/*
	һֱ���տͻ��˷��͵���Ϣ��ֱ������exit
	*/
	void f_allRecv() {
		while (1) {
			//���ܿͻ�������
			
			//ʹ��accept���ص��׽���clntSock������Ӧ�Ŀͻ��˽��н���������Ӧ�ͻ��˵�connect
			SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
			
			//ȷ���յ����ݵĳ���
			int len = recv(clntSock, buf, maxlen, 0);
			std::string s(buf);
			if (s.compare("exit") == 0) {
				std::cout << "���յ��ر���Ϣ���رշ�����" << std::endl;
				break;
			}
			std::cout << s << std::endl;
			//char *str = "HelloWorld!";
			//ʹ�øĳ���
			//send(clntSock, buf,len, NULL);

			//�ر��׽���
			closesocket(clntSock);
		}
	}
	/*
	ճ��չʾ
	*/
	void f_visioPacket_Recv() {
		SOCKET client = accept(servSock, (sockaddr*)&clntAddr, &nSize);
		while (1) {
			//���ܿͻ��˵�����

			//ͨ��sleep���ÿͻ�����Ϣȫ�����͵����������÷������ܹ�һ�ζ�ȡ��
			Sleep(1000);
			//���ܵ���Ϣ
			int len = recv(client, buf, maxlen, 0);
			std::string s(buf);
			if (s.compare("exit") == 0) {
				std::cout << "���յ��ر���Ϣ���رշ�����" << std::endl;
				break;
			}
			std::cout << s << " " << len << std::endl;

		}
		closesocket(client);
	}

	/*
	�ļ�����
	*/
	void f_fileTransfer_send() {
		std::ifstream infile;

		SOCKET client = accept(servSock, (sockaddr*)&clntAddr, &nSize);
		
		//��ȡ
		do {
			//���ջ�ȡ���ļ���
			recv(client, buf, maxlen, 0);
			std::cout << buf << std::endl;
			//���ļ�
			infile.open(buf, std::ios::binary | std::ios::in);
			if (infile.is_open()) {
				break;
			}
			else {
				std::cout << "�ļ���ʧ��" << std::endl;
				send(client, "False", 6, 0);
			}
		} while (1);
		


		if (infile.is_open()) {
			//���ļ��ɹ���֪ͨ�ͻ��˽����ļ�
			send(client, "True", 5, 0);
			std::cout << "׼�������ļ�" << std::endl;
			int num = 0;
			//��ȡ�ļ��Ĵ�С
			infile.seekg(0, std::ios::end);
			int length = infile.tellg();

			//�����ļ�ָ���ڵ�һ��λ��
			infile.seekg(std::ios::beg);
			//ѭ����ȡ
			while (length > 0) {
				std::cout << "���ڷ����ļ�" << buf << "��Ŀǰ��ʣ��" << length << "�ֽ�" << std::endl;
				memset(&buf, maxlen, 0);
				//��ȡ����
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
				//��������
				send(client, buf, num, 0);
			}	
		}	
		else {
			std::cout << "�ļ���ʧ�ܣ������ر�" << std::endl;
		}
		//���ͶϿ�������Ϣ
		shutdown(client, SD_SEND);

		//�ر��ļ����׽���
		infile.close();
		closesocket(client);
	}
};


int main()
{


	//�����׽���
	//PF_INET AF_INET ʹ��ipv4
	//SOCK_STREAM ʹ���������Ӵ��䷽ʽ
	//IPPROTO_TCP ʹ��TCPЭ��
	myServSOCKET mysock;


	//mysock.f_allRecv();
	//mysock.f_visioPacket_Recv();
	mysock.f_fileTransfer_send();
	
	return 0;
}




