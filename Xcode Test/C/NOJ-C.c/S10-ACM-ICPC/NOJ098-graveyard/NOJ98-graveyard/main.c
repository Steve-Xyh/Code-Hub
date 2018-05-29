//
//  main.c
//  NOJ98-graveyard
//
//  Created by Steve X on 2017/11/30.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#define N 1000

int main()
{
    int cur[N],add[N],i;
    double dis[N];
    for(i=0;;i++){
        double dist,ave;
        scanf("%d%d",&cur[i],&add[i]);
        if(cur[i]==0&&add[i]==0)break;
        dist=10000.0/(cur[i]+add[i]/cur[i]*cur[i]); //插入倍数后不需移动的间距
        ave=10000.0/(cur[i]+add[i]);                //最终间距
        dis[i]=(cur[i]+(add[i]/cur[i]*cur[i])-1-(add[i]/cur[i]))*(dist-ave); //初始其中1个不需移动，____不需移动，其余每个移动dist-ave
    }
    for(int j=0;j<i;j++){
        printf("%.4lf\n",dis[j]);
    }
    return 0;
}
