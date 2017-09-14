#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
#include <stdbool.h>

int umn(int number1, int number2)
{
	return number1 * number2;
}

int del(int number1, int number2)
{
	return number1 / number2;
}

int minus(int number1, int number2)
{
	return number1 - number2;
}

int plus(int number1, int number2)
{
	return number1 + number2;
}


int main()
{
	int number1 = 0;
	int number2 = 0;
	int temp = 0;
	printf("Enter size for number1\n");
	scanf_s("%d", &number1);
	printf("Enter size for number2\n");
	scanf_s("%d", &number2);

	int(*Pumn)(int, int) = umn;
	int(*Pdel)(int, int) = del;
	int(*Pminus)(int, int) = minus;
	int(*Pplus)(int, int) = plus;
	int(*calc[4])(int, int) = {Pumn, Pdel, Pminus, Pplus};

/*	calc[0] = *Pumn;
	calc[1] = *Pdel;
	calc[2] = *Pminus;
	calc[3] = *Pplus;
*/
	printf("*(0), /(1), -(2), +(3)\n");
	scanf_s("%d", &temp);
	int result = calc[temp](number1, number2);

	printf("%d", result);
	system("Pause");
	return 0;
}