#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
#include <stdbool.h>

int umn (int number1, int number2)
{
	return number1*number2;
}

int del (int number1, int number2)
{
	return number1/number2;
}

int minus (int number1, int number2)
{
    return number1-number2;
}

int plus(int number1, int number2)
{
    return number1+number2;
}


int main()
{
    int number1 = 0;
    int number2 = 0;
    int temp = 0;
    printf("Enter size for number1\n");
    scanf("%d", &number1);
    printf("Enter size for number2\n");
    scanf("%d", &number2);

    int(*Pumn)(int, int) = &umn;
    int(*Pdel)(int, int) = &del;
    int(*Pminus)(int, int) = &minus;
    int(*Pplus)(int, int) = &plus;
    int calc[4] = {*Pumn, *Pdel, *Pminus, *Pplus};
    printf("Для умножения 1, для деления 2, для вычитания 3, для сложения 4\n");
    scanf("%d", &temp);
    int result = calc[temp];
    printf("%d", result);

	return 0;
}