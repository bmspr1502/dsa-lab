#include <stdio.h>
#define size 100
//The time taken for each step is written in comments
int lenstr(char *A){
    int i;
    for(i=0; A[i]!='\0'; i++);
    return i;
}

int isUpper(char X){
    if(X>=65 && X<=90)
        return 1;

    return 0;
}

void capsfirst(char *str, char *str2){
    int len = lenstr(str),i;        //1

    char *ptr = str2;               //1
    //writing caps
    for(i=0; str[i]!='\0'; i++){    //1, n+1, n   
        if(isUpper(str[i])){        //n
            *ptr = str[i];          //worst case n
            ptr++;                  //worst case n
        }
    }
    //writing small
    for(i=0; str[i]!='\0'; i++){    //1, n+1, n
        if(!isUpper(str[i])){       //n
            *ptr = str[i];          //worst case n          
            ptr++;                  //worst case n
        }
    }
    *ptr='\0';                      //1
}


int main(){
    char string[size], string2[size];   //Here there are 2 strings of length n, so the space required is 2n
    scanf("%s", string);

    capsfirst(string, string2);
    printf("\nThe arranged string is: %s\n", string2);

}

/*
    *The time taken for all the steps in the worst case is:-
    *       = 1+1+((2n+2) +3n)*2 +1 = 3 + (5n+2)*2
    *       = 10n + 7
    * As we can see the time complexity is in O(n)
    * 
    * For the case of space complexity, 2n is required for the arrays and there are 
    * 5 variables in the function, so, the  space taken would be = 2n+5
    * But the complexity is still an Order(n)
*/