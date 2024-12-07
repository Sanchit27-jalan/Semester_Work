
#include <stdio.h>
int main(){
    int h,m,s;
    printf("Enter time \n");
    scanf("%d:%d:%d",&h,&m,&s);
    int min;
    min= h*60+m;
    printf("Time in minutes:%d",min);
    return 0;
}