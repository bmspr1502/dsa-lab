#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define size 50

//function to generate the lps array, O(m)
void lpsarr(char *ptn, int *lps){
    int len = 0;
    lps[0] = 0;
    int i=1;
    int m = strlen(ptn);

    //loop runs m times, O(m)
    while(i<m){
        if(ptn[i] == ptn[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len==0){
                lps[i] = 0;
                i++;
            }else{
                len = lps[len-1];
            }
        }
    }

}

//Function to find the pattern, Time complexity = O(m+n)
void kmpsearch(char *ptn, char *txt){
    int n = strlen(txt);
    int m = strlen(ptn);
    bool found = false;
    int lps[m];

    lpsarr(ptn, lps);       //O(m)

    int i=0, j=0;

    //The loop doesn't backtrack each time, and runs only n times, O(n)
    while(i<n){
        if(ptn[j] == txt[i]){
            j++;
            i++;
        }

        if(j==m){
            found = true;
            printf("Found pattern at index %d \n", i-j);
            j= lps[j-1];
        }
        else if(i<n && ptn[j] != txt[i]){
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }

    if(found==false){
        printf("Pattern not found. \n");
    }
}

int main(){
    char txt[size], ptn[size];
    printf("\n Enter the text: ");
    scanf("%s", txt);
    printf("\n Enter the pattern to be found: ");
    scanf("%s", ptn);

    kmpsearch(ptn, txt);

    return 0;
}