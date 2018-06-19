//  建立二叉树的二叉链表(严6.65)   
//  main.cpp
//  NOJ-DS 18 BT Pre&InOrder to PostOrder
//
//  Created by Steve X on 2018/6/7.
//  Copyright © 2018年 Steve X. All rights reserved.
//  Methods:recursion,OOP

#include <iostream>
#include <string>
using namespace std;
typedef char DataType;

struct BinTree{
    DataType c;
    BinTree *lt,*rt;
    BinTree(int c=0):c(c),lt(NULL),rt(NULL){}
    
    void rebuild(string p,string q){                            //Rebuild Bin-Tree according to the Preoeder and InOrder
        if(p==""||q=="")return;
        rebuild(p,0,(int)p.size()-1,q,0,(int)q.size()-1);
    }
    void rebuild(string p,int pL,int pR,string q,int qL,int qR){//String p,q and the Left and Right tags
        int tag,llen=0,rlen=0;
        c=p[pL];
        if(pL==pR||qL==qR)return;
        for(tag=qL;tag<=qR;tag++){                              //Tag of the root PreOrder in InOrder string q
            llen=tag-qL;                                        //Length of lt and rt
            rlen=qR-tag;
            if(p[pL]==q[tag])break;
        }
        if(llen>0){                                             //If there is a lt,rebuild it recursively
            lt=new BinTree();
            lt->rebuild(p,pL+1,pL+llen,q,qL,tag-1);             //Skip the root node,change the range to [pL+1,pL+llen] and [qL,tag-1]
        }
        if(rlen>0){                                             //If there is a rt,rebuild it recursively
            rt=new BinTree();
            rt->rebuild(p,pL+llen+1,pR,q,tag+1,qR);             //Skip the root node,change the range to [pL+llen+1,pR] and [tag+1,qR]
        }
    }
    
    void PostOrder()                                            //Output the Bin-Tree in PostOrder
    {
        if(lt)lt->PostOrder();
        if(rt)rt->PostOrder();
        cout<<c;
    }
}T;

int main()
{
    string preOrder,inOrder;
    cin>>preOrder>>inOrder;
    T.rebuild(preOrder,inOrder);
    T.PostOrder();
    cout<<endl;
    return 0;
}
