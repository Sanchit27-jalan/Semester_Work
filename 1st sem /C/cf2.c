#include <stdio.h>
int cnt[1000005];
int sum(int x){
    if (x==2020 || x==2021){
        cnt[x] = 1;
        return(1);}
    else if (x<2020){
        cnt[x] = 0;
        return(0);
    }
    else{
        if(cnt[x-2020] == -1)
            cnt[x-2020] = sum(x-2020);
        if(cnt[x-2021] == -1)
            cnt[x-2021] = sum(x-2021);
        int a= cnt[x-2020]+ cnt[x-2021];
        return(a);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;++i){
    int n;
    scanf("%d",&n);
    for(int i = 0; i <= n; ++i)
        cnt[i] = -1;
    int p= sum(n);
    if (p>=1){
        printf("YES \n");
    }
    else{
        printf("NO \n");
    }
    }
}