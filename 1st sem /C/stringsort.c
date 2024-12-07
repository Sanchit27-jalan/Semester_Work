#include <stdio.h>
#include <string.h>
char arr[100][4]={"aabb","abba","abab","bbaa","baba","baab"};
void merge(char *L,char R[],char A[], int sL, int sR){
    int l=0,r=0,c=0;
    while (c<sL+sR){
        if (l==sL){
            A[c]=R[r];
            c++;
            r++;
        }
        else if(r==sR){
            A[c]=L[l];
            c++;
            l++;
        }
        else if (strcmp(L[l],R[r])>0){
            A[c]=R[r];
            r++;
            c++;
        }
        else{
            A[c]=L[l];
            c++;
            l++;
        }
    }
}
void sorting(int len){
    if (len==1){ 
        return;
    }
    else{
        int mid=len/2;
        char L[mid][4];
        for(int i=0;i<mid;++i){
            for(int j=0;j<4;++){
                L[i][j]=arr[i][j];
            }
        }
        char R[len-mid][4];
        for(int j=mid;j<len;++j){
            R[j-mid]=arr[j];
        }
        sorting(L,mid);
        sorting(R,len-mid);
        merge(L,R,arr,mid,(len-mid));
    }
}
int main(){
    sorting(6);
    for (int i=0;i<6;++i){
        printf("%s \n",arr[i]);
    }
}