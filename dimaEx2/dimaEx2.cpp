#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int sum_of_positive(int X[])
{
    int sum = 0;
    for (int i = 0; i < 20; i++)
    {
        if (X[i] > 0) sum += X[i];
    }
    return sum;
}

int amount_of_positive(int X[])
{
    int amount = 0;
    for (int i = 0; i < 20; i++)
    {
        if (X[i] >= 0) amount++;
    }
    return amount;
}

int sum_of_negative(int X[])
{
    int sum = 0;
    for (int i = 0; i < 20; i++)
    {
        if (X[i] < 0) sum += X[i];
    }
    return sum;
}

int amount_of_negative(int X[])
{
    int amount = 0;
    for (int i = 0; i < 20; i++)
    {
        if (X[i] < 0) amount++;
    }
    return amount;
}

int main()
{
    int* X;
    X = (int*)malloc(20 * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < 20; i++)
    {
        if (-1 * (rand() % 2) == 0) X[i] = (rand() % 101);
        else X[i] = (rand() % 101) * -1;

        printf("%d ", X[i]);
    }


    printf("\nКількість позитивних елементів: %d\n", amount_of_positive(X));
    printf("Сума позитивних елементів: %d\n", sum_of_positive(X));

    printf("Кількість негативних елементів: %d\n", amount_of_negative(X));
    printf("Сума негативних елементів: %d\n", sum_of_negative(X));

    free(X);
    return 0;
}

