#include "functions.h"

int main()
{
    char c[4];
    scanf("%s\n", c);
    if (c[0] == 'A')
    {
        int n, m, k1, k2;
        scanf("%d %d %d %d", &n, &m, &k1, &k2);
        int i, j, val;
        struct node *dummy1 = malloc(sizeof(struct node));
        dummy1->col = -1;
        dummy1->row = -1;
        dummy1->value = 0;
        dummy1->next = NULL;
        struct node *dummy2 = malloc(sizeof(struct node));
        dummy2->col = -1;
        dummy2->row = -1;
        dummy2->value = 0;
        dummy2->next = NULL;
        struct node *temp = dummy1;
        for (int k = 0; k < k1; ++k)
        {
            scanf("%d %d %d", &i, &j, &val);
            struct node *new = (struct node *)malloc(1 * sizeof(struct node));
            new->next = NULL;
            new->col = j;
            new->value = val;
            new->row = i;
            temp->next = new;
            temp = temp->next;
        }
        struct node *temp1 = dummy2;
        for (int k = 0; k < k2; ++k)
        {
            scanf("%d %d %d", &i, &j, &val);
            struct node *new = (struct node *)malloc(1 * sizeof(struct node));
            new->next = NULL;
            new->col = j;
            new->value = val;
            new->row = i;
            temp1->next = new;
            temp1 = temp1->next;
        }
        add(dummy1, dummy2);
    }
    else if (c[0] == 'T')
    {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int i, j, val;
        struct node *dummy = malloc(sizeof(struct node));
        dummy->col = -1;
        dummy->row = -1;
        dummy->value = 0;
        dummy->next = NULL;
        struct node *temp = dummy;
        for (int k1 = 0; k1 < k; ++k1)
        {
            scanf("%d %d %d", &i, &j, &val);
            struct node *new = (struct node *)malloc(1 * sizeof(struct node));
            new->next = NULL;
            new->col = j;
            new->value = val;
            new->row = i;
            temp->next = new;
            temp = temp->next;
        }
        printf("%d \n", k);
        struct node *final = transpose(dummy, k);
        final = final->next;
        for (int i = 0; i < k; ++i)
        {
            printf("%d %d %d\n", final->row, final->col, final->value);
            final = final->next;
        }
    }
    else if (c[0] == 'M')
    {
        int n, m, l, k1, k2;
        scanf("%d %d %d %d %d", &n, &m, &l, &k1, &k2);
        int i, j, val;
        struct node *dummy1 = malloc(sizeof(struct node));
        dummy1->col = -1;
        dummy1->row = -1;
        dummy1->value = 0;
        dummy1->next = NULL;
        struct node *dummy2 = malloc(sizeof(struct node));
        dummy2->col = -1;
        dummy2->row = -1;
        dummy2->value = 0;
        dummy2->next = NULL;
        struct node *temp = dummy1;
        int arr[k1][3];
        for (int k = 0; k < k1; ++k)
        {
            scanf("%d %d %d", &i, &j, &val);
            struct node *new = (struct node *)malloc(1 * sizeof(struct node));
            arr[k][0]=j;
            arr[k][1]=i;
            arr[k][2]=val;
            new->next = NULL;
            new->col = j;
            new->value = val;
            new->row = i;
            temp->next = new;
            temp = temp->next;
        }
        merge_sort(arr,k1);
        struct node *t = dummy1->next;
        for(int i=0;i<k1;++i){
            t->row=arr[i][0];
            t->col=arr[i][1];
            t->value=arr[i][2];
            t=t->next;
        }
        struct node *temp1 = dummy2;
        for (int k = 0; k < k2; ++k)
        {
            scanf("%d %d %d", &i, &j, &val);
            struct node *new = (struct node *)malloc(1 * sizeof(struct node));
            new->next = NULL;
            new->col = j;
            new->value = val;
            new->row = i;
            temp1->next = new;
            temp1 = temp1->next;
        }
        multiply_2(dummy1, dummy2);
    }
}
