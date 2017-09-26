#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
#include<stdbool.h>

int min_number(int size_for_A, int* A_pointer, int size_for_B, int* B_pointer)
{
    int min_number = *(A_pointer+0);
    for (int st = 0; st < size_for_A; st++)
    {
        if (*(A_pointer+st) < min_number)
        {
            min_number = *(A_pointer+st);
        }
    }
    for (int st = 0; st < size_for_B; st++)
    {
        if (*(B_pointer+st) < min_number)
        {
            min_number = *(B_pointer+st);
        }
    }
    return min_number;
}

int max_number(int size_for_A, int* A_pointer, int size_for_B, int* B_pointer)
{
    int max_number = *(A_pointer+0);
    for (int st = 0; st < size_for_A; st++)
    {
        if (*(A_pointer+st) > max_number)
        {
            max_number = *(A_pointer+st);
        }
    }
    for (int st = 0; st < size_for_B; st++)
    {
        if (*(B_pointer+st) > max_number)
        {
            max_number = *(B_pointer+st);
        }
    }
    return max_number;
}

int average_of_arrays(int size_for_A, int* A_pointer, int size_for_B, int* B_pointer)
{
    int avg = 0.0;
    int sum_of_arrays = 0;
    for (int st = 0; st < size_for_A; st++)
    {
            sum_of_arrays += *(A_pointer+st);
    }
    for (int st = 0; st < size_for_B; st++)
    {
            sum_of_arrays += *(B_pointer+st);
    }
    avg = (sum_of_arrays)/(size_for_A+size_for_B);

    return avg;
}

void randomarray(int size_for_A, int* A_pointer, int size_for_B, int* B_pointer)
{
    for (int st = 0; st < size_for_A; st++)
    {
        *(A_pointer+st) = rand() % 100;
    }
    for (int st = 0; st < size_for_B; st++)
    {
        *(B_pointer+st) = rand() % 100;
    }

}
void print(int size_for_A, int* A_pointer, int size_for_B, int* B_pointer)
{
    for (int st = 0; st < size_for_A; st++)
    {
        printf("%d ", *(A_pointer+st));
    }
    printf("\n\n");
    for (int st = 0; st < size_for_B; st++)
    {
        printf("%d ", *(B_pointer+st));
    }
    printf("\n\n");

}

int Action(int size_for_A, int *A_pointer, int size_for_B, int *B_pointer, int *min, int *max, int *avg)
{
    printf("for_min(0), for_max(1), for_average(2)\n");
    int temp;
    scanf("%d", &temp);

    int (*array_function[3])(int, int*, int, int*) = {min, max, avg};
    int result = array_function[temp](size_for_A, A_pointer, size_for_B, B_pointer);
    return result;
}

int main()
{
    int size_for_A = 0;

    printf("Enter size for array A:\n");
    scanf("%d", &size_for_A);
    int arrayA[size_for_A];
    int size_for_B = 0;
    printf("Enter size for array B:\n");
    scanf("%d", &size_for_B);
    int arrayB[size_for_B];
    int *A_pointer;
    A_pointer = arrayA;
    int *B_pointer;
    B_pointer =arrayB;
    srand(time(NULL));
    randomarray(size_for_A, A_pointer, size_for_B, B_pointer);
    print(size_for_A, A_pointer, size_for_B, B_pointer);
    int (*min)(int, int*, int, int*) = min_number;
    int (*max)(int, int*, int, int*) = max_number;
    int (*avg)(int, int*, int, int*) = average_of_arrays;
    printf("%d", Action(size_for_A, A_pointer, size_for_B, B_pointer, min, max, avg));
    return 0;
}