//
//  main.c
//  NOJ97-scoring
//
//  Created by Steve X on 2017/11/30.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#define N 100

typedef struct tagTeam{
    char name[20];
    int sub[4],time[4],sum,penalty;
}TEAM;

void SelectionSort(TEAM B[],int n)  //选择排序
{
    int k;
    for(int i=0;i<n;i++){
        k=i;
        for(int j=i+1;j<=n;j++){
            if(B[j].sum>B[k].sum||(B[j].sum==B[k].sum&&B[j].penalty<B[j].penalty))k=j;
        }
        if(i!=k){
            TEAM t=B[i];
            B[i]=B[k];
            B[k]=t;
        }
    }
}

int main()
{
    TEAM T[N];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        T[i].name[0]='\0';
        T[i].sum=0;
        T[i].penalty=0;
        
        scanf("%s",T[i].name);
        for(int j=0;j<4;j++){
            scanf("%d%d",&T[i].sub[j],&T[i].time[j]);
            if(T[i].time[j]!=0){
                T[i].sum++;
                T[i].penalty+=(T[i].sub[j]-1)*20+T[i].time[j];
            }
        }
    }
    SelectionSort(T,n);
    printf("%s %d %d\n",T[1].name,T[1].sum,T[1].penalty);
    return 0;
}
