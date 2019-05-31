#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

#define ClassNumberSize 8	// 7자리의 학번 입력가능
#define NameSize 9			// 최대 4글자 이름입력가능
#define PeopleNumber 2		// N명의 데이터 입력

typedef struct Sexual
{
	char classNumber[ClassNumberSize];	// 학번
	char name[NameSize];				// 이름
	int middleScore;					// 중간고사 점수
	int finalScore;						// 기말고사 점수
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

void MemoryAllowcate(Sexual * sexual[])	// 성적종합 구조체 동적메모리 할당 함수
{
	for (int i = 0; i < PeopleNumber; i++)
	{
		sexual[i] = (Sexual *)malloc(sizeof(Sexual));
	}
}

void InputScore(Sexual * sexual[])	// N명의 데이터 입력 함수
{
	for (int i = 0; i < PeopleNumber; i++)
	{
		printf("*** %d번째 ***\n", i+1);
		printf("학 번 : ");
		scanf("%s", sexual[i]->classNumber);
		printf("이 름 : ");
		scanf("%s", sexual[i]->name);
		printf("중간고사 : ");
		scanf("%d", &sexual[i]->middleScore);
		printf("기말고사 : ");
		scanf("%d", &sexual[i]->finalScore);
		printf("\n");
	}
}

void PrintScore(Sexual * sexual[]) // 입력된 데이터 출력 함수
{
	int rowScoreSum[PeopleNumber];			// 한 행의 중간고사 합
	double rowScoreAvg[PeopleNumber];		// 한 행의 기말고사 합
	char * rowScoreRating[PeopleNumber];	// 한 행의 등급

	int totalMiddleScore = 0;				// 열의 중간고사 합
	int totalFinalScore = 0;				// 열의 기말고사 합
	int totalSum = 0;						// 열의 모든 성적의 합
	double totalAvg = 0.0;					// 열의 모든 평균의 합

	for (int i = 0; i < PeopleNumber; i++)									// 행과 관련된 연산을 반복
	{
		rowScoreSum[i] = sexual[i]->middleScore + sexual[i]->finalScore;	// 행의 중간고사, 기말고사의 합 (i=0일때는 첫 번째로 입력한 성적의 합)
		rowScoreAvg[i] = rowScoreSum[i] / 2;								// 행의 중간고사, 기말고사의 평균 (i=0일때는 첫 번째로 입력한 성적의 평균)
		if (rowScoreAvg[i] >= 90)											// 조건을 비교하며 등급을 매김 (i=0일때는 첫 번째 데이터의 평균이 조건)
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
	for (int i = 0; i < PeopleNumber; i++)									// 열과 관련된 연산을 반복
	{
		totalMiddleScore += sexual[i]->middleScore;							// 모든 중간고사 열의 합
		totalFinalScore += sexual[i]->finalScore;							// 모든 기말고사 열의 합
		totalSum += rowScoreSum[i];											// 모든 성적의 합
		totalAvg += rowScoreAvg[i];											// 모든 평균의 합
	}

	printf("\n\n\t\t\t*** 성적표 ***\n\n");
	printf("========================================================\n");
	printf("학번\t성명\t중간\t기말\t합\t평균\t등급\n");
	printf("--------------------------------------------------------\n");
	for (int i = 0; i < PeopleNumber; i++)									// N번 반복하며 구조체에 저장된 데이터를 출력
	{
		printf("%s\t%s\t%d\t%d\t%d\t%.2lf\t%s\n", sexual[i]->classNumber, sexual[i]->name, sexual[i]->middleScore, sexual[i]->finalScore,
			rowScoreSum[i], rowScoreAvg[i], rowScoreRating[i]);
	}
	printf("--------------------------------------------------------\n");
	printf("\t합계\t%d\t%d\t%d\t%.2lf\n", totalMiddleScore, totalFinalScore, totalSum, totalAvg);
	printf("========================================================\n");

}

void MemoryFree(Sexual * sexual[])	// 동적할당된 메모리해제 함수
{
	for (int i = 0; i < PeopleNumber; i++)
	{
		free(sexual[i]);
	}
}