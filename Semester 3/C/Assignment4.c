#include <stdio.h>
#include <stdlib.h>

void bucketsort(int marks[], int n);
void radixsort(int marks[], int n);
void accept(int marks[], int n);
void display(int marks[], int n);

#define MAX 20

int main()
{
    int marks[10], n;
    printf("Enter No. of Students: ");
    scanf("%d", &n);
    int choice;

    do
    {
        printf("1. Bucket Sort\n");
        printf("2. Radix Sort\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            accept(marks, n);
            bucketsort(marks, n);
            display(marks, n);
            break;

        case 2:
            accept(marks, n);
            radixsort(marks, n);
            display(marks, n);
            break;

        case 3:
            printf("Exiting...");
            break;

        default:
            printf("Incorrect Choice\n");
        }
    } while (choice <= 2);

    return 0;
}

void accept(int marks[], int n)
{
    printf("Enter the marks of %d students:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter mark for student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }
}

void display(int marks[], int n)
{
    printf("Marks of %d students: \n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Student %d: %d\n", i + 1, marks[i]);
    }
}

void bucketsort(int marks[], int n)
{
    int i, j;
    int bucket[MAX];
    for (i = 0; i < MAX; i++)
    {
        bucket[i] = 0;
    }
    for (j = 0; j < n; j++)
    {
        ++bucket[marks[j]];
    }
    for (i = 0, j = 0; i < MAX; i++)
    {
        for (; bucket[i] > 0; --bucket[i])
        {
            marks[j] = i;
            j++;
        }
    }
}

void radixsort(int marks[], int n)
{
    int count[10], bkt[20][20];
    int large = marks[0];
    int i, j, k, bktno, div = 1;

    for (i = 0; i < n; i++)
    {
        if (marks[i] > large)
        {
            large = marks[i];
        }
    }

    int pass = 0;
    while (large > 0)
    {
        pass++;
        large = large / 10;
    }

    for (i = 1; i <= pass; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            count[j] = 0;
        }

        for (j = 0; j < n; j++)
        {
            bktno = (marks[j] / div) % 10;
            bkt[bktno][count[bktno]] = marks[j];
            count[bktno]++;
        }

        j = 0;
        for (bktno = 0; bktno <= 9; bktno++)
        {
            for (k = 0; k < count[bktno]; k++)
            {
                marks[j] = bkt[bktno][k];
                j++;
            }
        }

        div = div * 10;
    }
}