#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char name[20];
    int age;
    int phone_number;
    char e_mail[100];
} Student;

typedef struct linkedlist
{
    Student data;
    struct linkedlist *next;
} linkedlist;

linkedlist *createnode()
{
    linkedlist *temp = NULL;
    temp = (linkedlist *)malloc(sizeof(linkedlist));
    temp->next = NULL;
    return temp;
}

linkedlist *addnode(int value, linkedlist *head)
{
    linkedlist *p = head->next;
    linkedlist *temp = NULL;
    temp = createnode();
    temp->data.age = value;
    strcpy(temp->data.name, "Harshit");
    strcpy(temp->data.e_mail, "harshitguptaa16@gmail.com");
    temp->data.phone_number = 34674321;

    if (head->next == NULL)
    {
        head->next = temp;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}
void find_student_by_age(linkedlist *head, int n)
{
    linkedlist *temp;
    if (head->data.age == n)
    {
        printf("%s\n", head->data.name);
        return;
    }
    temp = head->next;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->data.age == n)
        {
            printf("%s\n", temp->data.name);
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        printf("NO student with given age is found\n");
    }
}
linkedlist *delete_element(linkedlist *head, int j)
{
    if (j == 1)
    {
        linkedlist *p;
        p = createnode();
        p = head;
        head = p->next;
        free(p);
        return head;
    }
    else
    {
        linkedlist *p = head;
        j -= 1;
        while (j > 1)
        {
            p = p->next;
            j--;
        }
        linkedlist*toDel = p->next;
        p->next = p->next->next;
        free(toDel);
        return head;
    }
}
int main()
{
    int q = 2;
    printf("enter the number of students you want to enter");
    scanf("%d", &q);
    q = q - 1;
    linkedlist *temp;
    temp = createnode();
    int n;
    scanf("%d", &n);
    strcpy(temp->data.name, "Har");
    temp->data.age = n;
    while (q > 0)
    {
        scanf("%d", &n);
        addnode(n, temp);
        q--;
    }
    // scanf("%d",&n);
    // find_student_by_age(temp,n);
    int x;
    scanf("%d", &x);
    temp = delete_element(temp, x);
    linkedlist *p = temp;
    while (p != NULL)
    {
        printf("%d\n", p->data.age);
        p = p->next;
    }
}