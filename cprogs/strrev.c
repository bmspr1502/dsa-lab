#include<stdio.h>
#define num 100

char string[num],newstr[num];
char *revstr(char string[]){
    char *a, *b;
    for(a=string; *a!='\0'; a++);
    a--;
    b = newstr;
    while(a!=string){
        *b = *a;
        a--;
        b++;
    }
    *b = *a;
    b++;
    *b = '\0';
    return newstr;
}

int main(){
    char c;
     int i;
    for(i=0; (i<100)&&((c=getchar())!='\n'); i++){
        string[i]=c;
    }
    string[i] = '\0';

    printf("The reverse of the string %s is %s\n", string, revstr(string));
    return 0;
}