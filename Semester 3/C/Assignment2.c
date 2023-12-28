#include <stdio.h>
#include <stdlib.h>

int Compact(int a[10][10], int n, int m, int b[10][3]) {
    int k = 0;
    b[0][0] = n;
    b[0][1] = m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) {
                b[k + 1][0] = i;
                b[k + 1][1] = j;
                b[k + 1][2] = a[i][j];
                k++;
            }
        }
    }
    b[0][2] = k;
    return k;
}

int SimpleTranspose(int a[10][3], int n, int m, int b[10][3]) {
    int t = a[0][2], q = 1;
    b[0][0] = m;
    b[0][1] = n;
    b[0][2] = t;

    for (int col = 0; col < m; col++) {
        for (int p = 1; p <= t; p++) {
            if (a[p][1] == col) {
                b[q][0] = a[p][1];
                b[q][1] = a[p][0];
                b[q][2] = a[p][2];
                q++;
            }
        }
    }
    return 0;
}

int FastTranspose(int a[10][3], int b[10][3], int n, int m) {
    int t = a[0][2], q = 1, j;
    int *s = (int *)malloc(n * sizeof(int));
    int *x = (int *)malloc(n * sizeof(int));
    b[0][0] = m;
    b[0][1] = n;
    b[0][2] = t;

    if (t <= 0) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        s[i] = 0;
    }

    for (int i = 1; i <= t; i++) {
        s[a[i][1]]++;
    }

    x[0] = 1;
    for (int i = 1; i < n; i++) {
        x[i] = x[i - 1] + s[i - 1];
    }

    for (int i = 1; i <= t; i++) {
        j = a[i][1];
        b[x[j]][0] = a[i][1];
        b[x[j]][1] = a[i][0];
        b[x[j]][2] = a[i][2];
        x[j]++;
    }

    free(s);
    free(x);

    return 0;
}

int main() {
    int n, m, k, sm[10][10], cmpt[10][3], st[10][3], ft[10][3], x;

    printf("Enter number of rows: ");
    scanf("%d", &n);
    printf("Enter number of columns: ");
    scanf("%d", &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter element of (%d, %d): ", i + 1, j + 1);
            scanf("%d", &sm[i][j]);
        }
    }

    printf("\nSparse Matrix:\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", sm[i][j]);
        }
        printf("\n");
    }

    k = Compact(sm, n, m, cmpt);
    printf("\nCompact Matrix:\n\n");
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", cmpt[i][j]);
        }
        printf("\n");
    }

    printf("\nChoose Simple Transpose or Fast Transpose (0,1): ");
    scanf("%d", &x);

    switch (x) {
        case 0:
            SimpleTranspose(cmpt, n, m, st);
            printf("\nSimple Transpose Matrix:\n\n");
            for (int i = 0; i <= k; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("%d\t", st[i][j]);
                }
                printf("\n");
            }
            break;

        case 1:
            FastTranspose(cmpt, ft, n, m);
            printf("\nFast Transpose Matrix:\n\n");
            for (int i = 0; i <= k; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("%d\t", ft[i][j]);
                }
                printf("\n");
            }
            break;

        default:
            break;
    }

    return 0;
}
