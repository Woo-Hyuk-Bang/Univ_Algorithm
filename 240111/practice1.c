/*
240111 6������ �� ����
10-11���� pdf ����

��������� ����ӵ��� ���� ������� ����
�⺻ ����
���� ���� �߽����� �ΰ��� ������ �������� �����Ѵ�.



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

	printf("���ĵ� ������ ����Ʈ : \n");
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