#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void tak();
void pro();
void inq();
int seats[11] = { 0 };   //1���� �迭 �ʱ�ȭ
int mc = 99;  //�������� �ʱ�ȭ
int d = 0;   //�������� �ʱ�ȭ

int NUM[5][5] = { 0 };  //2���� �迭 �ʱ�ȭ


int main(void)
{
	int n;
	while (1)  //�ݺ��� while, ()�� 1�� �� �־� ��� �ݺ�
	{
		printf("[[MENU]]\n");
		printf("1. ���� �Է�\n");
		printf("2. ���� ó��\n");
		printf("3. ���� ��ȸ\n");
		printf("4. ����\n");
		printf("�޴� ����:");
		scanf("%d", &n);    //���� �Է�
		switch (n)   //switch��
		{
		case 1:
			tak();  //�Լ� tak�� �̵�
			break;  //�߿�, break�� ������ case2�� �Ѿ
		case 2:
			pro();  //�Լ� pro�� �̵�
			break;
		case 3:
			inq();  //�Լ� inq�� �̵�
			break;
		case 4:
			return 0;   //���α׷� ����
		}

	}
}


void tak()
{
	int a, i;
	if (d > 4)   //d�� 4���� ū ���
	{
		printf("�� �̻� �Է��� �����Ͱ� �����ϴ�\n");
		return;    //switch������ ���ư�
	}
	printf("���� ����: ");
	scanf("%d", &NUM[d][1]);   //d�� 1���� ���� ����
	printf("���� ����: ");
	scanf("%d", &NUM[d][2]);   //d�� 2���� ���� ����

	srand(time(NULL));
	do {
		a = rand() % 10 + 1;   //1���� 10���� �� �߿� ���Ƿ� �߻��Ǿ� a�� ����
	} while (seats[a] == 1);   //seats[a]�� 1�� �ƴϸ� ��������
	seats[a] = 1;
	NUM[d][0] = a;
	d++;  //���������� ���� ���ǵǾ ��� ��� ����
	
	for (int i = 0; i < d; i++)  //i�� d���� ���� ���� �ݺ�
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
		printf("ó���� ������ �����ϴ�\n");
		return;    //switch������ ���ư�
	}
	
	int tot = 0;
	for (int i = 0; i < d; i++)
		avg += (double)NUM[i][4] / d;   

	for (int i = 0; i < d; i++)
		re_1 += (double)((avg - NUM[i][4]) * (avg - NUM[i][4])) /d;

	re_2 = sqrt(re_1);    //��Ʈ���� ����
	printf("��ü ���: %lf  ǥ������: %lf", avg, re_2);

}

void inq()
{
	if (d == 0)
	{
		printf("��ȸ�� �����Ͱ� �����ϴ�");
		return;    //switch������ ���ư�
	}
	printf("��ȣ \t ���� \t ���� \t �հ� \t ���\n");
	for (int i = 0; i < d; i++)
	{
		printf("%d \t %d \t %d \t %d \t %d \n", NUM[i][0], NUM[i][1], NUM[i][2], NUM[i][3], NUM[i][4]);
	}

}