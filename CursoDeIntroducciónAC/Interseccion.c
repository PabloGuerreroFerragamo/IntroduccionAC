#include <stdio.h>

int main() {
    int i, j;
    int A[] = {1, 2, 3, -1};
    int B[] = {2, 22, 33, -1};
    int AnB[10];
    int indexAnB = 0;

    for (i = 0; A[i] != -1; i++) {
        for (j = 0; B[j] != -1; j++) {
            if (A[i] == B[j]) {
                AnB[indexAnB] = A[i];
                indexAnB++;
            }
        }
    }

    for (i = 0; i < indexAnB; i++) {
        printf("%d\n", AnB[i]);
    }

    return 0;
}