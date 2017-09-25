#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void randomarray(int64_t size, int64_t* Ma, int64_t* Mb)
{
    for (int64_t st = 0; st < size; st++)
    {
        *(Ma + st) = rand() % 10;
    }
    for (int64_t st = 0; st < size; st++)
    {
        *(Mb + st) = rand() % 10;
    }
}

void print(int64_t size, int64_t* Ma, int64_t* Mb)
{
    for (int64_t st = 0; st < size; st++)
    {
        printf("%lli ", *(Ma+st));
    }
    printf("\n\n");
    for (int64_t st = 0; st < size; st++)
    {
        printf("%lli ", *(Mb + st));
    }
    printf("\n\n");
}

void sum_AandB(int64_t* Ma, int64_t* Mb, int64_t* Mc, int64_t size)
{
    for (int64_t position = 0; position < size; position++)
    {
        *(Mc+position) = (*(Ma+position))+(*(Mb+position));
        printf("%lli ", *(Mc+position));
    }
}

int main()
{
    int64_t size = 0;
    printf("Enter size\n");
    scanf("%lli", &size);
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
    randomarray(size, Ma, Mb);
    print(size,  Ma, Mb);

    sum_AandB(Ma, Mb, Mc, size);
    return 0;
}