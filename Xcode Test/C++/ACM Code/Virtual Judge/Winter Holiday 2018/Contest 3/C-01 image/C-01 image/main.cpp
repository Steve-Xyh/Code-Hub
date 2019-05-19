//
//  main.cpp
//  C-01 image
//
//  Created by Steve X on 2018/1/20.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100
using namespace std;
int A[N][N];

int main(){
    //int A[N][N];
    int m,n,tag[N],mark[N][4];
    char c;
    while (scanf("%d%d",&m,&n)!=EOF){
        int cnt=1;
        memset(A,0,sizeof(A));
        memset(mark,0,sizeof(mark));
        for(int i=0;i<n;i++){
            tag[i]=0;
            int p=0;
            for(int j=0;j<m;j++){
                cin>>c;
                A[i][j]=c-'0';
                if(A[i][0]==0&&j>0&&A[i][j]!=A[i][j-1]){
                    tag[i]++;
                    mark[i][p++]=j;
                }
                if(A[i][0]!=0)tag[i]=10;
            }
            
        }
        
        
        //if(k==0){
            for(int i=0;i<n;i++){
                
                if((tag[i]!=2&&tag[i]!=4)&&(tag[0]!=0||tag[n-1]!=0)){
                    cnt=-1;
                    //k++;
                    break;
                }
                
                if(tag[i]==4){
                    cnt=0;
                    break;
                }
            }
        //}
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0&&mark[i][0])
            }
        }
        
        cout<<cnt<<endl;
    }
    return 0;
}
