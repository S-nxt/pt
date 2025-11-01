#include <stdio.h>
#define MAX 50

int main() {
    int pages[MAX], frames[MAX], freq[MAX], temp[MAX];
    int n, fsize, i, j, k, pos, maxfreq;
    int page_faults = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &fsize);

    for(i = 0; i < fsize; i++) {
        frames[i] = -1; // initialize frames as empty
        freq[i] = 0;    // frequency of each page in frame
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        int found = 0;
        // Check if page is already in frames
        for(j = 0; j < fsize; j++) {
            if(frames[j] == pages[i]) {
                freq[j]++; // increase frequency
                found = 1;
                break;
            }
        }

        if(!found) {
            page_faults++;
            // Find empty frame
            int empty = -1;
            for(j = 0; j < fsize; j++) {
                if(frames[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) {
                frames[empty] = pages[i];
                freq[empty] = 1;
            } else {
                // Replace MFU page
                maxfreq = freq[0];
                pos = 0;
                for(j = 1; j < fsize; j++) {
                    if(freq[j] > maxfreq) {
                        maxfreq = freq[j];
                        pos = j;
                    }
                }
                frames[pos] = pages[i];
                freq[pos] = 1; // reset frequency for new page
            }
        }

        // Print current frame state
        printf("%d\t", pages[i]);
        for(j = 0; j < fsize; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
    return 0;
}
