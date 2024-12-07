#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct Customer
{
    char name[100];
    long PhoneNo;
}Customer;
typedef struct receipt
{
    int day;
    Customer* customer;
    int no_of_pens;
    int no_of_pencils;
    int value;
}receipt;
typedef struct database
{
    Customer customers[100];
    receipt receipts[1000];
    int cust_count;
    int receipt_count;
}database;
Customer* FindingTheCust(long PhoneNo,database* DB)
{
    Customer* finder=NULL;
    for(int i=0;i<DB->cust_count;i++)
    {
        if(PhoneNo==DB->customers[i].PhoneNo)
        {
            finder=&(DB->customers[i]);
            break;
        }
    }    
    return finder;
}
Customer* ADDaNewCust(char* name,long phoneno,database* DB)
{
    Customer* c =&(DB->customers[DB->cust_count++]);
    c->PhoneNo=phoneno;
    strcpy(c->name,name);
    return c;
}
receipt* ADDanewRec(int no_of_pens,int no_of_pencils, Customer*c,database* DB,int day)
{
    receipt* r= &(DB->receipts[DB->receipt_count++]);
    r->customer=c;
    r->day=day;
    r->no_of_pencils=no_of_pencils;
    r->no_of_pens=no_of_pens;
    int b=20*no_of_pens+10*no_of_pencils;
    r->value=b;
    return r;
}
int main()
{
    database db;
    db.cust_count=db.receipt_count=0;
    while(true)
    {
        //system("@cls||clear");
        printf("------------------------------------------------------\n"
        "STORE MGMT SYSTEM\n"
        "\t options: 0 = New Receipt\t1 = New Customer   2=Receipts amount for a phone no     3=Total receipts amt order on a particular day"
        "\t stats %d customers and %d receipts\n"
        "-----------------------------------------------------------\n"
        "Enter option:\n",db.cust_count,db.receipt_count);
        int option;
        scanf("%d",&option);
        long p;int v,z,o=0;char q;
        long f;
        char names[100];
        Customer* c=NULL;
        switch(option)
        {
            case 0:
            printf("Enter customer's phone no\n");
            scanf("%ld",&p);
            c = FindingTheCust(p,&db);
            if(c==NULL){
                printf("New Customer's Name:");
            scanf("%s",names);
            c = ADDaNewCust(names,p,&db);}
            else
                printf("Customer is %s\n",c->name);
            printf("No of pens\n");
            scanf("%d",&v);
            int e;
            printf("No of pencils\n");
            scanf("%d",&e);
            printf("enter day no \n");
            int m;
            scanf("%d",&m);
            receipt* d = ADDanewRec(v,e,c,&db,m);
            int d2=db.receipt_count-1;
            printf("Name is : %s \n",db.receipts[d2].customer->name);
            printf("Phone No is : %ld \n",db.receipts[d2].customer->PhoneNo);
            printf("Cost of pens is : %d \n",20*db.receipts[d2].no_of_pens);
            printf("Cost of pencils is : %d \n",10*db.receipts[d2].no_of_pencils);
            printf("Total value is : %d",db.receipts[d2].value);
            break;
            case 1:
            printf("Enter customer's Name\n");
            scanf("%s",names);
            printf("Enter Phone No.\n");
            scanf("%ld",&p);
            c = ADDaNewCust(names,p,&db);
            break;
            case 2:
            printf("Enter Phone No \n");
            scanf("%ld",&f);
            c=FindingTheCust(f,&db);
            int flag=0;
            for (int i=0;i<db.receipt_count;++i){
                if(db.receipts[i].customer==c){
                    printf("The value of receipt is : %d \n",db.receipts[i].value);
                    flag=1;
                }
                
            }
            if (flag==0){
                printf("No receipt for given phone no");
            }
            break;
            case 3:
            printf("Enter day no \n");
            int m1;
            scanf("%d",&m1);
            int sum=0;
            for(int i=0;i<db.receipt_count;++i){
                if(m1==db.receipts[i].day){
                    sum=sum+db.receipts[i].value;
                }
            }
            if (sum==0){
                printf("No value of receipts issued today \n");
            }
            else{
                printf("Total value of receipts on day %d is %d",m1,sum);
            }
            break;
            default:
            break;
        }
    }
    return 0;
}