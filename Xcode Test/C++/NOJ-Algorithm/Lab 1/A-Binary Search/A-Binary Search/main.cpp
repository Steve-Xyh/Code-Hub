//
//  main.cpp
//  A-Binary Search
//
//  Created by Steve X on 2018/11/13.
//  Copyright © 2018 Steve X. All rights reserved.
//
//  二分查找
#include <iostream>
#include <algorithm>
using namespace std;

const int N=1e4+10;
int a[N];

bool binSearch(int x,int l,int r)
{
    int mid=(l+r)>>1;
    if(a[mid]==x)return true;
    else if(l==r)return false;
    if(x<a[mid])return binSearch(x,l,mid);
    if(x>a[mid])return binSearch(x,mid+1,r);
    return false;
}

int main()
{
    int n,m,x;
    cin>>n;;
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x;
        if(binSearch(x,0,n))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
