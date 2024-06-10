/*
240112 3번문제 합병 정렬 10-15
13주차 pdf 참조

정렬된 두 데이터 집합을 하나의 정렬된 데이터집합으로 합병

a1, a2, a의 현재 위치를 나타내는 인덱스를 i,j,k로 지정(이때 초기화 진행) => i=j=k=0

a1[i] <= a2[j]이면 a[k] = a1[i], i++, k++
a1[i] > a2[j]이면 a[k] = a2[j], j++, k++

어느 한 리스트를 다 처리하면 나머지 리스트의 데이터를 복사한다.
a1의 데이터의 수 n1, a2의 데이터의 수를 n2라고 지정
while (j <= n2) a[k]=a2[j], k++, j++
while (i <= n2) a[k]=a1[i], k++, i++


*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void print_list(int *list, int n, char *mesg);
void quick_sort(int a[], int left, int right);
int two_one(int *a1, int *a2, int *a, int n1, int n2);

void main() 
{
	int list1[] = { 32, 15, 20, 50, 40, 10, 25, 30 };
	int list2[] = { 25, 50, 15, 17, 20, 10, 38, 13, 35 };
	int list[100];
	int n1, n2, n;
	char sorted;

	n1 = sizeof(list1) / sizeof(int);
	n2 = sizeof(list2) / sizeof(int);

	print_list(list1, n1, "데이터 리스트 1: \n");
	print_list(list2, n2, "데이터 리스트 2: \n");

	printf("\n 준비된 데이터 리스트1이 정렬되어 있는가? (Y/N)");
	sorted = getche();
	if (sorted == 'n') quick_sort(list1, 0, n1 - 1);

	printf("\n 준비된 데이터 리스트2가 정렬되어 있는가? (Y/N");
	sorted = getche();
	if (sorted == 'n') quick_sort(list2, 0, n2 - 1);
	printf("\n\n");
	n = two_one(list1, list2, list, n1, n2);

	print_list(list, n, "합병된 데이터 리스트: \n");

}

void print_list(int *list, int n, char *mesg)
{
	int i;
	printf(mesg);
	for (i = 0; i < n; i++) {
		printf("%d   ", list[i]);
		if ((i % 10) == 9) printf("\n");
	}
	printf("\n\n");
}

int two_one(int* a1, int* a2, int* a, int n1, int n2)
{
	int i = 0, j = 0, k = 0;

	while (i < n1 && j < n2) {
		if (a1[i] <= a2[j])
			a[k++] = a1[i++];
		else if (a1[i] > a2[j])
			a[k++] = a2[j++];
	}
	
	if (i == n1)
		while (j < n2) a[k++] = a2[j++];

	else
		while (i < n1) a[k++] = a1[i++];
	return k;

}

void quick_sort(int a[], int left, int right) {
	int pivot, i, j, tmp;
	if (left < right) {
		i = left; j = right + 1; pivot = a[left];
		while (i < j) {
			do i++; while ((a[i] < pivot) && (i < right));
			do j--; while ((a[j] > pivot) && (j > left));
			if (i < j) {
				tmp = a[i]; 
				a[i] = a[j]; 
				a[j] = tmp;
			}
		}
		if (j != left) {
			tmp = a[j];
			a[j] = a[left];
			a[left] = tmp;
		}
		quick_sort(a, left, j - 1);
		quick_sort(a, j + 1, right);
	}

}
