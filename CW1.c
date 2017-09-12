#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
#include <stdbool.h>

void randomarray(uint64_t size, uint64_t A[])
{
	for (uint64_t st = 0; st < size; st++)
	{
		A[st] = rand() % 100;
	}

}

void print(uint64_t size, uint64_t A[])
{
	for (uint64_t st = 0; st < size; st++)
	{
		printf("%llu ", A[st]);
	}
	printf("\n\n");
}

uint64_t sumcompos(uint64_t* M, uint64_t size, uint64_t* sumu, uint64_t* compositionu)
{
	for (uint64_t sb = 0; sb < size; sb++) 
	{
		{
			*sumu += *(M+sb);
			*compositionu *= *(M + sb);
		}
	}
}

/**
uint64_t notincludeforA(uint64_t size, uint64_t A[size], uint64_t B[size], uint64_t C[size]) //ClassW1
{
	uint64_t sc = 0;
	for (uint64_t sa = 0; sa < size; sa++) //A
	{
		int i = false;
		for (uint64_t sb = 0; sb < size; sb++) //B
		{
			if (A[sa] == B[sb])
			{
				i == true;
				break;
			}
		}
		if (i == false)
		{
			uint64_t temp = 0;
			temp = A[sa];
			for (uint64_t st = 0; st < sc; st++)
			{
				if (temp == C[st])
				{
					i == true;
					break;
				}
			}
			if (i == false)
			{
				C[sc] = temp;
				sc++;
			}
		}
	}
}
*/

int main()
{
	uint64_t size = 0;
	printf("Enter size\n");
	scanf_s("%llu", &size);
	uint64_t A[100];
	srand(time(NULL));
	randomarray(size, A);
	print(size, A);
	uint64_t *M;
	M = A;
	uint64_t sum = 0;
	uint64_t composition = 1;
	uint64_t *sumu;
	uint64_t *compositionu;
	compositionu = &composition;
	sumu = &sum;
	sumcompos(M, size, sumu, compositionu);
	printf("%llu\n%llu\n", sum, composition);
	system("pause");
	return 0;
}