#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

#define ClassNumberSize 8	// 7�ڸ��� �й� �Է°���
#define NameSize 9			// �ִ� 4���� �̸��Է°���
#define PeopleNumber 2		// N���� ������ �Է�

typedef struct Sexual
{
	char classNumber[ClassNumberSize];	// �й�
	char name[NameSize];				// �̸�
	int middleScore;					// �߰���� ����
	int finalScore;						// �⸻��� ����
}Sexual;

void loop();
void MemoryAllowcate(Sexual * sexual[]);
void InputScore(Sexual * sexual[]);
void PrintScore(Sexual * sexual[]);
void MemoryFree(Sexual * sexual[]);

int main(void)
{
	loop();
	system("pause");

	return 0;
}

void loop()
{
	Sexual * sexual[PeopleNumber];

	MemoryAllowcate(sexual);

	InputScore(sexual);

	PrintScore(sexual);

	MemoryFree(sexual);
}

void MemoryAllowcate(Sexual * sexual[])	// �������� ����ü �����޸� �Ҵ� �Լ�
{
	for (int i = 0; i < PeopleNumber; i++)
	{
		sexual[i] = (Sexual *)malloc(sizeof(Sexual));
	}
}

void InputScore(Sexual * sexual[])	// N���� ������ �Է� �Լ�
{
	for (int i = 0; i < PeopleNumber; i++)
	{
		printf("*** %d��° ***\n", i+1);
		printf("�� �� : ");
		scanf("%s", sexual[i]->classNumber);
		printf("�� �� : ");
		scanf("%s", sexual[i]->name);
		printf("�߰���� : ");
		scanf("%d", &sexual[i]->middleScore);
		printf("�⸻��� : ");
		scanf("%d", &sexual[i]->finalScore);
		printf("\n");
	}
}

void PrintScore(Sexual * sexual[]) // �Էµ� ������ ��� �Լ�
{
	int rowScoreSum[PeopleNumber];			// �� ���� �߰���� ��
	double rowScoreAvg[PeopleNumber];		// �� ���� �⸻��� ��
	char * rowScoreRating[PeopleNumber];	// �� ���� ���

	int totalMiddleScore = 0;				// ���� �߰���� ��
	int totalFinalScore = 0;				// ���� �⸻��� ��
	int totalSum = 0;						// ���� ��� ������ ��
	double totalAvg = 0.0;					// ���� ��� ����� ��

	for (int i = 0; i < PeopleNumber; i++)									// ��� ���õ� ������ �ݺ�
	{
		rowScoreSum[i] = sexual[i]->middleScore + sexual[i]->finalScore;	// ���� �߰����, �⸻����� �� (i=0�϶��� ù ��°�� �Է��� ������ ��)
		rowScoreAvg[i] = rowScoreSum[i] / 2;								// ���� �߰����, �⸻����� ��� (i=0�϶��� ù ��°�� �Է��� ������ ���)
		if (rowScoreAvg[i] >= 90)											// ������ ���ϸ� ����� �ű� (i=0�϶��� ù ��° �������� ����� ����)
		{
			rowScoreRating[i] = "A+";
		}
		else if (rowScoreAvg[i] < 90 && rowScoreAvg[i] >= 85)
		{
			rowScoreRating[i] = "A0";
		}
		else if (rowScoreAvg[i] < 85 && rowScoreAvg[i] >= 80)
		{
			rowScoreRating[i] = "B+";
		}
		else if (rowScoreAvg[i] < 80 && rowScoreAvg[i] >= 75)
		{
			rowScoreRating[i] = "B0";
		}
		else if (rowScoreAvg[i] < 75 && rowScoreAvg[i] >= 70)
		{
			rowScoreRating[i] = "C+";
		}
		else if (rowScoreAvg[i] < 70 && rowScoreAvg[i] >= 65)
		{
			rowScoreRating[i] = "C0";
		}
		else if (rowScoreAvg[i] < 65 && rowScoreAvg[i] >= 60)
		{
			rowScoreRating[i] = "D+";
		}
		else if (rowScoreAvg[i] < 60 && rowScoreAvg[i] >= 55)
		{
			rowScoreRating[i] = "D0";
		}
		else
		{
			rowScoreRating[i] = "F";
		}
	}
	for (int i = 0; i < PeopleNumber; i++)									// ���� ���õ� ������ �ݺ�
	{
		totalMiddleScore += sexual[i]->middleScore;							// ��� �߰���� ���� ��
		totalFinalScore += sexual[i]->finalScore;							// ��� �⸻��� ���� ��
		totalSum += rowScoreSum[i];											// ��� ������ ��
		totalAvg += rowScoreAvg[i];											// ��� ����� ��
	}

	printf("\n\n\t\t\t*** ����ǥ ***\n\n");
	printf("========================================================\n");
	printf("�й�\t����\t�߰�\t�⸻\t��\t���\t���\n");
	printf("--------------------------------------------------------\n");
	for (int i = 0; i < PeopleNumber; i++)									// N�� �ݺ��ϸ� ����ü�� ����� �����͸� ���
	{
		printf("%s\t%s\t%d\t%d\t%d\t%.2lf\t%s\n", sexual[i]->classNumber, sexual[i]->name, sexual[i]->middleScore, sexual[i]->finalScore,
			rowScoreSum[i], rowScoreAvg[i], rowScoreRating[i]);
	}
	printf("--------------------------------------------------------\n");
	printf("\t�հ�\t%d\t%d\t%d\t%.2lf\n", totalMiddleScore, totalFinalScore, totalSum, totalAvg);
	printf("========================================================\n");

}

void MemoryFree(Sexual * sexual[])	// �����Ҵ�� �޸����� �Լ�
{
	for (int i = 0; i < PeopleNumber; i++)
	{
		free(sexual[i]);
	}
}