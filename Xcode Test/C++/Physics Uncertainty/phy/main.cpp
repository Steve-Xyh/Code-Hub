//  uncertainty
//  main.cpp
//  phy
//
//  Created by Steve X on 2018/6/11.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

const int N=100;
const double delta=0.5*0.001;
const double C=sqrt(3);
const double tp=1.11;
int n;
double x[N];

double average(double a[],int n)
{
    double sum=0;
    for(int i=0;i<n;i++)sum+=a[i];
    return 1.0*sum/n;
}

double uncertaintyA(double x[])
{
    double ave=average(x,n),ans=0;
    for(int i=0;i<n;i++)ans+=(x[i]-ave)*(x[i]-ave);
    ans/=1.0*n*(n-1);
    ans=tp*sqrt(ans);
    return ans;
}

double uncertaintyB()
{
    return 1.0*delta/C;
}

int main()
{
    while(cin>>n){
        memset(x,0,sizeof(x));
        for(int i=0;i<n;i++)cin>>x[i];
        cout<<"A Uncertainty: "<<uncertaintyA(x)<<endl;
        cout<<"B Uncertainty: "<<uncertaintyB()<<endl<<endl;
    }
    
    return 0;
}
