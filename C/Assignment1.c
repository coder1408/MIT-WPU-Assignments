#include <stdio.h>
#include <stdbool.h>

void accept(int matrix[10][10], int r, int c);
void display(int matrix[10][10], int r, int c);
void add(int matrix1[10][10], int matrix2[10][10], int r, int c);
void subtract(int matrix1[10][10], int matrix2[10][10], int r, int c);
void multiply(int matrix1[10][10], int matrix2[10][10], int r1, int c1, int r2, int c2);
void transpose(int matrix[10][10], int r, int c);
bool identity(int matrix[10][10], int r, int c);
bool is_upper_triangular(int matrix[10][10], int r, int c);
bool is_lower_triangular(int matrix[10][10], int r, int c);

int i, j;
int operation;

int main()
{
    int matrix1[10][10], matrix2[10][10];
    int r1, c1, r2, c2;

    do
    {
        printf("Enter size of matrix 1: \n");
        scanf("%d%d", &r1, &c1);
        accept(matrix1, r1, c1);
        display(matrix1, r1, c1);

        printf("Enter size of matrix 2: \n");
        scanf("%d%d", &r2, &c2);
        accept(matrix2, r2, c2);
        display(matrix2, r2, c2);

        printf("Enter operation to perform \n 1: Add,\n 2: Subtract,\n 3: Multiply,\n 4: Transpose,\n 5: Identity,\n 6: Upper Triangular,\n 7: Lower Triangular: \n");
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
            if (r1 == r2 && c1 == c2)
            {
                add(matrix1, matrix2, r1, c1);
            }
            else
            {
                printf("Error! Matrices are not of the same size for addition.\n");
            }
            break;

        case 2:
            if (r1 == r2 && c1 == c2)
            {
                subtract(matrix1, matrix2, r1, c1);
            }
            else
            {
                printf("Error! Matrices are not of the same size for subtraction.\n");
            }
            break;

        case 3:
            if (c1 == r2)
            {
                multiply(matrix1, matrix2, r1, c1, r2, c2);
            }
            else
            {
                printf("Error! Number of columns in matrix 1 is not equal to number of rows in matrix 2 for multiplication.\n");
            }
            break;

        case 4:
            transpose(matrix1, r1, c1);
            break;

        case 5:
            if (identity(matrix1, r1, c1))
            {
                printf("Yes it is an identity matrix");
            }
            else
            {
                printf("No it is not an identity matrix");
            }
            break;

        case 6:
            if (is_upper_triangular(matrix1, r1, c1))
            {
                printf("The given matrix is an Upper Triangular matrix.\n");
            }
            else
            {
                printf("The given matrix is not an Upper Triangular matrix.\n");
            }
            break;

        case 7:
            if (is_lower_triangular(matrix1, r1, c1))
            {
                printf("The given matrix is a Lower Triangular matrix.\n");
            }
            else
            {
                printf("The given matrix is not a Lower Triangular matrix.\n");
            }

            break;

        default:
            printf("Error! Operation Not Available\n");
            break;
        }

    } while (operation < 10);

    return 0;
}

void accept(int matrix[10][10], int r, int c)
{

    printf("Enter elements of matrix: \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display(int matrix[10][10], int r, int c)
{
    printf("Matrix:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add(int matrix1[10][10], int matrix2[10][10], int r, int c)
{
    int result[10][10];
    printf("Result of addition:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void subtract(int matrix1[10][10], int matrix2[10][10], int r, int c)
{
    int result[10][10];
    printf("Result of subtraction:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void multiply(int matrix1[10][10], int matrix2[10][10], int r1, int c1, int r2, int c2)
{
    int result[10][10];
    printf("Result of multiplication:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void transpose(int matrix[10][10], int r, int c)
{
    int result[10][10];
    printf("Transpose of the matrix:\n");
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < r; j++)
        {
            result[i][j] = matrix[j][i];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

bool identity(int matrix[10][10], int r, int c)
{
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (i == j && matrix[i][j] != 1)
            {
                return false;
            }
            else if (i != j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool is_upper_triangular(int matrix[10][10], int r, int c)
{
    if (r != c)
    {
        return false;
    }

    for (i = 1; i < r; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (matrix[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

bool is_lower_triangular(int matrix[10][10], int r, int c)
{
    if (r != c)
    {
        return false;
    }

    for (i = 0; i < r; i++)
    {
        for (j = i + 1; j < c; j++)
        {
            if (matrix[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}
