//
//  main.c
//  years
//
//  Created by Steve X on 2017/9/27.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>

int main()
{
    printf("1900-2016之间的闰年如下:\n\n");
    for(int i=1990;i<=2016;i++)
    {
        if(i%4==0){
            if(i%100==0){
                if(i%400==0){
                    printf("%i\n",i);
                }
            }
            else{
                printf("%i\n",i);
            }
        }
    }
    return 0;
}

