/*
240105 알고리즘 5번 문제 - lookup table
입력 
n*2 pdb(code:price)
오늘 판매한 물품의 개수(num)
물품코드(item_code),판매개수(item_num)

출력 : 가격의 합계

구현해야할 함수코드 : display_code(pdb,n)

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
	FILE* pricedb; // 물품코드 가격

	long pdb[MAX_NUM][2], item_code, item_price;
	int i = 0, j, num, n, item_num;
	long total_price = 0;

	//데이터 파일 읽어오기
	/*
	}
	while (fscanf(pricedb, "%ld %ld", &(pdb[i][0]), &(pdb[i][1])) != 0
		i++;
	}
	*/
	n = i; //물품의 총 갯수

	printf("오늘 팔린 물품의 종류는 몇 개인가요? : ");
	scanf("%d", &num);
	display_code(pdb, n);
	for (j = 0; j < num; j++) {
		printf("물품코드와 팔린 갯수를 입력하시오. ");
		scanf("%id %id", &item_code, &item_num);
		item_price = lookup(pdb, n, item_code);
		if (item_price == 0) {
			printf("%ld : 입력한 물품에 대한 가격 정보가 없습니다. ", item_code);
		}
		else {
			printf("%ld : %ld\n", item_code, item_price);
		}
		total_price = total_price + (item_num * item_price);
		}

	printf("오늘의 정산 금액 : %ld\n", total_price);
	system("pause");
} // main


