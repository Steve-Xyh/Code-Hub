//
//  main.c
//  NOJ92-road trip
//
//  Created by Steve X on 2017/11/22.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n,s[10][10],t[10][10],d[10],j=0;
    while(1){
        scanf("%d",&n);
        if(n==-1)break;
        d[j]=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&s[j][i],&t[j][i]);
            if(i>0)d[j]+=s[j][i]*(t[j][i]-t[j][i-1]);
            else d[j]+=s[j][i]*t[j][i];
        }
        j++;
    }
    for(int i=0;i<j;i++){
        printf("%d\n",d[i]);
    }
    return 0;
}
