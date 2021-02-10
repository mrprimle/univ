#include <stdio.h>
#include <stdlib.h>




const int M = 3;
const int N = 3;
const int Q = 3;

void matMultiply(int A [][N], int B [][Q]) {
    int C[M][Q];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < Q; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    printf("\nthe result of multiplying\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < Q; j++)
            printf("%3d ", C[i][j]);
        printf("\n");
    }
}


int main()
{

    int A[M][N] = { {0, 9, 1}, {1, 3, 7}, {2, 7, 0} };
    int B[N][Q] = { {0, 9, 8}, {0, 9, 9}, {1, 9, 6} };
    matMultiply(A, B);

    return 0;
}
