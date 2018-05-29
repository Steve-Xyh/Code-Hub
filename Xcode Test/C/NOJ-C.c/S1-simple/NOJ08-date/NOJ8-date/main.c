//
//  main.c
//  NOJ8-date
//
//  Created by Steve X on 2017/10/12.
//  Copyright © 2017年 Steve X. All rights reserved.
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

int month(int y,int m)
{
    int a;
    switch (m){
        default:a=31;break;
        case 2:if(leapyear(y)==1)a=29;
        else a=28;
            break;
        case 4:case 6:case 9:case 11:a=30;break;
    }
    return a;
}

int main()
{
    int y,m,d;
    scanf("%d-%d-%d",&y,&m,&d);
    int a=0,summ=0,sumd;
    for(int i=1;i<m;i++){
        a=month(y,i);
        summ=summ+a;
    }
    sumd=summ+d;
    printf("%d\n",sumd);
    return 0;
}
