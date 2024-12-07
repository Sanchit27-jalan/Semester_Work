#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fptr;
    fptr = fopen("Sample.txt", "r+");
    char ch1;
    ch1 = fgetc(fptr);
    int flag = 1;
    while (ch1 != EOF)
    {
        if (ch1 >= 'a' && ch1 <= 'z' && flag == 1)
        {
            ch1 = ch1 - 32;
            fseek(fptr, -1, SEEK_CUR);
            fputc(ch1, fptr);
            flag = 0;
        }
        if (ch1 == ' ' || ch1 == '\n')
        {
            flag = 1;
            fseek(fptr, -2, SEEK_CUR);
            ch1 = fgetc(fptr);
            int t = 0;
            if (ch1 >= 'a' && ch1 <= 'z')
            {
                fseek(fptr, -1, SEEK_CUR);
                ch1 = ch1 - 32;
                fputc(ch1, fptr);
                t = 1;
            }
            if (t == 0)
            {
                fseek(fptr, 1, SEEK_CUR);
            }
        }
        ch1 = fgetc(fptr);
    }
    fseek(fptr, -1, SEEK_CUR);
    ch1 = fgetc(fptr);
    fseek(fptr, -1, SEEK_CUR);
    if (ch1 >= 'a' && ch1 <= 'z')
    {
        ch1 = ch1 - 32;
        fputc(ch1, fptr);
    }
    fclose(fptr);
}