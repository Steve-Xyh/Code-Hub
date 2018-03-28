//
//  main.c
//  NOJ32-encryption
//
//  Created by Steve X on 2017/10/26.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int code(int n)
{
    int a[4],b=0;
    for(int i=3;i>=0;i--){
        a[i]=(n%10+5)%10;
        n=n/10;
    }
    b=a[3]*1000+a[2]*100+a[1]*10+a[0];
    return b;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",code(n));
    return 0;
}
