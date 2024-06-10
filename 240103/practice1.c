/*
240103 알고리즘 10번 문제
파일 확인
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[])
{
	int a, b, result, answer, correct = 0, i = 0;
	FILE* infile;
	FILE* out;
	if (argc != 3) {
		printf("실행인수를 잘못 주었습니다...\n");
		exit(1);
	}
	
	if ((infile = fopen(argv[1], "r")) == NULL) {
		printf("입력 파일을 열 수 없습니다. \n");
		exit(1);
	}
	
	if ((out = fopen(argv[2], "w")) == NULL) {
		printf("출력 파일을 만들 수 없습니다. \n");
		exit(1);
	}

	while (fscanf(infile, "%d %d", &a, &b) != EOF) {
		printf("%d : gcd(&d, &d) = ", i + 1, a, b);
		scanf("%d", &answer);
		result = gcd(a, b);
		if (answer != result)
		{
			printf("Answer : gcd(%d, %d) = %d \n",a,b,result);
			fprintf(out, "%d %d \n", a, b);
		}
		else {
			printf("Correct...\n");
			correct++;
		}
		i++;
	}

	printf("%d 문제 중에 %d 문제 통과하셨습니다...\n,i,correct");

}

int gcd(int x, int y) // 재귀적 정의법
{
	if (y == 0)
		return x;
	if (x == 0)
		return y;
	else
		return gcd(y, (x % y));
}

