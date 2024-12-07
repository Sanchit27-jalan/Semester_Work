#include <stdio.h>
struct complex
{
    int real;
    int img;
};
void addition(struct complex c1, struct complex c2)
{
    int c = c1.real + c2.real;
    int d = c1.img + c2.img;
    if (d >= 0)
    {
        printf("Addition is : %d +%di \n", c, d);
    }
    else
    {
        printf("Addition is : %d -%di \n", c, -1 * d);
    }
}
void subtraction(struct complex c1, struct complex c2)
{
    int c = c1.real - c2.real;
    int d = c1.img - c2.img;
    if (d >= 0)
    {
        printf("Subtraction is : %d +%di \n", c, d);
    }
    else
    {
        printf("Subtraction is : %d -%di \n", c, -1 * d);
    }
}
void multiplication(struct complex c1, struct complex c2)
{
    int a = c1.real * c2.real - c1.img * c2.img;
    int b = c1.real * c2.img + c1.img * c2.real;
    if (b >= 0)
    {
        printf("Multiplication is : %d +%di \n", a, b);
    }
    else
    {
        printf("Multiplication is : %d -%di \n", a, -1 * b);
    }
}
int main()
{
    struct complex c1;
    struct complex c2;
    printf("Enter real part of 1st number :");
    scanf("%d", &c1.real);
    printf("Enter img part of 1st number :");
    scanf("%d", &c1.img);
    printf("Enter real part of 2nd number :");
    scanf("%d", &c2.real);
    printf("Enter img part of 2nd number :");
    scanf("%d", &c2.img);
    while (1)
    {
        printf("Enter option: \n");
        printf("1 for addition \n");
        printf("2 for subtraction \n");
        printf("3 for multiplication \n");
        printf("4 for exit \n");
        int n;
        scanf("%d", &n);
        if (n == 1)
        {
            addition(c1, c2);
        }
        else if (n == 2)
        {
            subtraction(c1, c2);
        }
        else if (n == 3)
        {
            multiplication(c1, c2);
        }
        else
        {
            break;
        }
    }
}
