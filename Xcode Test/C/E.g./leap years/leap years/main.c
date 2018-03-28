//
//  main.c
//  years
//
//  Created by Steve X on 2017/9/27.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
int leapyear(int i)
{
    if(i%100==0){
        if(i%400==0)return 1;
        else return 0;
    }
    if(i%4==0)return 1;
    else return 0;
}

int main()
{
    int a,X,Y;
    printf("请输入两个年份\n\n");
    scanf("%d,%d",&X,&Y);
    if(X>Y){
        a=X;
        X=Y;
        Y=a;
    }
    printf("%d-%d之间的闰年如下:\n\n",X,Y);
    int m=0;
    /*for(int i=X;i<=Y;i++)
    {
        if(i%4==0){
            if(i%100==0){
                if(i%400==0){
                    printf("%i\n",i);
                    m++;
                }
            }
            else{
                printf("%i\n",i);
                m++;
            }
        }
    }*/
    for(int i=X;i<=Y;i++){
        if(leapyear(i)==1){
            printf("%d\n",i);
            m++;
        }
    }
    printf("区间内共有%d个闰年\n",m);
    return 0;
}

