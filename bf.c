#include <stdio.h>

int main() {
    int fragment[20], b[20], f[20], i, j, nb, nf, temp, lowest;
    static int barray[20], ff[20];

    printf("\n\tMemory Management Scheme - Best Fit (Files)\n");
    printf("Enter the number of memory blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for(i = 1; i <= nb; i++) {
        printf("Block no.%d: ", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the files:\n");
    for(i = 1; i <= nf; i++) {
        printf("File no.%d: ", i);
        scanf("%d", &f[i]);
    }

    for(i = 1; i <= nf; i++) {
        lowest = 10000;
        for(j = 1; j <= nb; j++) {
            if(barray[j] != 1) {
                temp = b[j] - f[i];
                if(temp >= 0 && temp < lowest) {
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }

        fragment[i] = lowest;
        if(ff[i] != 0)
            barray[ff[i]] = 1;  // mark block as allocated
    }

    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");
    for(i = 1; i <= nf; i++) {
        if(ff[i] != 0)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], fragment[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\t--\t\t--\n", i, f[i]);
    }

    return 0;
}
=============fifo
//Learnprogramo
#include <stdio.h>
int main()
{
int referenceString[10], pageFaults = 0, m, n, s, pages, frames;
printf("\nEnter the number of Pages:\t");
scanf("%d", &pages);
printf("\nEnter reference string values:\n");
for( m = 0; m < pages; m++)
{
   printf("Value No. [%d]:\t", m + 1);
   scanf("%d", &referenceString[m]);
}
printf("\n What are the total number of frames:\t");
{
   scanf("%d", &frames);
}
int temp[frames];
for(m = 0; m < frames; m++)
{
  temp[m] = -1;
}
for(m = 0; m < pages; m++)
{
  s = 0;
  for(n = 0; n < frames; n++)
   {
      if(referenceString[m] == temp[n])
         {
            s++;
            pageFaults--;
         }
   }     
   pageFaults++;
   if((pageFaults <= frames) && (s == 0))
      {
        temp[m] = referenceString[m];
      }   
   else if(s == 0)
      {
        temp[(pageFaults - 1) % frames] = referenceString[m];
      }
      printf("\n");
      for(n = 0; n < frames; n++)
       {     
         printf("%d\t", temp[n]);
       }
} 
printf("\nTotal Page Faults:\t%d\n", pageFaults);
return 0;
}
