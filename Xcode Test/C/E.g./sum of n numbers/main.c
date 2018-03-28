//
//  main.c
//  sum of n numbers
//
//  Created by Steve X on 2017/10/5.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n,sum=0;
    printf("请输入数字个数\n");
    scanf("%d",&n);
    printf("请输入%d个数字\n",n);
    int a[n];
    for(int i=1;i<=n;i++){
        scanf("%d,",&a[i]);
        sum=sum+a[i];
    }
    printf("sum=%d\n",sum);
    return 0;
}
