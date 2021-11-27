#include<stdio.h>
#define num 100

void strcomp(char string1[], int l1, char string2[], int l2){
    if(l1>l2){
        printf("Strings %s and %s are unequal and %s has the larger length\n", string1, string2, string1);
        return;
    } else if(l1<l2){
        printf("Strings %s and %s are unequal and %s has the larger length\n", string1, string2, string2);
        return;
    }else if(l1==l2){
        char *a = string1, *b = string2;
        int diff=0;

        while(*a!='\0'){
            if(*a!=*b){
                diff=1;
                break;
            }
            a++;
            b++;
        }

        if(diff==0){
            printf("Strings %s and %s are equal \n", string1, string2);
            return;
        }else{
            printf("Strings %s and %s have equal length but are not equal \n", string1, string2);
            return;
        }
    }
}

int main(){
    char str1[num], str2[num];
    char c;
     int i, l1, l2;
    for(i=0; (i<num)&&((c=getchar())!='\n'); i++){
        str1[i]=c;
    }
    str1[i] = '\0';
    l1 = i;

    for(i=0; (i<num)&&((c=getchar())!='\n'); i++){
        str2[i]=c;
    }
    str2[i] = '\0';
    l2 = i;

    strcomp(str1, l1, str2, l2);
    return 0;
}