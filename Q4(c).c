#include <stdio.h>
int main() {
    int A[10][10], transpose[10][10];
    int r, c, i, j;

    printf("Enter rows and columns of matrix: ");

 scanf("%d %d", &r, &c);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &A[i][j]);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            transpose[j][i] = A[i][j];

    printf("Transpose of the matrix: \n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }

    return 0;
}