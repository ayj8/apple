#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void tak();
void pro();
void inq();
int seats[11] = { 0 };   //1차원 배열 초기화
int mc = 99;  //전역변수 초기화
int d = 0;   //전역변수 초기화

int NUM[5][5] = { 0 };  //2차원 배열 초기화


int main(void)
{
	int n;
	while (1)  //반복문 while, ()에 1이 들어가 있어 계속 반복
	{
		printf("[[MENU]]\n");
		printf("1. 성적 입력\n");
		printf("2. 성적 처리\n");
		printf("3. 성적 조회\n");
		printf("4. 종료\n");
		printf("메뉴 선택:");
		scanf("%d", &n);    //정수 입력
		switch (n)   //switch문
		{
		case 1:
			tak();  //함수 tak로 이동
			break;  //중요, break가 없으면 case2로 넘어감
		case 2:
			pro();  //함수 pro로 이동
			break;
		case 3:
			inq();  //함수 inq로 이동
			break;
		case 4:
			return 0;   //프로그램 종료
		}

	}
}


void tak()
{
	int a, i;
	if (d > 4)   //d가 4보다 큰 경우
	{
		printf("더 이상 입력할 데이터가 없습니다\n");
		return;    //switch문으로 돌아감
	}
	printf("역사 점수: ");
	scanf("%d", &NUM[d][1]);   //d행 1열에 정수 저장
	printf("과학 점수: ");
	scanf("%d", &NUM[d][2]);   //d행 2열에 정수 저장

	srand(time(NULL));
	do {
		a = rand() % 10 + 1;   //1에서 10까지 수 중에 임의로 발생되어 a에 저장
	} while (seats[a] == 1);   //seats[a]가 1이 아니면 빠져나옴
	seats[a] = 1;
	NUM[d][0] = a;
	d++;  //전역변수로 위에 정의되어서 계속 사용 가능
	
	for (int i = 0; i < d; i++)  //i가 d보다 작은 동안 반복
	{
		NUM[i][3] = NUM[i][1] + NUM[i][2];
	}
	
	for (int i = 0; i < d; i++)
	{
		NUM[i][4] = (double)NUM[i][3] / 2;
	}
}

void pro()
{

	double avg = 0;
	double re_1 = 0;
	double re_2;
	if (d == 0)
	{
		printf("처리할 성적이 없습니다\n");
		return;    //switch문으로 돌아감
	}
	
	int tot = 0;
	for (int i = 0; i < d; i++)
		avg += (double)NUM[i][4] / d;   

	for (int i = 0; i < d; i++)
		re_1 += (double)((avg - NUM[i][4]) * (avg - NUM[i][4])) /d;

	re_2 = sqrt(re_1);    //루트값을 구함
	printf("전체 평균: %lf  표준편차: %lf", avg, re_2);

}

void inq()
{
	if (d == 0)
	{
		printf("조회할 데이터가 없습니다");
		return;    //switch문으로 돌아감
	}
	printf("번호 \t 역사 \t 과학 \t 합계 \t 평균\n");
	for (int i = 0; i < d; i++)
	{
		printf("%d \t %d \t %d \t %d \t %d \n", NUM[i][0], NUM[i][1], NUM[i][2], NUM[i][3], NUM[i][4]);
	}

}