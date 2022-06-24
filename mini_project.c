#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct employee
{
char name[20];
int id;

union info
{
int monthly_salary;
int hours_worked;
}details;
}e1,e2;
void main()
{
    FILE *empinfo;
    empinfo = fopen("person.dat","w");
    if(empinfo == NULL){
        fprintf(stderr,"\nError opened file\n");
        exit (1);
    }
    
    strcpy(e1.name,"anil");
    e1.id=456;
    e1.details.hours_worked = 10;
    e1.details.monthly_salary = 1500000;
    strcpy(e2.name,"suman");
    e2.id=458;
    e2.details.monthly_salary = 2000000;
    e2.details.hours_worked = 20;
    fwrite(&e1,sizeof(struct employee),1,empinfo);
    fwrite(&e2,sizeof(struct employee),1,empinfo);
    if(fwrite !=0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
    if (empinfo == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
   // while(fread(&e1,sizeof(struct employee),1,empinfo))
    printf("\nname:%s\nid=%d\nmonthly salary:%d\nhours worked%dhrs",e1.name,e1.id,e1.details.monthly_salary,e1.details.hours_worked);
    printf("\n\nname:%s\nid=%d\nmonthly salary:%d\nhours worked%dhrs",e2.name,e2.id,e2.details.monthly_salary,e2.details.hours_worked);
    
    fclose(empinfo);
   }
