//
//  main.c
//  NOJ26-permutation&combination
//
//  Created by Steve X on 2017/10/21.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int A(int m,int n)
{
    int a=m;
    for (;n>1;n--){
        a=a*(m-1);
        m--;
    }
    return a;
}

int C(int m,int n)
{
    int b,c;
    b=A(m,n);
    c=A(n,n);
    return b/c;
}

int main()
{
    int m,n;
     scanf("%d%d",&m,&n);
     printf("%d\n",A(m,n));
     printf("%d\n",C(m,n));
    return 0;
}

