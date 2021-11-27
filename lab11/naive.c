#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define size 50

//Time complexity of the function is O(m*n)
void match(char *txt, char *ptn){
    int m,n,i,j;
    m = strlen(txt);
    n = strlen(ptn);
    bool found;
    for(i=0; i<=m-n; i++){      //O(mn)

        found = true;
        for(j=0; j<n; j++){         //O(n)
            if(txt[i+j] != ptn[j]){
                found = false;
                break;
            }
        }
        if(j==n)
            printf("Pattern found at %d \n", i);
    }
    if(found==false && j!=n){
        printf("Pattern not found \n");
    }
}

int main(){
    char txt[size], ptn[size];
    printf("\n Enter the text: ");
    scanf("%s", txt);
    printf("\n Enter the pattern to be found: ");
    scanf("%s", ptn);

    match(txt, ptn);

    return 0;
}