//
//  main.c
//  NOJ4
//
//  Created by Steve X on 2017/10/10.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
int main()
{
    int a,b,c,x;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)x=a;
    else x=b;
    if(x>c)printf("%d\n",x);
    else printf("%d\n",c);
    return 0;
}
