//
//  main.cpp
//  CodeForces-922A cloning toys
//
//  Created by Steve X on 2018/2/8.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:y至少可以产生y-1个x,x可以产生2个x,y>=1,y=1时x必为0

#include <iostream>
using namespace std;

int main()
{
    int x,y;
    while(cin>>x>>y){
        if((y==1&&x)||(y<1)||(x<y-1)||((x-y+1)&1))cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
