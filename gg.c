#include <stdio.h>

#define NUM_B 7
#define NUM_R 3

int blocks[NUM_B];
int request[NUM_R];
void print_state(){
    int i;
    printf("Blocks ");
    for(i=0;i<NUM_B;i++){
        printf("%d ",blocks[i]);
    }
    printf("\nRequest Size: ");
    for(i=0;i<NUM_R;i++){
        printf("%d ",request[i]);
    }
    printf("\n");
}
void first_fit() {
    int i, j;
    for (i = 0; i < NUM_R; i++) {
        for (j = 0; j < NUM_B; j++) {
            if (blocks[j] >= request[i]) {
                printf("Request of size %d allocated to block %d (original size %d)\n", request[i], j, blocks[j] + request[i]);
                blocks[j] -= request[i];
                break;
            }
        }
        if (j == NUM_B) {
            printf("Request of size %d cannot be allocated\n", request[i]);
        }
    }
}
int main() {
    int i;
    printf("Enter block sizes:\n");
    for (i = 0; i < NUM_B; i++) {
        printf("Block %d: ", i);
        scanf("%d", &blocks[i]);
    }

    printf("Enter request sizes:\n");
    for (i = 0; i < NUM_R; i++) {
        printf("Request %d: ", i);
        scanf("%d", &request[i]);
    }
    printf("Initial State:\n");
    print_state();
    first_fit();
    printf("Final State:\n");
    print_state();

    return 0;
}
-------------mem alloc
#include <stdio.h>

int main() {
    int ms, bs, nob, ef, n, mp[10], tif = 0;
    int i, p = 0;

    printf("Enter the total memory available (in Bytes): ");
    scanf("%d", &ms);
    printf("Enter the block size (in Bytes): ");
    scanf("%d", &bs);

    nob = ms / bs;            // number of blocks
    ef = ms - nob * bs;       // external fragmentation

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter memory required for process %d (in Bytes): ", i+1);
        scanf("%d", &mp[i]);
    }

    printf("\nNo. of blocks available in memory: %d\n", nob);
    printf("\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");

    for(i = 0; i < n && p < nob; i++) {
        printf("\n%d\t\t%d", i+1, mp[i]);
        if(mp[i] > bs) {
            printf("\t\tNO\t\t--");
        } else {
            printf("\t\tYES\t\t%d", bs - mp[i]);
            tif += bs - mp[i];
            p++;
        }
    }

    if(i < n)
        printf("\nMemory is full, remaining processes cannot be accommodated");

    printf("\n\nTotal internal fragmentation: %d", tif);
    printf("\nTotal external fragmentation: %d\n", ef);

    return 0;
}
