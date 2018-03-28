//
//  main.c
//  NOJ25-chase
//
//  Created by Steve X on 2017/10/19.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,a,b,L,t,s=0;
    scanf("%d%d%d%d%d",&x,&y,&a,&b,&L);
    if(a==b)printf("impossible\n");
    else {
        if ((x<y)*(a>b)<0)s=abs(x-y);
        if ((x<y)*(a<b)>0)s=L-abs(x-y);
        t=s/abs(a-b);
        printf("%d\n",t);
    }
    return 0;
}
