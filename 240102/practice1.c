/*
240102 �˰��� 3�� ����
n���� �л��� ������ ����� ���Ͻÿ�(�ּ� 10�� �̻�)
�Է� : data(10), avg
��� : avg���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sn;
int score;
int sum;
float avg;

void main() {
	printf("�л� ���� �Է����ּ���\n");
	scanf(" %d", &sn);
	printf("�л��� ������ �Է����ּ���\n");
	sum = 0;
	avg = 0;

	for (int i=1; i <=sn; i++) {
		printf("�л� %d�� ���� :", i);
		scanf(" %d", &score);
		sum = sum + score;
	}

	avg = sum / sn;

	printf("�л����� ����� %f\n�Դϴ�!",avg);
}
