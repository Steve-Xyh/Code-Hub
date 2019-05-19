//  CHD-ACM
//  main.cpp
//  L-Big Boss
//  https://www.nowcoder.com/acm/contest/102/L
//  Created by Steve X on 2018/4/14.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int log9(int a)
{
    return (int)(1.0*log(a)/log(9));
}

int power(int a,int r)
{
    int ans=1;
    while(r--)ans*=a;
    return ans;
}

int judge(int a,int b,int x)
{
    if(min(abs(a-x),abs(b-x))==abs(a-x))return a;
    else return b;
}

int CalBill(int x,int cnt)
{
    int r=log9(x),a=power(9,r),b=power(a,r+1),m=judge(a,b,x);
    int lt=x/9*9,rt=lt+9;
    if(r<=4){
        cnt++;
        x-=power(9,r);
    }
    else{
        int n=power(9,r-4);
        cnt+=n;
        x-=power(9,n);
    }
    if(x==0)return cnt;
    else return CalBill(x,cnt);
}

int main()
{
    int cnt=0;
    
    return 0;
}
