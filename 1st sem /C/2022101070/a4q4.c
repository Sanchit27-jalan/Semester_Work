#include <stdio.h>
#include <string.h>
struct student
{
    char email[100];
    char rollno[10];
    char marks1[10];
    char marks2[10];
    char marks3[10];
};
int main()
{
    struct student arr1[100];
    FILE *fptr;
    fptr = fopen("Assignment1.txt", "r");
    char ch1[100];
    fscanf(fptr, "%s", ch1);
    int count = 0;
    while (!feof(fptr))
    {
        strcpy(arr1[count].email, ch1);
        fscanf(fptr, "%s", ch1);
        strcpy(arr1[count].rollno, ch1);
        fscanf(fptr, "%s", ch1);
        strcpy(arr1[count].marks1, ch1);
        fscanf(fptr, "%s", ch1);
        count++;
    }
    fclose(fptr);
    FILE *fptr1;
    fptr1 = fopen("Assignment2.txt", "r");
    while (!feof(fptr1))
    {
        fscanf(fptr1, "%s", ch1);
        fscanf(fptr1, "%s", ch1);
        for (int i = 0; i < count; ++i)
        {
            if (strcmp(ch1, arr1[i].rollno) == 0)
            {
                fscanf(fptr1, "%s", ch1);
                strcpy(arr1[i].marks2, ch1);
                break;
            }
        }
    }
    fclose(fptr1);
    FILE *fptr2;
    fptr2 = fopen("Assignment3.txt", "r");
    while (!feof(fptr2))
    {
        fscanf(fptr2, "%s", ch1);
        fscanf(fptr2, "%s", ch1);
        for (int i = 0; i < count; ++i)
        {
            if (strcmp(ch1, arr1[i].rollno) == 0)
            {
                fscanf(fptr2, "%s", ch1);
                strcpy(arr1[i].marks3, ch1);
                break;
            }
        }
    }
    fclose(fptr2);
    FILE *fptr3;
    fptr3 = fopen("Assignment4.txt", "w");
    fprintf(fptr3, "%s\t\t\t\t", "Email");
    fprintf(fptr3, "%s\t", "RollNo");
    fprintf(fptr3, "%s\t", "Marks1");
    fprintf(fptr3, "%s\t", "Marks2");
    fprintf(fptr3, "%s\n", "Marks3");
    for (int i = 0; i < count; ++i)
    {
        fprintf(fptr3, "%s\t", arr1[i].email);
        fprintf(fptr3, "%s\t\t", arr1[i].rollno);
        fprintf(fptr3, "%s\t\t", arr1[i].marks1);
        fprintf(fptr3, "%s\t\t", arr1[i].marks2);
        fprintf(fptr3, "%s\n", arr1[i].marks3);
    }
    fclose(fptr3);
}