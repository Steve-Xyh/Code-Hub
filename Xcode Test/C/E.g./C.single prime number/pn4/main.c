//
//  main.c
//  pn4
//
//  Created by Steve X on 2017/10/3.
//  Copyright © 2017年 apple. All rights reserved.
//
#include <stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=2;i<=n-1;i++){
          if(n%i==0)break;
    }
    if(n!=i)printf("NO\n");
    else printf("YES\n");
}
