/*
#include <stdio.h>
#include <Windows.h>

#define ME 1
#define INCH 2
#define YA 3
#define FT 4

int main(void)
{
	int m_Previous;
	int m_After;
	double Previous;
	double After;
	printf("[1] ����(m), [2] ��ġ, [3] �ߵ�(ya) [4] ��Ʈ(ft) [0] ����\n");
	printf("[��������] ---> [��ȯ����], �� ���� �޴� ��ȣ�� �����ϼ���. >> ");
	scanf_s("%d %d", &m_Previous, &m_After);
	while (1)
	{
		printf("[��ȯ�� ����]�� ���̸� �Է��ϼ���. >> ");
		scanf_s("%lf", &Previous);
		if (Previous == 0)
		{
			break;
		}
		if (m_Previous == ME)
		{
			if (m_After == INCH)
			{
				After = (Previous / 2.54) * 100;
				printf("%.6lf(m) -> %.6lf(in)\n", Previous, After);
			}
			else if (m_After == YA)
			{
				After = (Previous / 91.44) * 100;
				printf("%.6lf(m) -> %.6lf(ya)\n", Previous, After);
			}
			else if (m_After == FT)
			{
				After = (Previous / 30.48) * 100;
				printf("%.6lf(m) -> %.6lf(ft)\n", Previous, After);
			}
		}
		else if (m_Previous == INCH)
		{
			if (m_After == ME)
			{
				After = (Previous * 2.54) / 100;
				printf("%.6lf(in) -> %.6lf(m)\n", Previous, After);
			}
			else if (m_After == YA)
			{
				After = (Previous / 36);
				printf("%.6lf(in) -> %.6lf(ya)\n", Previous, After);
			}
			else if (m_After == FT)
			{
				After = (Previous / 12);
				printf("%.6lf(in) -> %.6lf(ft)\n", Previous, After);
			}
		}
		else if (m_Previous == YA)
		{
			if (m_After == INCH)
			{
				After = (Previous * 36);
				printf("%.6lf(ya) -> %.6lf(in)\n", Previous, After);
			}
			else if (m_After == ME)
			{
				After = (Previous * 91.44);
				printf("%.6lf(ya) -> %.6lf(m)\n", Previous, After);
			}
			else if (m_After == FT)
			{
				After = (Previous * 3);
				printf("%.6lf(ya) -> %.6lf(ft)\n", Previous, After);
			}
		}
		else if (m_Previous == FT)
		{
			if (m_After == INCH)
			{
				After = (Previous * 12);
				printf("%.6lf(ft) -> %.6lf(in)\n", Previous, After);
			}
			else if (m_After == YA)
			{
				After = (Previous / 3);
				printf("%.6lf(ft) -> %.6lf(ya)\n", Previous, After);
			}
			else if (m_After == ME)
			{
				After = (Previous * 30.48) / 100;
				printf("%.6lf(ft) -> %.6lf(m)\n", Previous, After);
			}
		}
		else if (Previous == 0.0)
		{
			break;
		}
	}
	printf("����\n");
	system("pause");
	return 0;
}
*/