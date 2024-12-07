#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool check_for_enough_players(int end, int pointer, int i, int team_size){
    return(end-i+1>=team_size-pointer)? true:false;
}

void print_team(int* good_team,int n){
    for(int i=0; i<n; i++){
        printf("%d ", good_team[i]);
    }
    printf("\n");
}

void good_team_generation(int* skill_array, int* good_team, int start, int end, int team_size, int pointer){
    if(pointer==team_size){
        print_team(good_team,team_size);
        return;
    }
    for(int i=start; i<=end; i++){
        if(check_for_enough_players(end, pointer, i, team_size)){
            good_team[pointer]=skill_array[i];
            good_team_generation(skill_array, good_team, start+1, end, team_size, pointer+1);
        }
    }
}

int main(){
    int N=5, K=3;
    //scanf("%d %d", &N, &K);
    int skill_array[5]={1, 2, 3, 4, 5};
    //for(int i=0; i<N; i++){
    //    scanf("%d ", &skill_array[i]);
    //}
    int good_team[K];
    good_team_generation(skill_array, good_team, 0, K-1, K, 0);
}