#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

void print(int64_t sizeA, int64_t sizeB, int64_t* Ma, int64_t* Mb)
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

void printafteradd(int64_t sizeA, int64_t sizeB, int64_t* Ma) //print A after add
{
    for (int64_t st = 0; st < (sizeA+sizeB); st++)
    {
        printf("%lli ", *(Ma+st));
    }
    printf("\n\n");
}


void freeadd(int64_t* Ma, int64_t* Mb, int64_t sizeA, int64_t sizeB)
{
    int64_t position = 0;
    printf("Enter pointer for add:\n");
    scanf("%lli", &position);
    for (int64_t i = 0; i < sizeB; i++)
    {
        for(int64_t c = (sizeA+sizeB-1); c > position+i; c--)
        {
            *(Ma + c) = (*(Ma + (c - 1)));
        }
        *(Ma+(position+i)) = (*(Mb+i));
    }
}



int main()
{
    int64_t sizeA = 0;
    printf("Enter size for A\n");
    scanf("%lli", &sizeA);
    int64_t sizeB = 0;
    printf("Enter size for B\n");
    scanf("%lli", &sizeB);
    int64_t A[100];
    int64_t B[100];
    int64_t C[100];
    srand(time(NULL));
    int64_t *Ma;
    int64_t *Mb;
    int64_t *Mc;
    Ma = A;
    Mb = B;
    Mc = C;
    printf("%p\n", Ma);
    randomarray(sizeA, sizeB, Ma, Mb);
    print(sizeA, sizeB, Ma, Mb);
    freeadd(Ma, Mb, sizeA, sizeB);
    printafteradd(sizeA, sizeB, Ma);
    return 0;
}