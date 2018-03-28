//
//  main.c
//  NOJ34-combination
//
//  Created by Steve X on 2017/10/26.
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
    int n,m;
    scanf("%d%d",&n,&m);
    if(n>=m)printf("%d\n",C(n,m));
    else printf("wrong\n");
    return 0;
}
