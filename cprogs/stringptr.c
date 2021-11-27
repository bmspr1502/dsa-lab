#include<stdio.h>

int findlength(char string[]){
    int i=0;
    char *a = string;
    while(*a!='\0'){
        i++;
        a++;
    }
    return i;
}

int main(){
    char c,string[100];
    int i;
    for(i=0; (i<100)&&((c=getchar())!='\n'); i++){
        string[i]=c;
    }
    string[i] = '\0';

    printf("The size of the string %s is %d\n", string, findlength(string));

    return 0;
}