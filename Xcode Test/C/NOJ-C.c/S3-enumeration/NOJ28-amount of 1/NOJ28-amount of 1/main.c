//
//  main.c
//  NOJ28-amount of 1
//
//  Created by Steve X on 2017/10/24.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int powe(int x,int y)
{
    int a=1;
    for(;y>0;y--){
        a=a*x;
    }
    return a;
}

int jud(int a);

int main()
{
    int N;
    scanf("%d",&N);
    int a,g=0;
    if(N<=1000000)
        for(int b=1;b<=N;b++){
            a=b;
            while(a>0){
                if(a%10==1)g++;
                a=a/10;
            }
        }
    else g=jud(N);
    printf("%d\n",g);
    return 0;
}

int jud(int a)
{
    int g=0;
    while(a>1){
        g++;
        a=a/10;
    }
    g=g*powe(10,g-1)+1;
    return g;
}
