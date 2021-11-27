#include<stdio.h>
#define size 100

struct student{
	int regn;
	float cgpa;
};

void main()
{
	struct student students[size];
	int count = 0,i;

	printf("\n Enter students reg.no. followed by cgpa and when you want to stop, enter reg.no as '0': \n");
	for(i=0; i<size; i++)
	{
		printf("Enter the details of student %d \n", i+1);
        printf("Enter the regn no. :");
		scanf("%d", &(students[i].regn));

		if(students[i].regn==0)
			break;

        printf("Enter the CGPA: ");
		scanf("%f", &(students[i].cgpa));
		count++;
	}

	printf("\n Showing all details: ");
	for(i=0; i<count; i++)
	{
		printf("\n Student %d ", i+1);
		printf("\n Regn = %d \n CGPA = %f", students[i].regn, students[i].cgpa);
	}
	printf("\n");

}
