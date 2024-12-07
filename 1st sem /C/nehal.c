#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char arr[], int size){
    for(int i=0; i<size/2; i++){
        if(arr[i]!=arr[size-1-i]){
            return 0;
        }
    }
    return 1;
}
void shift(char arr[], int size){
    char temp = arr[0];
    for(int i=0; i<size-1; i++){
        arr[i] = arr[i+1];
    }
    arr[size-1] = temp; 
}

int main(){
    char arr[100000];
    scanf("%s", arr);
    int size = strlen(arr);
    if(check(arr, size)){
        printf("YES\n");
        printf("%s",arr);
        return 0;
    }
    for(int i=0; i<size; i++){
        shift(arr, size);
        if(check(arr, size)){            
            printf("YES\n");
            printf("%s",arr);
            return 0;
        }   
    }
    printf("NO\n");
}