//  线性表的就地逆置(耿2.9)
//  main.cpp
//  NOJ-DS 2 reverse
//
//  Created by Steve X on 2018/3/17.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#define N 1000
using namespace std;

int a[N],n;
struct LINKLIST{
    int dat;
    LINKLIST *next;
};

void Inputlist(LINKLIST *head)
{
    LINKLIST *p1=head,*p2;
    for(int i=0;i<n;i++){
        cin>>a[i];
        p2=new LINKLIST;
        p2->dat=a[i];
        p1->next=p2;
        p1=p2;
        p2->next=NULL;
    }
}

void Reverselist(LINKLIST *head)
{
    LINKLIST *p=head->next;
    LINKLIST *q=NULL;
    head->next=NULL;
    while(p){
        LINKLIST *r=p->next;
        p->next=q;
        q=p;
        p=r;
    }
    head->next=q;
}

void Display(LINKLIST *head)
{
    for(int i=n-1;i>=0;i--)cout<<a[i]<<" ";
    cout<<endl;
    LINKLIST *p=head->next;
    while(p){
        cout<<p->dat<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    LINKLIST *head=new LINKLIST;
    cin>>n;
    Inputlist(head);
    Reverselist(head);
    Display(head);
    return 0;
}
