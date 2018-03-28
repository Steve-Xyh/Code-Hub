//
//  main.c
//  NOJ26-permutation&combination
//
//  Created by Steve X on 2017/10/21.
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

int com(int n)
{
    if (n<3)return 0;
    else if(n==3)return 1;
    else if(n==4)return 3;
    else return 2*com(n-1)+powe(2,n-4)-com(n-4);
}

int main()
{
    int n;
    scanf("%d",&n);
    int s=com(n);
    printf("%d\n",s);
    return 0;
}
