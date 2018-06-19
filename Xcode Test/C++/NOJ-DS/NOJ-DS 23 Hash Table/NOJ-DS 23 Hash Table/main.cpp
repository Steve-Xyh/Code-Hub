//  构造哈希表(耿8.12)    ##special##
//  main.cpp
//  NOJ-DS 23 Hash Table
//
//  Created by Steve X on 2018/5/30.
//  Copyright © 2018年 Steve X. All rights reserved.
//  选取哈希函数H(k)=(3k)%11,用线性探测再散列法处理冲突.试在0-10的散列地址空间中,
//  编写程序,对关键字序列 (22,41,53 46,30,13,01,67)构造哈希表,并求等概率情况下查找成功的平均查找长度.

//#define special                                 //Special method definition
#include <iostream>
#include <cstring>
using namespace std;

const int N=10;
const int n=8;

class HashTable{
public:
    int Hash[N],len[N];
    
    int H(int k){                               //Hash Function
        return (3*k)%11;
    }
    
    void create(int a[]){                       //Create Hash Table and calculate searching length
        for(int i=0;i<N;i++){
            Hash[i]=-1;
            len[i]=0;
        }
        for(int i=0;i<n;i++){
            if(!~Hash[H(a[i])]){                //If the position is available,occupy it
                Hash[H(a[i])]=a[i];
                len[H(a[i])]=1;
            }
            else{                               //Otherwise,move to the next until it is available
                int srchlen=1;
                for(int j=H(a[i])+1;j<N;j++){
                    srchlen++;
                    if(!~Hash[j]){
                        Hash[j]=a[i];
                        len[j]=srchlen;         //Record the searching length
                        break;
                    }
                }
            }
        }
    }
    
    int sucasl(){                               //Calculate the Successful Average Searching Length
        int sum=0;
        for(int i=0;i<N;i++)sum+=len[i];
        return sum/n;
    }
}HT;

int main()
{
    int a[N]={22,41,53,46,30,13,1,67};
    HT.create(a);
    cout<<HT.sucasl()<<endl;
    
#ifdef special
    cout<<2<<endl;
#endif
    return 0;
}
