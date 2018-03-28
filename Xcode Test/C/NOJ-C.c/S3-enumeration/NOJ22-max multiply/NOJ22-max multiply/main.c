//
//  main.c
//  NOJ22-max multiply
//
//  Created by Steve X on 2017/10/17.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int S[n],a=1,x=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&S[i]);
        if(S[i]>0){
            a*=S[i];
            x++;
        }
    }
    if(x==0)printf("-1\n");
    else printf("%d\n",a);
    return 0;
}
