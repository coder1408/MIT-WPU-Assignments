#include <stdio.h>
#include <string.h>

struct student
{
    int roll_no;
    char name[20];
    int marks;
    int div;
};

void accept(struct student s[], int n);
void display(struct student s[], int n);
int linearSearch(struct student s[], int n, int searchValue);
int binarySearch(struct student s[], int n, int searchValue);
void selectionSort(struct student s[], int n);
void insertionSort(struct student s[], int n);
void shellSort(struct student s[], int n);

int i, j, n;

int main()
{
    struct student s[10];

    printf("Enter no. of students: ");
    scanf("%d", &n);

    accept(s, n);
    display(s, n);

    int choice;
    int linearSearchValue;
    int searchValue;

    do
    {
        printf("\nMenu:\n");
        printf("1. Search student info (Linear Search) \n");
        printf("2. Search student info (Binary Search) \n");
        printf("3. Sort Student info (Selection Sort) \n");
        printf("4. Sort Student info (Insertion Sort) \n");
        printf("5. Sort Student info (Shell Sort) \n");
        printf("6. Exit \n");
        printf("Enter Your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to search for: ");
            scanf("%d", &linearSearchValue);
            int linearFoundIndex = linearSearch(s, n, linearSearchValue);
            if (linearFoundIndex != -1)
            {
                printf("\nStudent found:\n");
                printf("Roll No: %d\n", s[linearFoundIndex].roll_no);
                printf("Name: %s\n", s[linearFoundIndex].name);
                printf("Marks: %d\n", s[linearFoundIndex].marks);
                printf("Division: %d\n", s[linearFoundIndex].div);
            }
            else
            {
                printf("\nStudent not found.\n");
            }
            break;

        case 2:
            printf("Enter value to search for: ");
            scanf("%d", &searchValue);
            int foundIndex = binarySearch(s, n, searchValue);
            if (foundIndex != -1)
            {
                printf("\nStudent found:\n");
                printf("Roll No: %d\n", s[foundIndex].roll_no);
                printf("Name: %s\n", s[foundIndex].name);
                printf("Marks: %d\n", s[foundIndex].marks);
                printf("Division: %d\n", s[foundIndex].div);
            }
            else
            {
                printf("\nStudent not found.\n");
            }
            break;

        case 3:
            selectionSort(s, n);
            display(s, n);
            break;

        case 4:
            insertionSort(s, n);
            display(s, n);
            break;

        case 5:
            shellSort(s, n);
            display(s, n);
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Option!\n");
        }

    } while (choice != 6);

    return 0;
}

void accept(struct student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter roll no.: \n");
        scanf("%d", &s[i].roll_no);
        printf("Enter name: \n");
        scanf("%s", s[i].name);
        printf("Enter marks: \n");
        scanf("%d", &s[i].marks);
        printf("Enter division: \n");
        scanf("%d", &s[i].div);
        printf("\n");
    }
}

void display(struct student s[], int n)
{
    printf("\nStudent Information:\n");
    printf("%s %s %s %s \n", "Roll No", "Name", "Marks", "Division");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %d %d \n", s[i].roll_no, s[i].name, s[i].marks, s[i].div);
    }
}

int linearSearch(struct student s[], int n, int searchValue)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i].roll_no == searchValue)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(struct student s[], int n, int searchValue)
{
    shellSort(s, n);

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (s[mid].roll_no == searchValue)
        {
            return mid;
        }
        else if (s[mid].roll_no < searchValue)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Not found
}

void selectionSort(struct student s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (s[j].roll_no < s[minIndex].roll_no)
                minIndex = j;
        }

        if (minIndex != i)
        {
            struct student temp = s[i];
            s[i] = s[minIndex];
            s[minIndex] = temp;
        }
    }
}

void insertionSort(struct student s[], int n)
{
    for (int i = 1; i < n; i++)
    {
        struct student key = s[i];
        int j = i - 1;

        while (j >= 0 && s[j].roll_no > key.roll_no)
        {
            s[j + 1] = s[j];
            j = j - 1;
        }

        s[j + 1] = key;
    }
}

void shellSort(struct student s[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            struct student temp = s[i];
            int j;

            for (j = i; j >= gap && s[j - gap].roll_no > temp.roll_no; j -= gap)
            {
                s[j] = s[j - gap];
            }

            s[j] = temp;
        }
    }
}
