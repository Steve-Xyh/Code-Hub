//
//  main.c
//  NOJ36-amiable numbers
//
//  Created by Steve X on 2017/10/27.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int ami(int x)
{
    int s=0;
    for(int i=1;i<x;i++){
        if(x%i==0)s=s+i;
    }
    return s;
}

int main()
{
    int A,B;
    scanf("%d%d",&A,&B);
    //printf("%d\n",ami(A));
    if(ami(A)==B)printf("YES\n");
    else printf("NO\n");
    return 0;
}
