//
//  main.cpp
//  H-sort
//
//  Created by Steve X on 2017/12/28.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define N 1000
using namespace std;

struct tshirt {
    int no;
    double sati;
}C[N];
double A[N][N];

bool cmps(tshirt a,tshirt b)
{
    return a.sati!=b.sati?a.sati>b.sati:a.no<b.no;
}
bool cmpn(tshirt a,tshirt b)
{
    return a.no>b.no;
}

int main()
{
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(int i=0;i<N;i++){
            C[i].sati=0;
            C[i].no=i;
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                scanf("%lf",&A[i][j]);
                C[j].sati+=A[i][j];
            }
        }
        sort(C+1,C+m+1,cmps);
        sort(C+1,C+k+1,cmpn);
        for(int i=1;i<=k;i++){
            if(i!=1)cout<<" ";
            cout<<C[i].no;
        }
        cout<<endl;
    }
    return 0;
}
