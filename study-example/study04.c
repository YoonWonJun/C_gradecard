/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

boolean leapyear(int year); 

int main(void)
{	
	int standardYear = 1200;
	int Days = 0;
	int inputYear = 0;

	printf("Year >>> ");
	scanf("%d", &inputYear);

	for (int i = standardYear; i < inputYear; i++)
	{
		if (leapyear(i))
		{
			Days += 366;
		}
		else
		{
			Days += 365;
		}
	}
	printf("%d\n", Days);

	system("pause");
	return 0;
}

boolean leapyear(int year)
{
	if ((year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}*/