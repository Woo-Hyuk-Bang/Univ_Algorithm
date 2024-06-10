/*
240102 알고리즘 3번 문제
n명의 학생의 성적의 평균을 구하시오(최소 10명 이상)
입력 : data(10), avg
결과 : avg출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sn;
int score;
int sum;
float avg;

void main() {
	printf("학생 수를 입력해주세요\n");
	scanf(" %d", &sn);
	printf("학생의 성적을 입력해주세요\n");
	sum = 0;
	avg = 0;

	for (int i=1; i <=sn; i++) {
		printf("학생 %d의 성적 :", i);
		scanf(" %d", &score);
		sum = sum + score;
	}

	avg = sum / sn;

	printf("학생들의 평균은 %f\n입니다!",avg);
}
