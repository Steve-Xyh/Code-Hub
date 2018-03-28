//
//  main.c
//  NOJ11-x^a
//
//  Created by Steve X on 2017/10/13.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int main()
{
    int x,a;
    int s=1;
    scanf("%d%d",&x,&a);
    for(int i=1;i<=a;i++){
        s=s*x%1000;
    }
    printf("%d",s);
    return 0;
}
