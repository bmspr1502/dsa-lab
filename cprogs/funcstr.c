#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[20];
    int rollno;
};
void initialise(struct student* s){
    printf("Enter student name\n");
    fgets(s->name, 20, stdin);
    printf("Enter student roll number\n");
    scanf("%d",&(s->rollno));
}
void display(struct student* s){
    printf("Student name: %s\n",s->name);
    printf("Roll number: %d\n",s->rollno);
}
int main(){
    struct student s;
    initialise(&s);
    display(&s);
    return 0;
}