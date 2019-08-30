// socket_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "myServSOCKET.h"


int main()
{


	//创建套接字
	//PF_INET AF_INET 使用ipv4
	//SOCK_STREAM 使用面向连接传输方式
	//IPPROTO_TCP 使用TCP协议
	//myServSOCKET mysock("tcp");
	myServSOCKET mysock("udp");
	
	//mysock.f_tcp_allRecv();
	//mysock.f_tcp_visioPacket_Recv();
	//mysock.f_tcp_solveVisioPacket_Recv();
	//mysock.f_tcp_fileTransfer_send();
	mysock.f_udp_recv();
	return 0;
}




