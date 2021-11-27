#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 20

//Function to return the larger value, O(1)
int max(int x, int y){
    return x>y? x:y;
}

//Function to compute the longest common sub sequence, O(n*m)
void longcomsubseq(char *a, char *b){

    int i,j,k;
    int n = strlen(a);
    int m = strlen(b);

    int dp[n+1][m+1];

    //O(n*m)
    for(i=0; i<=n; i++){
        for(j=0; j<=m; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;

            else if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    printf("DYNAMIC PROGRAMMING TABLE:\n");
    for (i = 0; i <= n; i++){
        if(i==0){
            printf("\t");
            for(k=0; k<m; k++)
                printf("\t%c", b[k]);
            printf("\n\t");
        }
        else
            printf("%c\t", a[i-1]);
        for (j = 0; j <= m; j++){
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }

    printf("\n The length of the longest common subsequence of %s and %s is : %d\n", a, b, dp[n][m]);

    k=dp[n][m];
    
    i=n;
    j=m;

    char lcs[k+1];
    lcs[k] = '\0';

    while(i>=0 && j>=0){        //O(min(n,m))
        if(a[i-1] == b[j-1]){
            lcs[--k] = a[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
    }

    printf("\n The longest common subsequence is: %s \n", lcs);
}

int main()
{
    char a[size], b[size];
    
    printf("Enter string 1:");
    scanf("%s", a);
    printf("Enter string 2:");
    scanf("%s", b);

    longcomsubseq(a, b);

    return 0;
}
