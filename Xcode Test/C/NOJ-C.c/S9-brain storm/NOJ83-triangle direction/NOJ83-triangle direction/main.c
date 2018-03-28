//
//  main.c
//  NOJ83-triangle direction
//
//  Created by Steve X on 2017/11/16.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int main()
{
    int x1,y1,x2,y2,x3,y3;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    int p=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
    if(p<=0)printf("1\n");
    else printf("0\n");
    return 0;
}

