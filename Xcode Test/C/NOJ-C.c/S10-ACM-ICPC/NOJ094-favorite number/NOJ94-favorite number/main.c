//
//  main.c
//  NOJ94-favorite number
//
//  Created by Steve X on 2017/11/28.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#define N 100000
int PR[N];

int favorite(int a)
{
    if(a==1)return 0;
    int b=a,cnt=0,aL=0,aR=0;            //L,R分别表示向左向右查找素数
    while(!PR[a]){
        if(a<=1)break;
        a--;
        aL++;
    }
    /*while(!PR[b]){
        if(b<=1)break;
        b++;
        aR++;
    }*/
    cnt=aL;
    cnt++;                              //除以一个素数需要一步
    return cnt;
}

int main()
{
    for(int i=0;i<N;i++){               //初始化为1
        PR[i]=1;
    }
    
    PR[0]=PR[1]=0;                      //埃氏筛法
    for(int i=2;i<=N/i;i++){
        if(PR[i]){
            for(int j=i*i;j<=N;j+=i){
                PR[j]=0;
            }
        }
    }
    
    for(int i=0;i<1000;i++){
        int a,b,n=0;
        scanf("%d%d",&a,&b);
        if(a==0&&b==0)break;
        for(int i=a;i<=b;i++){
            n+=favorite(i);
        }
        printf("%d\n",n);
    }
    return 0;
}
