//
//  main.c
//  NOJ33-A+B time
//
//  Created by Steve X on 2017/10/26.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

void t(int h,int m,int s)
{
    if(s>=60){
        m=m+s/60;
        s=s%60;
    }
    if(m>=60){
        h=h+m/60;
        m=m%60;
    }
    printf("%d %d %d\n",h,m,s);
}

int main()
{
    int AH,AM,AS,BH,BM,BS,h,m,s;
    scanf("%d%d%d%d%d%d",&AH,&AM,&AS,&BH,&BM,&BS);
    h=AH+BH;
    m=AM+BM;
    s=AS+BS;
    t(h,m,s);
    return 0;
}
