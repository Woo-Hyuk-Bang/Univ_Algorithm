/*
240111 6번문제 퀵 정렬
10-11주차 pdf 참조

평균적으로 수행속도가 빠른 방법으로 사용됨
기본 정렬
제어 값을 중심으로 두개의 데이터 집합으로 분할한다.



*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void insertion_string(char a[][10], int n);
//////////////////////////////////////////////////////////////////////////////////////////////////

main()
{
	char list[][10] = { "name", "is", "woo", "hyuk","my" };
	int i, n;

	n = sizeof(list) / sizeof(list[0]);
	insertion_string(list, n);

	printf("정렬된 데이터 리스트 : \n");
	for (i = 0; i < n; i++) {
		printf("%s ", list[i]);
	}

}

void insertion_string(char a[][10], int n) {
	int i, j;
	char idata[10];
	for (i = 1; i <= n - 1; i++) {
		strcpy(idata, a[i]);
		j = i - 1;
		while (strcmp(a[j], idata) > 0 && j >= 0) {
			strcpy(a[j + 1], a[j]); j--;
		}
		strcpy(a[j + 1], idata);
 	}
}