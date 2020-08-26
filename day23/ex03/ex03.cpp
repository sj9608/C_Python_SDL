// ex03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//  ex03_tcp_server.py --> 파이썬 코드 C로 옮기기 (과정의 복잡함 확인차원)

#include <iostream>
#include <winsock.h>

#pragma comment(lib, "ws2_32.lib")


int main()
{
	WSADATA wsaData;
	SOCKET socketCli;
	char szMsg[32];

	struct sockaddr_in addrServer;
	WSAStartup(MAKEWORD(2, 0), &wsaData); // 소켓 객체 받아오기 

	// 소켓 인스턴스 만들기
	socketCli = socket(AF_INET, SOCK_STREAM, 0);

	// 접속할 서버 주소 구조체 만들기
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htonl(8282);
	addrServer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	// 서버에 접속 소켓 객체에 
	printf("connecting server ...\n");
	if(connect(socketCli, (struct sockaddr*)&addrServer, sizeof(addrServer)) == SOCKET_ERROR)
	{
		printf("error code : %s \n", WSAGetLastError());
		return 1;
	}
	printf("connected server");

	send(socketCli, "hello CTP", 10, 0);

	closesocket(socketCli);

	return 0;
}