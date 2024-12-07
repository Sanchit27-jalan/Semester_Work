#include "srms.h"

int add_customer(char *name, int phone_no, Database *db) {
    Customer *c = &(db->customers[db->customer_count++]);
    c->phone_no = phone_no;
    strcpy(c->name, name);
    return db->customer_count-1;
}

Reciept* add_reciept(int value, int c, PayMode mode, Database *db) {
    Reciept* r = &(db->reciepts[db->reciept_count++]);
    r->customer_index= c;
    r->value = value;
    r->mode = mode;
    return r;
}


int main() {
    Database db;
    db.customer_count = db.reciept_count = 0;


    int a = add_customer("Alice",12345,&db);

    add_reciept(1000, a, Cash, &db);
    add_reciept(500, a, UPI, &db);

    int b = add_customer("Bob",5678,&db);

    add_reciept(700, b, Card, &db);
    add_reciept(500, b, UPI, &db);

    FILE* cus_file = fopen("customers.txt","w");
    for(int i=0;i<db.customer_count;++i){
        fprintf(cus_file,"%s\t",db.customers[i].name);
        fprintf(cus_file,"%d\n",db.customers[i].phone_no);
    }
    fclose(cus_file);
    FILE* res_file = fopen("reciepts.txt","w");
    for (int i=0;i<db.reciept_count;++i){
        fprintf(res_file,"%d\t\t",db.reciepts[i].customer_index);
        fprintf(res_file,"%d\t\t",db.reciepts[i].mode);
        fprintf(res_file,"%f\n",db.reciepts[i].value);
    }
    // fwrite(&(db.reciept_count), sizeof(int), 1, res_file);
    // fwrite(db.reciepts, sizeof(Reciept), db.reciept_count, res_file);
    fclose(res_file);
    return 0;
}