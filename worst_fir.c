#include <stdio.h>

void worstFit(int blockSize[], int m, int processSize[], int n) {
    
    int allocation[n];

   
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    
    for (int i = 0; i < n; i++) {
        int wstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (wstIdx == -1) {
                    wstIdx = j;
                } else if (blockSize[wstIdx] < blockSize[j]) {
                    wstIdx = j;
                }
            }
        }

        
        if (wstIdx != -1) {
            allocation[i] = wstIdx;

            
            blockSize[wstIdx] -= processSize[i];
        }
    }

    
    printf("Process No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t\t%d\t\t\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}


int main() {
    int blockSize[] = {120, 450, 110, 100, 600,890};
    int processSize[] = {78,375, 112, 98,72,652};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    worstFit(blockSize, m, processSize, n);

    return 0;
}
