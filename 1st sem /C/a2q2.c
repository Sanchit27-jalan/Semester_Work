#include <stdio.h>
#include <math.h>
long long int absolute(long long int n){
    if (n>=0){
        return(n);
    }
    else {
        return(-1*n);
    }
}
void binary(int arr1[],int z,int n){
    for (int i=n-1;i>=0;--i){
        int temp=z;
        if ((temp/pow(2,i))==0){
            arr1[n-1-i]=0;
        }
        else{
            if (z!=0){
            arr1[n-1-i]=z%2;
            z=z/2;}
            else {
                break;
            }
        }
    }


}
int main(){
    int n;
    scanf("%d",&n);
    long long int arr[n];
    for (long long int i=0;i<n;++i){
        scanf("%lld",&arr[i]);
    }
    long long int suma=0;
    for (long long int i=0;i<n;++i){
        suma=suma+arr[i];
    }
    long long int min=suma;
    for (int i=0;i<pow(2,n);++i){
        int arr1[n];
        for (int j=0;j<n;++j){
            arr1[j]=0;
        }
        binary(arr1,i,n);
        long long int sum=0;
        for (int k=0;k<n;++k){
            if (arr1[k]==1){
                sum=sum+arr[k];
            }
        }
        long long int z=suma-2*sum;
        long long int min1=absolute(z);
        if (min>min1){
            min=min1;
        }
    }
    printf("%lld",min);
}