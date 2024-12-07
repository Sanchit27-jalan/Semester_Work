#include <stdio.h>
#include <string.h>
struct info
{
    char email[100];
    char name[100];
    int age;
    int roll_no;
    char hostel_add[100];
};
void name(struct info student[], int n)
{
    int flag=0;
    for (int i = 0; i < n; ++i)
    {
        if (student[i].age == 19)
        {
            printf("Name found are: %s \n", student[i].name);
            flag=1;
        }
    }
    if (flag==0){
        printf("No is having age 19 \n");
    }
}
void address(struct info student[], int n)
{
    int flag=0;
    for (int i = 0; i < n; ++i)
    {
        if (student[i].email[0] == 'I' || student[i].email[0] == 'T' || student[i].email[0] == 't' || student[i].email[0] == 'i' )
        {
            printf("Name found are:%s \n", student[i].name);
            flag=1;
        }
    }
    if(flag==0){
        printf("No email starts with T,I,t or i \n");
    }
}
void mail(struct info student[], int n, char arr4[])
{
    int flag = 0;
    for (int i = 0; i < n; ++i)
    {
        if (strcmp(arr4, student[i].email) == 0)
        {
            printf("Name is: %s \n", student[i].name);
            printf("Age is: %d \n", student[i].age);
            printf("Roll No is: %d \n", student[i].roll_no);
            printf("Hostel Address is: %s \n", student[i].hostel_add);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("No student exists for this email id \n");
    }
}
int main()
{
    printf("Enter no of students: ");
    int n;
    scanf("%d", &n);
    struct info student[n];
    for (int i = 0; i < n; ++i)
    {
        printf("Enter email id: ");
        scanf("%s", student[i].email);
        printf("Enter name: ");
        scanf("%s", student[i].name);
        printf("Enter age : ");
        scanf("%d", &student[i].age);
        printf("Enter roll no: ");
        scanf("%d", &student[i].roll_no);
        printf("Enter hostel address: ");
        scanf("%s", student[i].hostel_add);
    }
    name(student, n);
    address(student, n);
    printf("Enter email id to be found :");
    char arr4[1000];
    scanf("%s", arr4);
    mail(student, n, arr4);
}