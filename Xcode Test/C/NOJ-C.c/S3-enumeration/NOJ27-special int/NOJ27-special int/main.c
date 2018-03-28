//
//  main.c
//  NOJ27-special int
//
//  Created by Steve X on 2017/10/23.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int powe(int x,int y)
{
    int a=1;
    for (;y>0;y--){
        a=a*x;
    }
    return a;
}

int main()
{
    int m,n,min,max,a,g=0,s=0;
    scanf("%d%d",&m,&n);
    min=powe(10,n-1);
    max=powe(10,n)-1;
    for(int b=min;b<=max;b++){
        a=b;
        for(int i=n;i>0;i--){
            if(a%10==m&&b%m!=0){
                g++;
                s=s+b;
                break;
            }
            else a=a/10;
        }
    }
    printf("%d %d\n",g,s);
    return 0;
}
