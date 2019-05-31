/*
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct score {
	int kor;
	int eng;
}score;

score * return_score();

int main(void)
{
	score * sc;

	sc = return_score();

	printf("국어 : %d 영어 : %d", sc->kor, sc->eng);

	free(sc);

	system("pause");
	return 0;
}

score * return_score()
{
	score * sc = (score*)malloc(sizeof(score));
	sc->kor = 90;
	sc->eng = 100;

	return sc;
}
*/