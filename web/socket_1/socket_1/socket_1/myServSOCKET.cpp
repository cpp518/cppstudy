#include "stdafx.h"
#include "myServSOCKET.h"
#pragma comment (lib,"ws2_32.lib") //��̬����ws2_32.lib
#define _WINSOCK_DEPRECATED_NO_WARNINGS

myServSOCKET::myServSOCKET(std::string input_type) :type(input_type) {
	//MAKEWORD ��2��byte�ͺϳ�1��16λ���޷����ͣ���һ������Ϊ��8λ��ֵ���ڶ�������Ϊ��8λ��ֵ
	WSAStartup(MAKEWORD(2, 2), &wsadata);  //˵��ʹ��winsocket�汾��Ϊ2.2
	if (type.compare("tcp") == 0) {
		f_tcp_CreateSocket();
	}
	else if (type.compare("udp") == 0) {
		f_udp_CreateSocket();
	}
	f_CreateSocketaddr();

}
myServSOCKET::~myServSOCKET() {
	std::cout << "�������ѹر�" << std::endl;
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
	memset(&sockAddr, 0, sizeof(sockAddr));//��ʼ��
	sockAddr.sin_family = AF_INET;         //ͬ�ϣ���ʹ��ipv4
	inet_pton(AF_INET,"127.0.0.1", &sockAddr.sin_addr.s_addr); //˵��Ҫ������ip��ַ
	sockAddr.sin_port = htons(9000);  //˵��Ҫ�����Ķ˿ں�
									  //IP�Ͷ˿����׽��ְ�����������sockAddr���õ�ip��ַ�Ͷ˿ں�
	bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	std::cout << "��������ʼ������" << std::endl;

	if (type.compare("tcp") == 0) {
		//�������״̬,�����׽��֣�20�ǻ���������
		listen(servSock, 20);
	}
	else if (type.compare("udp") == 0) {
		;
	}

}

/*
һֱ���տͻ��˷��͵���Ϣ��ֱ������exit
*/
void myServSOCKET::f_tcp_allRecv() {

	memset(&clntAddr, sizeof(SOCKADDR), 0);
	//ʹ��accept���ص��׽���clntSock������Ӧ�Ŀͻ��˽��н���������Ӧ�ͻ��˵�connect
	SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
	while (1) {
		//���ܿͻ�������


		//ȷ���յ����ݵĳ���
		int len = recv(clntSock, buf, maxlen, 0);
		std::string s(buf);
		if (s.compare("exit") == 0) {
			std::cout << "���յ��ر���Ϣ���رշ�����" << std::endl;
			break;
		}
		std::cout << s << std::endl;
		//std::cout <<clntAddr.sin_addr.s_addr<<" "<< 
		//char *str = "HelloWorld!";
		//ʹ�øĳ���
		//send(clntSock, buf,len, NULL);

	}
	//�ر��׽���
	closesocket(clntSock);

}
/*
ճ��չʾ
*/
void myServSOCKET::f_tcp_visioPacket_Recv() {
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
void myServSOCKET::f_tcp_fileTransfer_send() {
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
			std::cout << "���ڷ����ļ���Ŀǰ��ʣ��" << length << "�ֽ�" << std::endl;
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

/*
udpģʽ����
*/
void myServSOCKET::f_udp_recv() {
	while (1) {
		//udp������Ϣ
		int recvlen = recvfrom(servSock, buf, readlen, 0, (sockaddr*)&clntAddr, &nSize);
		if (strcmp(buf, "exit") == 0) {
			break;
		}
		std::cout << clntAddr.sin_port << " " << "�յ�����Ϣ�ǣ�" << buf << std::endl;
		//�����յ����ݴ���һ�£��ٷ���ȥ
		buf[recvlen / 2] = 0;
		sendto(servSock, buf, recvlen, 0, (sockaddr*)&clntAddr, nSize);
	}

}