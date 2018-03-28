//
//  main.c
//  NOJ89-soldier queue
//
//  Created by Steve X on 2017/11/21.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 10000

typedef struct tagsoldier{
    int x;
    int y;
}SOLDIER;

void sorty(SOLDIER A[],int n)    //按y排序
{
    SOLDIER t;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(A[i].y<A[j].y){
                t=A[i];
                A[i]=A[j];
                A[j]=t;
            }
        }
    }
}

void sortx(SOLDIER A[],int n)    //按x排序
{
    SOLDIER t;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(A[i].x<A[j].x){
                t=A[i];
                A[i]=A[j];
                A[j]=t;
            }
        }
    }
}

int main()
{
    SOLDIER A[N],Mid;
    int n,X=0,Y=0,X1=0,Y1=0,X2=0,Y2=0,sum1=0,sum2=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&A[i].x,&A[i].y);
    }
    
    sorty(A,n);                                //按y排序，以中位数为基准共线
    if(n%2!=0){
        Mid=A[n/2];
        for(int i=0;i<n;i++){
            Y+=abs(A[i].y-Mid.y);
        }
    }
    else{
        Mid=A[n/2];
        for(int i=0;i<n;i++){
            Y1+=abs(A[i].y-Mid.y);
        }
        
        Mid=A[n/2-1];
        for(int i=0;i<n;i++){
            Y2+=abs(A[i].y-Mid.y);
        }
    }
    
    
    sortx(A,n);                               //按x排序，合并
    if(n%2!=0){
        Mid=A[n/2];
        for(int i=0;i<n;i++){
            X+=abs(abs(A[i].x-Mid.x)-abs(i-n/2));
        }
    }
    else{
        Mid=A[n/2];
        for(int i=0;i<n;i++){
            X1+=abs(abs(A[i].x-Mid.x)-abs(i-n/2));
        }
        
        Mid=A[n/2-1];
        for(int i=0;i<n;i++){
            X2+=abs(abs(A[i].x-Mid.x)-abs(i-n/2+1));
        }
    }
    sum1=X+Y;
    sum2=(X1+Y1)<(X2+Y2)?(X1+Y1):(X2+Y2);
    if(n%2!=0)printf("%d\n",sum1);
    else printf("%d\n",sum2);
    return 0;
}
