#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
#include <stdbool.h>

void randomarray(int64_t size, int64_t A[])
{
	for (int64_t st = 0; st < size; st++)
	{
		A[st] = rand() % 200-100;
	}

}

void print(int64_t size, int64_t A[])
{
	for (int64_t st = 0; st < size; st++)
	{
		printf("%lli ", A[st]);
	}
	printf("\n\n");
}

int64_t sign(int64_t* M, int64_t size, int64_t* plus, int64_t* minus, int64_t* zero)
{
	for (int64_t sb = 0; sb < size; sb++) 
	{
			if (*(M + sb) > 0)
			{
				(*plus)++;
			}
			else if (*(M + sb) < 0) 
			{
				(*minus)++;
			}
			else if (*(M + sb) == 0)
			{
				(*zero)++;
			}
	}
}

int main()
{
	int64_t size = 0;
	printf("Enter size\n");
	scanf_s("%lli", &size);
	int64_t A[100];
	srand(time(NULL));
	randomarray(size, A);
	print(size, A);
	int64_t *M;
	M = A;
	int64_t plus = 0;
	int64_t minus = 0;
	int64_t zero = 0;
/**
	int64_t *plusu;
	int64_t *minusu;
	int64_t *zerou;
	plusu = &plus;
	minusu = &minus;
	zerou = &zero;
*/
	sign(M, size, &plus, &minus, &zero);
	printf("%lli\n%lli\n%lli\n", plus, minus, zero);
	system("pause");
	return 0;
}