#include <stdio.h>
#include <stdlib.h>

long long int answer(long long int** given,long long int m,long long int n);

int main(){
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    long long int **given=malloc(sizeof(long long int*)*a);
    for(long long int i=0;i<b;++i){
        given[i]=(long long int*)malloc(sizeof(long long int)*b);
    }
    for(long long int i=0;i<a;i++){
        for(long long int j=0;j<b;j++){
            scanf("%lld",&given[i][j]);
        }
    }
    long long int ans=answer(given,a,b);
    printf("%lld \n",ans);
}