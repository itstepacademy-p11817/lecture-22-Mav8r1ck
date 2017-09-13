#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
#include <stdbool.h>

void randomarray(int64_t sizeA, int64_t sizeB, int64_t* Ma, int64_t* Mb)
{
	for (int64_t st = 0; st < sizeA; st++)
	{
		*(Ma + st) = rand() % 10;
	}
	for (int64_t st = 0; st < sizeB; st++)
	{
		*(Mb + st) = rand() % 10;
	}
}

void print(int64_t sizeA, int sizeB, int64_t* Ma, int64_t* Mb)
{
	for (int64_t st = 0; st < sizeA; st++)
	{
		printf("%lli ", *(Ma+st));
	}
	printf("\n\n");
	for (int64_t st = 0; st < sizeB; st++)
	{
		printf("%lli ", *(Mb + st));
	}
	printf("\n\n");
}

void AinB(int64_t* Ma, int64_t* Mb, int64_t sizeA, int64_t sizeB)
{
    int64_t sb = 0;
    int64_t counter = 0;
    int a = 0;
	for (int64_t sa = 0; sa < sizeA; sa++)
	{
        if ((*(Ma + sa)) == (*(Mb + sb)))
		{
            counter++;
            sb++;
            if (counter == sizeB)
            {
                a++;
                printf("Есть совпадения: %d\n", a);
            }
		}
        else{
            counter = 0;
            sb = 0;
        }
	}
    if (a==0){
        printf("Нет совпадения: %d\n", a);
    }

}

int main()
{
	int64_t sizeA = 0;
	int64_t sizeB = 0;
	printf("Enter size for A\n");
	scanf("%lli", &sizeA);
	printf("Enter size for B\n");
	scanf("%lli", &sizeB);
	int64_t A[100];
	int64_t B[100];
	srand(time(NULL));
	int64_t *Ma;
	int64_t *Mb;
	Ma = A;
	Mb = B;
	printf("%p\n", Ma);
	randomarray(sizeA, sizeB, Ma, Mb);
	print(sizeA, sizeB, Ma, Mb);
	/*
	int64_t plus = 0;
	int64_t minus = 0;
	int64_t zero = 0;
	int64_t *plusu;
	int64_t *minusu;
	int64_t *zerou;
	plusu = &plus;
	minusu = &minus;
	zerou = &zero;
*/
	AinB(Ma, Mb, sizeA, sizeB);
//	printf("%lli", &A);
	system("pause");
	return 0;
}