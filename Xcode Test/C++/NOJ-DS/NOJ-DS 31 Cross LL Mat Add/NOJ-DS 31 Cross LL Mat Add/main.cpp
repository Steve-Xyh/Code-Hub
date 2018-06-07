//  实验2.3:稀疏矩阵加法,用十字链表实现C=A+B
//  main.cpp
//  NOJ-DS 31 Cross LL Mat Add
//
//  Created by Steve X on 2018/6/6.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
using namespace std;

const int N=1e3;
int m,n,t1,t2;

struct Mat{
    int x,y,dt;
    Mat *down,*right;
    Mat():down(NULL),right(NULL){}
    Mat(int x,int y,int t=0):x(x),y(y),dt(t),down(NULL),right(NULL){}
}*hd[N];

bool flag;

void init()
{
    for(int i=0;i<N;i++){
        Mat *p=new Mat;
        hd[i]=p;
    }
}

void insertHrz(Mat * dat)   //Insert new elements horizontally
{
    Mat *pos=hd[dat->x];
    while(pos->right!=NULL&&pos->right->y < dat->y)pos=pos->right;
    if(pos->right&&pos->right->y==dat->y){
        flag=true;          //Find the very position to add,then mark it
        pos->right->dt+=dat->dt;
        return;
    }
    dat->right=pos->right;  //Insert dat on the right
    pos->right=dat;
}

void insertVrt(Mat * dat)   //Insert new elements vertically
{
    if(flag)return;         //If added horizontally,do not add vertically
    Mat *pos=hd[dat->y];
    while(pos->down!=NULL&&pos->down->x < dat->x)pos=pos->down;
    dat->down=pos->down;    //Find the vert position to insert
    pos->down=dat;          //Insert dat downward
}

void cinMatrix(int t)
{
    for(int i=0;i<t;i++){
        int x,y,d;
        cin>>x>>y>>d;
        Mat *tmp=new Mat(x,y,d);
        if(t==t2)flag=false;
        insertHrz(tmp);
        insertVrt(tmp);
    }
}

void coutMatrix()
{
    for(int i=0;i<N;i++){
        Mat *pos=hd[i]->right;
        while(pos!=NULL){
            if(pos->dt)cout<< pos->x <<' '<< pos->y <<' '<< pos->dt <<endl;
            pos=pos->right;
        }
    }
}

int main()
{
    init();
    cin>>m>>n>>t1>>t2;
    cinMatrix(t1);
    cinMatrix(t2);
    coutMatrix();
    return 0;
}
