// socket_1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "myServSOCKET.h"


int main()
{


	//�����׽���
	//PF_INET AF_INET ʹ��ipv4
	//SOCK_STREAM ʹ���������Ӵ��䷽ʽ
	//IPPROTO_TCP ʹ��TCPЭ��
	myServSOCKET mysock("tcp");


	mysock.f_tcp_allRecv();
	//mysock.f_visioPacket_Recv();
	//mysock.f_fileTransfer_send();
	//mysock.f_udp_recv();
	return 0;
}



