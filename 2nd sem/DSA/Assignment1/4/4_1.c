#include <stdio.h>
#include <stdlib.h>

struct node
{
    int row;
    int col;
    int value;
    struct node *next;
};

struct node *transpose(struct node *dummy, int k)
{
    struct node *temp = dummy->next;
    struct node *trans = malloc(1 * sizeof(struct node));
    trans->col = -1;
    trans->row = -1;
    trans->value = 0;
    trans->next = NULL;
    // printf("%d\n", k);
    for (int i = 0; i < k; ++i)
    {
        struct node *t = trans;
        struct node *m = trans;
        int j = temp->col;
        int flag = 0;
        while (t->next != NULL)
        {
            if (t->row < j)
            {
                t = t->next;
            }
            if (t->row > j)
            {
                flag = 1;
                break;
            }
            if (t->row == j)
            {
                struct node *new = malloc(sizeof(struct node));
                new->col = temp->row;
                new->row = temp->col;
                new->value = temp->value;
                int p = temp->row;
                int flag_col = 0;
                while (t->next != NULL)
                {
                    if (t->col < p)
                    {
                        t = t->next;
                    }
                    if (t->col > p)
                    {
                        flag_col = 1;
                        break;
                    }
                    if (t->row != j)
                    {
                        flag_col = 1;
                        break;
                    }
                }
                if (flag_col == 0)
                {
                    new->next = NULL;
                    t->next = new;
                }
                if (flag_col == 1)
                {
                    new->next = t;
                    while (m->next != t)
                    {
                        m = m->next;
                    }
                    m->next = new;
                }
                flag = 2;
                break;
            }
        }
        if (flag == 0)
        {
            struct node *new = malloc(sizeof(struct node));
            new->col = temp->row;
            new->row = temp->col;
            new->value = temp->value;
            new->next = NULL;
            t->next = new;
        }
        else if (flag == 1)
        {
            struct node *new = malloc(sizeof(struct node));
            new->col = temp->row;
            new->row = temp->col;
            new->value = temp->value;
            new->next = t;
            while (m->next != t)
            {
                m = m->next;
            }
            m->next = new;
        }
        temp = temp->next;
    }
    return trans;
}
void add(struct node *dummy1, struct node *dummy2)
{
    struct node *temp1 = dummy1->next;
    struct node *temp2 = dummy2->next;
    struct node *t1 = dummy1->next;
    struct node *t2 = dummy2->next;
    int ct = 0;

    while (1)
    {
        if (t1 != NULL && t2 != NULL)
        {
            if (t1->col == t2->col && t1->row == t2->row)
            {
                int c = t1->value + t2->value;
                if (c != 0)
                {
                    ct++;
                    t1 = t1->next;
                    t2 = t2->next;
                }
                else
                {
                    t1 = t1->next;
                    t2 = t2->next;
                }
            }
            else if (t1->row == t2->row && t1->col > t2->col)
            {
                ct++;
                t2 = t2->next;
            }
            else if (t1->row == t2->row && t1->col < t2->col)
            {
                ct++;
                t1 = t1->next;
            }
            else if (t1->row > t2->row)
            {
                ct++;
                t2 = t2->next;
            }
            else if (t1->row < t2->row)
            {
                ct++;
                t1 = t1->next;
            }
        }
        if (t1 == NULL && t2 == NULL)
        {
            break;
        }
        if (t1 == NULL && t2 != NULL)
        {
            while (t2 != NULL)
            {
                ct++;
                t2 = t2->next;
            }
        }
        if (t1 != NULL && t2 == NULL)
        {
            while (t1 != NULL)
            {
                ct++;
                t1 = t1->next;
            }
        }
    }
    printf("%d \n", ct);
    while (1)
    {
        if (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->col == temp2->col && temp1->row == temp2->row)
            {
                int c = temp1->value + temp2->value;
                if (c != 0)
                {
                    printf("%d %d %d\n", temp1->row, temp1->col, c);
                    ct++;
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
                else
                {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
            }
            else if (temp1->row == temp2->row && temp1->col > temp2->col)
            {
                printf("%d %d %d\n", temp1->row, temp2->col, temp2->value);
                ct++;
                temp2 = temp2->next;
            }
            else if (temp1->row == temp2->row && temp1->col < temp2->col)
            {
                printf("%d %d %d\n", temp1->row, temp1->col, temp1->value);
                ct++;
                temp1 = temp1->next;
            }
            else if (temp1->row > temp2->row)
            {
                printf("%d %d %d\n", temp2->row, temp2->col, temp2->value);
                ct++;
                temp2 = temp2->next;
            }
            else if (temp1->row < temp2->row)
            {
                printf("%d %d %d\n", temp1->row, temp1->col, temp1->value);
                ct++;
                temp1 = temp1->next;
            }
        }
        if (temp1 == NULL && temp2 == NULL)
        {
            break;
        }
        if (temp1 == NULL && temp2 != NULL)
        {
            while (temp2 != NULL)
            {
                printf("%d %d %d\n", temp2->row, temp2->col, temp2->value);
                ct++;
                temp2 = temp2->next;
            }
        }
        if (temp1 != NULL && temp2 == NULL)
        {
            while (temp1 != NULL)
            {
                printf("%d %d %d\n", temp1->row, temp1->col, temp1->value);
                ct++;
                temp1 = temp1->next;
            }
        }
    }
}

void merge(int arr[][3], int left[][3], int right[][3], int left_size, int right_size)
{
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size)
    {
        if (left[i][0] < right[j][0])
        {
            arr[k][0] = left[i][0];
            arr[k][1] = left[i][1];
            arr[k][2] = left[i][2];
            i++;
        }
        else if (left[i][0] > right[j][0])
        {
            arr[k][0] = right[j][0];
            arr[k][1] = right[j][1];
            arr[k][2] = right[j][2];
            j++;
        }
        else if (left[i][0] == right[j][0] && left[i][1] < right[j][1])
        {
            arr[k][0] = left[i][0];
            arr[k][1] = left[i][1];
            arr[k][2] = left[i][2];
            i++;
        }
        else
        {
            arr[k][0] = right[j][0];
            arr[k][1] = right[j][1];
            arr[k][2] = right[j][2];
            j++;
        }
        k++;
    }
    while (i < left_size)
    {
        arr[k][0] = left[i][0];
        arr[k][1] = left[i][1];
        arr[k][2] = left[i][2];
        i++;
        k++;
    }
    while (j < right_size)
    {
        arr[k][0] = right[j][0];
        arr[k][1] = right[j][1];
        arr[k][2] = right[j][2];
        j++;
        k++;
    }
}

void merge_sort(int arr[][3], int n)
{
    if (n <= 1)
    {
        return;
    }
    int mid = n / 2;
    int left[mid][3], right[n - mid][3];
    for (int i = 0; i < mid; i++)
    {
        left[i][0] = arr[i][0];
        left[i][1] = arr[i][1];
        left[i][2] = arr[i][2];
    }
    for (int i = mid; i < n; i++)
    {
        right[i - mid][0] = arr[i][0];
        right[i - mid][1] = arr[i][1];
        right[i - mid][2] = arr[i][2];
    }
    merge_sort(left, mid);
    merge_sort(right, n - mid);
    merge(arr, left, right, mid, n - mid);
}
void multiply_2(struct node *dummy1, struct node *dummy2)
{
    struct node *temp1 = dummy1->next;
    struct node *temp2 = dummy2->next;
    int ct = 0;
    int a[1000500][3];
    while (temp1 != NULL)
    {
        int c = temp1->row;
        while (temp2 != NULL && c > temp2->row)
        {
            temp2 = temp2->next;
        }
        struct node *t = temp2;
        while (temp2 != NULL && temp2->row == c)
        {
            int m = temp1->value * temp2->value;
            int row = temp1->col;
            int column = temp2->col;
            a[ct][0]=row;
            a[ct][1]=column;
            a[ct][2]=m;
            ct++;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        if (temp1 != NULL && temp1->row == c)
        {
            temp2 = t;
        }
    }
    merge_sort(a, ct);
    int count=0;
    int i=0;
    while(i<ct){
        int j;
        int flag=0;
        j=i+1;
        while(1){
            if(a[i][0]==a[j][0] && a[i][1]==a[j][1]){
                a[i][2]=a[i][2]+a[j][2];
                j++;
                flag=1;
            }
            else{
                break;
            }
        }
        if(flag==0){
            if(a[i][2]!=0){
                count++;
            }
            ++i;
        }
        if(flag==1){
            if(a[i][2]!=0){
                count++;
            }
            i=j;
        }
    }
    printf("%d \n",count);
    i=0;
    while(i<ct){
        int j;
        int flag=0;
        j=i+1;
        while(1){
            if(a[i][0]==a[j][0] && a[i][1]==a[j][1]){
                j++;
                flag=1;
            }
            else{
                break;
            }
        }
        if(flag==0){
            if(a[i][2]!=0){
            printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
            }
            ++i;
        }
        if(flag==1){
            if(a[i][2]!=0){
            printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
            }
            i=j;
        }
    }
}


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
