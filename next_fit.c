#include <stdio.h>

void NextFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    int j = 0;
    int t = m - 1;

    for (int i = 0; i < n; i++) {
        while (j < m) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                t = (j - 1) % m;
                break;
            }
            if (t == j) {
                t = (j - 1) % m;
                break;
            }
            j = (j + 1) % m;
        }
    }

    printf("Process No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf("\t%d\t\t\t%d\t\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int blockSize[] = {5, 10, 20};
    int processSize[] = {10, 20, 5};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    NextFit(blockSize, m, processSize, n);

    return 0;
}
