//
//  main.cpp
//  NOJ76-link vary C++
//
//  Created by Steve X on 2017/11/16.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct Linklist{
    int age;
    struct Linklist *next;
}LIST,*LINKLIST;

LINKLIST crtlis(LINKLIST L);
LINKLIST dellis(LINKLIST L,int age);
void displis(LINKLIST L);
void destlis(LINKLIST L);
int findnum(LINKLIST L,int age);

int main(){
    LINKLIST L=crtlis(L);
    displis(L);
    destlis(L);
    return 0;
}

LINKLIST crtlis(LINKLIST L){
    int n,age;
    L=(LINKLIST)malloc(sizeof(LIST));
    L->next=NULL;
    LINKLIST p,q=NULL,test;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> age;
        if(findnum(L,age)==0){
            p=(LINKLIST)malloc(sizeof(LIST));
            p->age=age;
            p->next=NULL;
            if(i==0)L->next=p;
            else q->next=p;
            q=p;
        }
        else {
            test=dellis(L,age);
            if(test!=NULL)q=test;
        }
    }
    return L;
}

int findnum(LINKLIST L,int age){
    int cont=0;
    for(LINKLIST FIND=L->next;FIND!=NULL;FIND=FIND->next){
        if(FIND->age==age)cont++;
    }
    return cont;
}

LINKLIST dellis(LINKLIST L,int age){
    LINKLIST cp=L,mid;
    for(;cp->next!=NULL;cp=cp->next){
        if(cp->next->age==age){
            mid=cp->next;
            cp->next=mid->next;
            free(mid);
            break;
        }
    }
    if(cp->next==NULL)return cp;
    else return NULL;
}

void displis(LINKLIST L){
    LINKLIST put;
    if(L->next!=NULL){
        for(put=L->next;put->next!=NULL;put=put->next)
            printf("%d ",put->age);
        cout <<put->age<<endl;
    }
}

void destlis(LINKLIST L){
    LINKLIST p=L,q=L->next;
    while(q!=NULL){
        free(p);
        p=q;
        q=q->next;
    }
    free(p);
}
