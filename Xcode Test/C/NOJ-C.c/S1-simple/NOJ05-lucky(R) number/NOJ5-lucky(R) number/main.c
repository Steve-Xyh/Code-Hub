//
//  main.c
//  NOJ5-lucky(R) number
//
//  Created by Steve X on 2017/10/10.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
int luckynumber(int n)
{
    int r=0;
    while(n!=0){
        r=r*10+n%10;
        n=n/10;
    }
    return r;
}
int main()
{
    int n;
    scanf("%d",&n);
    int r=luckynumber(n);
    if(r==n)printf("yes\n");
    else printf("no\n");
    return 0;
}
