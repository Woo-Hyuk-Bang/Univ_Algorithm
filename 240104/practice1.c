/*
240104 알고리즘 5번 문제 - 계산기 338p
상태도 분석 기법 -> 상태 전이도를 통하여 분석 확장
정수 단순 계산기 프로그램 
stage 1 -> stage 2 -> stage 3
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define STAGE1 0
#define STAGE2 1
#define STAGE3 2

void real_calculator(void);
double real_operation(char op, double operand1, double operand2);
double get_real(double current_operand, char c, int status); // 이해해야하는 중요 함수 - 정수와 실수 부분을 읽기 위한 프로그램
int is_operator(char c);
int is_digit(char c);

double get_real(double current_operand, char c, int status) {


}

void main()
{
	printf("계산기 프로그램을 시작합니다. \n");
	printf("실수형의 피연산자와 사칙연산자 중 하나를 입력하십시오. \n");
	real_calculator();
	printf("\n계산기 프로그램을 종료합니다. \n");
}
int is_operator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	else
		return 0;
}

int is_digit(char c) {
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}

void real_calculator(void)
{
	double operand1 = 0, operand2 = 0, result;
	char op, c;
	int current_stage = STAGE1, status = 0;
	while ((c = getchar()) != 'x') {
		if (current_stage == STAGE1) {
			if (is_digit(c)) {
				operand1 = get_real(operand1, c, status);
				if (status != 0) status++;
			}

			else if (is_operator(c)) {
				op = c;
				current_stage = STAGE2;
				status = 0;
				operand2 = 0;
			}
			else if (c == '.') status = 1;
		}	// STAGE 1

		else if (current_stage == STAGE2) {
			if (is_digit(c)) {
				operand2 = get_real(operand2, c, status);
				if (status != 0) status++;
			}
			else if (c == '.') status = 1;
			else if (c == '\n') { // 중요부분
				result = real_operation(op, operand1, operand2);
				printf("= %.3f", result);
				current_stage = STAGE3;
				status = 0;
			}
		} //STAGE2

		else if (current_stage == STAGE3) {
			if (c == '\n') {
				operand1 = 0;
				current_stage = STAGE1;
			}
			else if (is_operator(c)) {
				op = c;
				current_stage = STAGE2;
			}
		}
	}
}

double real_operation(char op, double operand1, double operand2) 
{
	double result;
	switch (op) {
	case '+' :
		result = operand1 + operand2;
		break;
	case '-':
		result = operand1 - operand2;
		break;
	case '*':
		result = operand1 * operand2;
		break;
	case '/':
		if (operand2 !=0) result = operand1 / operand2;
		break;
	}
	return result;
}

