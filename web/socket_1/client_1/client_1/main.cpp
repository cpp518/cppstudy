// client_1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "myClieSOCKET.h"



int main()
{
	myClieSOCKET mysock;
	//mysock.f_tcp_AllSend();
	//mysock.f_tcp_visiopacket_send(5);
	//mysock.f_udp_send();
	mysock.f_tcp_fileTransfer_recv();
	return 0;
}

