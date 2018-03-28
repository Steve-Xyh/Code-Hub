//
//  main.c
//  NOJ37-reverse output
//
//  Created by Steve X on 2017/10/27.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int reverse(int x)
{
    int a=0,b=0;
    while(x>0){
        b=x%10;
        x=x/10;
        a=a*10+b;
    }
    return a;
}

int main()
{
    int x;
    scanf("%d",&x);
    printf("%d\n",reverse(x));
    return 0;
}
