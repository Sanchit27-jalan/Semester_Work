#include "sort.h"

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        int n,k;
        scanf("%d %d",&n,&k);
        int input;
        heap h=create(n+1);
        for(int j=0;j<n;++j){
            scanf("%d",&input);
            insert(h,input);
        }
        // for(int j=1;j<=n;++j){
        //     printf("%d ",h->elements[j]);
        // }
        long long int ans=happy_calc(h,k);
        printf("%lld\n",ans);
    }
}