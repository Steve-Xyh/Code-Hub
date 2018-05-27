//  实验3.1 哈夫曼编/译码器  ##DNF##
//  main.cpp
//  NOJ-DS 33 Huffman Coding Tree
//
//  Created by Steve X on 2018/5/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#define MAXINT 0x3f3f3f
#define MAXNODE 100
#define MAXNUM 50
#define MaxLen 100
using namespace std;

struct HtNode           //哈夫曼树结点的结构
{
    int weight;
    int parent,lchild,rchild;
};

typedef struct HtTree
{
    HtNode ht[MAXNODE];
    int root;           //哈夫曼树根在数组中的位置
}HtTree,*PHtTree;

typedef struct {
    int weight;
    int parent,lchild,rchild;
} HTNode, *HuffmanTree;
typedef char  ** HuffmanCode;

void Select (PHtTree pht, int pos, int &x1, int &x2)
{
    int  m1 = MAXINT, m2 = MAXINT;     /* 相关变量赋初值 */
    for (int j=1; j<pos; j++) {/* 找两个最小权的无父结点的结点 */
        if (pht->ht[j].weight<m1 && pht->ht[j].parent == 0) {
            m2 = m1;
            x2 = x1;
            m1 = pht->ht[j].weight;
            x1 = j;
        }
        else if (pht->ht[j].weight<m2 && pht->ht[j].parent == 0) {
            m2 = pht->ht[j].weight;
            x2 = j;
        }
    }
}

PHtTree huffman (int n, int *w)
/* 构造具有n个叶结点的哈夫曼树*/
/* 数组w[1…n]中存放n个权值 */
{
    PHtTree  pht;
    int i,j,x1,x2,m1,m2;
    pht=(PHtTree) malloc (sizeof (struct HtTree));    /* 创建空哈夫曼树 */
    assert(pht);
    for( i=1; i<=2*n - 1; i++ ) {     /* 置初态 */
        pht->ht[i].lchild = 0;
        pht->ht[i].rchild = 0;
        pht->ht[i].parent = 0;
        if (i<=n)
            pht->ht[i].weight = w[i];
        else
            pht->ht[i].weight = 0;
    }
    /* 每循环一次构造一个内部结点 */
    for( i=1; i < n ; i++ ) {
        Select(pht,n+i,x1,x2);
        pht->ht[x1].parent = n + i;    /* 构造一个内部结点 */
        pht->ht[x2].parent = n + i;
        pht->ht[n+i].weight = pht->ht[x1].weight + pht->ht[x2].weight;
        pht->ht[n+i].lchild = x1;
        pht->ht[n+i].rchild = x2;
        pht->root = n+i;
    }
    return pht;
}

void TraverseHuffman (PHtTree T, char** HC, int n)
{
    static int codeLen = 0;        /* 为什么使用静态变量? */
    static char cd[MaxLen];
    if(!T)return;
    if(T->ht[n].rchild==0) {     /* Why ? */
        cd[codeLen] = '\0';
        strcpy(HC[n], cd);
    }else{
        cd[codeLen++] = '0';
        TraverseHuffman (T, HC, T->ht[n].lchild);
        codeLen--;
        cd[codeLen++]  =  '1';
        TraverseHuffman (T, HC, T->ht[n].rchild);
        codeLen--;
    }
}

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int &w,int n)
{
    int i,m=2*n-1;
    HuffmanTree p=HT;
    if(n<=1)return;
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
    for(i=1;i<=n;++i,++p,++w) *p={w, 0, 0, 0};
    for(;i<=m; ++i, ++p)*p={0,0,0,0};
    for(i=n+1;i<=m; ++i){
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;HT[s2].parent=i;
        HT[i].lchild=s1;HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
    HC=(HuffmanCode)malloc((n+1)*sizeof(char));
    char *cd=(char *)malloc(n*sizeof(char));
    cd[n-1]='\0';
    for (i=1; i<=n; ++i) {
        int start = n-1;
        for(int c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent){
            if (HT[f].lchild == c)cd[--start]='0';
            else cd[--start]='1';
        }
        HC[i]=(char *)malloc((n-start)*sizeof(char));
        strcpt (HC[i], &cd[start]);
    }
    free(cd);
}


int main()
{
    
    return 0;
}
