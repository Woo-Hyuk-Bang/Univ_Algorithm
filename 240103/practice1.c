/*
240103 �˰����� 10�� ����
���� Ȯ��
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
		printf("�����μ��� �߸� �־����ϴ�...\n");
		exit(1);
	}
	
	if ((infile = fopen(argv[1], "r")) == NULL) {
		printf("�Է� ������ �� �� �����ϴ�. \n");
		exit(1);
	}
	
	if ((out = fopen(argv[2], "w")) == NULL) {
		printf("��� ������ ���� �� �����ϴ�. \n");
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

	printf("%d ���� �߿� %d ���� ����ϼ̽��ϴ�...\n,i,correct");

}

int gcd(int x, int y) // ����� ���ǹ�
{
	if (y == 0)
		return x;
	if (x == 0)
		return y;
	else
		return gcd(y, (x % y));
}
