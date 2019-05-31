/*
#include <WinSock2.h>
#include <stdio.h>
#include <Windows.h>
#include <sys/types.h>

struct sockaddr_in {
	unsigned short sa_family;
	char sa_data[14];
};

struct sockaddr {
	short sin_family;
	unsigned short sin_port;
	struct in_addr sin_addr;
	char sin_zero[8];
};
struct in_addr {
	unsigned long s_addr;
};

struct A {
	short num1;
	short num2;
	short num3;
};

struct B {
	short num1;
	char * su;
};

int main(void)
{
	char a = 's';

	printf("%c", a ^ 13);

	system("pause");
	return 0;
}
*/