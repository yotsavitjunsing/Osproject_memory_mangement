#include <stdio.h>

void bestFit(int blockSize[], int m, int processSize[], int n) {
    
    int allocation[n];

    
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1) {
                    bestIdx = j;
                } else if (blockSize[bestIdx] > blockSize[j]) {
                    bestIdx = j;
                }
            }
        }

        
        if (bestIdx != -1) {
            allocation[i] = bestIdx;

            
            blockSize[bestIdx] -= processSize[i];
        }
    }

    
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t\t%d\t\t\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}


int main() {
    int blockSize[] = {100, 500, 200, 300, 600,400,99};
    int processSize[] = {400,200, 458, 99, 572};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    bestFit(blockSize, m, processSize, n);

    return 0;
}
