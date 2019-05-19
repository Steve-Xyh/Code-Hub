//  HYSBZ-2456
//  main.cpp
//  A-mode
//  https://vjudge.net/contest/207828#problem
//  Created by Steve X on 2018/1/30.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:主元素.与ans相同cnt++,不同cnt--,cnt=0时更新ans.时空限制用stdio

#include <cstdio>

void modenum(int n)
{
    int cnt=0;
    long x,ans=-1;
    
    for(int i=0;i<n;i++){
        scanf("%ld",&x);
        if(!i){
            ans=x;
            cnt=1;
        }
        else{
            if(x==ans)cnt++;
            else{
                cnt--;
                if(!cnt){
                    ans=x;
                    cnt=1;
                }
            }
        }
    }
    printf("%ld\n",ans);
}

int main()
{
    int n;
    scanf("%d",&n);
    modenum(n);
    return 0;
}
