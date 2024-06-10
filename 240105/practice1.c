/*
240105 �˰��� 5�� ���� - lookup table
�Է� 
n*2 pdb(code:price)
���� �Ǹ��� ��ǰ�� ����(num)
��ǰ�ڵ�(item_code),�ǸŰ���(item_num)

��� : ������ �հ�

�����ؾ��� �Լ��ڵ� : display_code(pdb,n)

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 50

//////////////////////////////////////////////////////////////////////////////////////////////////

long lookup(long pdb[][2], int n, long item_code);
long display_code(long pdb[][2], int n);

long lookup(long pdb[][2], int n, long item_code) {
	int i;

	for (i = 0; i < n; i++) {
		if (pdb[i][0] == item_code) return pdb[i][1];
	}
	return 0;
}


long display_code(long pdb[][2], int n) {
	int i;

	for (i = 0; i < n; i++) {
		printf("&ld &ld\n", pdb[i][0], pdb[i][1]);
	}
	return 0;
}

int main(int argc, char* argv[]) {
	FILE* pricedb; // ��ǰ�ڵ� ����

	long pdb[MAX_NUM][2], item_code, item_price;
	int i = 0, j, num, n, item_num;
	long total_price = 0;

	//������ ���� �о����
	/*
	}
	while (fscanf(pricedb, "%ld %ld", &(pdb[i][0]), &(pdb[i][1])) != 0
		i++;
	}
	*/
	n = i; //��ǰ�� �� ����

	printf("���� �ȸ� ��ǰ�� ������ �� ���ΰ���? : ");
	scanf("%d", &num);
	display_code(pdb, n);
	for (j = 0; j < num; j++) {
		printf("��ǰ�ڵ�� �ȸ� ������ �Է��Ͻÿ�. ");
		scanf("%id %id", &item_code, &item_num);
		item_price = lookup(pdb, n, item_code);
		if (item_price == 0) {
			printf("%ld : �Է��� ��ǰ�� ���� ���� ������ �����ϴ�. ", item_code);
		}
		else {
			printf("%ld : %ld\n", item_code, item_price);
		}
		total_price = total_price + (item_num * item_price);
		}

	printf("������ ���� �ݾ� : %ld\n", total_price);
	system("pause");
} // main


