#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

typedef int* Subset;

int string_count=0;

int fact(int x){
    return(x==0)? 1:x*fact(x-1);
}

long long int sum_array(int* array, int size){
    long long int sum=0;
    for(int i=0; i<size; i++){
        sum+=array[i];
    }
    return sum;
}

int prefix_sum(int* array, int N){
    int count_of_one=0;
    int count_of_zero=0;
    for(int i=0; i<N; i++){
        if(array[i]==1){
            count_of_one++;
        }
        else{
            count_of_zero++;
            if(count_of_one<count_of_zero){
                return 0;
            }
        }
    }
    return 1;
}

Subset binary_generator(int size, int num){
    Subset binary_string=(int*)malloc(sizeof(int)*size);
    int m=num;
    for(int i=0; i<size; i++)
        binary_string[i]=0;
    for(int i=0; i<size; i++){
        binary_string[size-1-i]=m%2;
        m/=2;
    }
    return binary_string;
}

bool binary_constraint(int* binary_string,int n){
    if(sum_array(binary_string, n)==n/2){
        if(binary_string[0]==0){
        return false;
        }
        else if(prefix_sum(binary_string, n/2)==0){
        return false;
        }
        else{
        return true;
        }
    }
    else{
        return false;
    }    
}

void string_generator(int n, char* plus_minus_array){
    char plus_minus_equivalent[2*n+1];
    for(int i=0; i<pow(2, 2*n); i++){
        Subset binary_representation=binary_generator(2*n,i);
        if(binary_constraint(binary_representation,n)){
            for(int i=0; i<=2*n; i++){
                string_count++;
                plus_minus_equivalent[2*n]='\0';
                if(binary_representation[i]==1){
                    plus_minus_equivalent[i]='+';
                }
                else if(binary_representation[i]==0){
                    plus_minus_equivalent[i]='-';
                }
                
            }
            strcpy(&plus_minus_array[i], plus_minus_equivalent);
            string_count++;
        }
    }
}

static int cmpfunc (const void * a, const void * b) { 
    
   return strcmp( *(char*)a, *(char*)b );
}//

void print_string(char* plus_minus_array[string_count], int size){
    for(int i=0; i<size; i++){
        printf("%s\n", plus_minus_array[i]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    char plus_minus_array[fact(20)/(fact(10)*2*fact(10))][2*n+1];
    string_generator(n, plus_minus_array);
    qsort(plus_minus_array, string_count, sizeof(plus_minus_array[0]), cmpfunc);
    print_string(plus_minus_array, string_count);

}