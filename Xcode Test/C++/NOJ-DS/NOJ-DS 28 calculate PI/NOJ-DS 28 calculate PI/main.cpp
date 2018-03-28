//  实验1.2 高精度计算Pi值
//  main.cpp
//  NOJ-DS 28 calculate PI
//
//  Created by Steve X on 2018/3/23.
//  Copyright © 2018年 Steve X. All rights reserved.
//
/*
#include <iostream>
using namespace std;

char pi[510]={"14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912"};

int main()
{
    int n;
    cin>>n;
    cout<<"3.";
    for(int i=0;i<n;i++)cout<<pi[i];
    cout<<endl;
    return 0;
}
*/
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int>rn;         //Rn
    list<int>sum;        //前Rn的累加和
    
    
    int n = 2000;         //计算2000位
    rn.push_back(2);     //R1的第一位初始化为2;
    sum.push_back(2);    //sum的第一位初始化为2;
    
    for(int i = 1; i < n; ++i)
        rn.push_back(0), sum.push_back(0);  //Rn和sum的其他位初始化为0
    list<int>::reverse_iterator rit1, rit2; //逆序迭代器
    list<int>::iterator it;                 //正序迭代器
    int temp, ret;
    for(int i = 1; i < 2000; i ++)
    {
        //R(n) = R(n-1)*i/(2*i+1)
        
        //乘法
        ret = 0;
        for(rit1 = rn.rbegin(); rit1 != rn.rend(); ++rit1)
        {
            temp = *rit1*i+ret;
            *rit1 = temp%10;
            ret = temp/10;
        }
        
        //除法
        ret = 0;
        for(it = rn.begin(); it != rn.end(); ++it)
        {
            temp = (*it+ret*10);
            *it = temp/(2*i+1);
            ret = temp%(2*i+1);
        }
        
        //加法,计算sum
        ret = 0;
        for(rit1 = sum.rbegin(), rit2 = rn.rbegin(); rit1 != sum.rend()&& rit2!=rn.rend(); ++rit1, ++rit2)
        {
            temp = *rit1 + *rit2+ret;
            *rit1 = temp%10;
            ret = temp/10;
        }
    }
    
    int i;
    while(cin >> i){
        it = sum.begin();
        cout << *it << ".";
        it ++;
        while(it != sum.end() && i)
        {
            cout << *it;
            it++;i--;
        }
        cout<<endl;
    }
}
