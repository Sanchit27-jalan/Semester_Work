#include <stdio.h>
int main(){
    int n,i,k,j;
    printf("Enter no of rows");
    scanf("%d",&n);
    for (i=1;i<=n;++i){
        for (j=n-i;j>0;--j){
            printf("\t");
        }
        for (k= (i*(i-1)/2)+1; k<= i*(i+1)/2; ++k){
            printf("%d",k);
            printf("\t");
        }
        printf("\n");

    }
    return 0;
}