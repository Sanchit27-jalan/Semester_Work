#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_mode(FILE *fptr)
{

    char read_array;
    printf("This is the following data stored in the file:\n");
    read_array = fgetc(fptr);
    while (read_array != EOF)
    {
        printf("%c", read_array);
        read_array = fgetc(fptr);
    }
    fclose(fptr);
}

void write_mode(FILE *fptr, int x)
{
    //read_mode(fptr);
    fptr = fopen("Marksheet.txt", "a");
    char email[100];
    int roll_no, a1, a2, a3;
    printf("Enter the student data according to the following format: \n");
    printf("Email \n");
    printf("RollNo Marks1 Marks2 Marks3 \n");
    for (int i = 0; i < x; i++)
    {
        scanf("%s", email);
        scanf("%d %d %d %d",&roll_no,&a1,&a2,&a3);
        fprintf(fptr, "%s\t", email);
        fprintf(fptr,"%d\t",roll_no);
        fprintf(fptr,"%d\t",a1);
        fprintf(fptr,"%d\t",a2);
        fprintf(fptr,"%d\n",a3);
    }
    fclose(fptr);

    fptr = fopen("Marksheet.txt", "r");
    char read_array;
    printf("This is the following data stored in the file after updating:\n");
    read_array = fgetc(fptr);
    while (read_array != EOF)
    {
        printf("%c", read_array);
        read_array = fgetc(fptr);
    }
    fclose(fptr);
}

int main()
{
    int operation, x;
    FILE *fPtr;
    fPtr = fopen("Marksheet.txt", "r");
    if (fPtr == NULL)
    {
        printf("File does not exist");
        exit(0);
    }

    while (1)
    {
        printf("Choose mode in which you want to operate: Read-1    Write-0\n");
        scanf("%d",&operation);
        if (operation == 1)
        {
            read_mode(fPtr);
        }
        else if(operation==0)
        {
            printf("Enter the number of students you want to add:\n");
            scanf("%d", &x);
            write_mode(fPtr, x);
        }
        else{
            break;
        }
    }
}