//  实验3.1 哈夫曼编/译码器  ##DNF##
//  main.cpp
//  NOJ-DS 33 Huffman Coding Tree
//
//  Created by Steve X on 2018/5/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

typedef struct Tree{
    int w;
    char c;
    Tree *lt,*rt,*pre;
    Tree(int w=0,char c=0):w(w),c(c),lt(NULL),rt(NULL),pre(NULL){}
}*PTree;

PTree t[110],dt[110],root;
int ww[110],n,cnt;
char cc[110];

void buildTree(){                                           //建树
    while (1){
        if (n == 0) break;
        
        int min1 = 2e9, pos1 = -1;
        for (int i = 0; i <= n; ++i)if(t[i] && min1 > t[i] -> w){
            min1 = t[i] -> w; pos1 = i;                     //找最小权值结点作为左子树
        }
        
        int min2 = 2e9, pos2 = -1;
        for (int i=0;i<=n;++i)if(t[i]&&min2>t[i]->w)if(i!=pos1){
            min2 = t[i] -> w; pos2 = i;                     //找次小权值结点作为右子树
        }
        
        Tree *tmp = new Tree(t[pos1] -> w + t[pos2] -> w);  //tmp结点为左右子树之和
        tmp -> lt = t[pos1]; tmp -> rt= t[pos2];
        t[pos1] -> pre = tmp; t[pos2]->pre=tmp;             //将tmp设为左右子树的父结点
        dt[cnt++] = t[pos1]; dt[cnt++] = t[pos2];
        
        int fir = pos1 > pos2 ? pos1 : pos2;                //删除最小&次小结点
        int sec = pos1 + pos2 - fir;
        for (int i = fir; i <= n; ++i) t[i] = t[i + 1];
        for (int i = sec; i <= n; ++i) t[i] = t[i + 1];
        t[--n] = tmp;
    }
    root = t[0];
}

string getCode(string str) {                                //编码
    string ret = "";
    for (unsigned i = 0; i < str.length(); ++i) {
        string tmp = "";
        Tree *now = NULL;
        for (int j = 0; j < cnt; ++j)if (dt[j] -> c == str[i]) {
            now = dt[j];
            break;
        }
        while (now && now -> pre) {
            if (now == now -> pre -> lt) tmp += '0';        //左子树编为0
            else if (now == now -> pre -> rt) tmp += '1';   //右子树编为1
            now = now -> pre;
        }
        for (int j = (int)tmp.length() - 1; j >= 0; --j) ret += tmp[j];
    }
    return ret;
}

string getMessage(string code){                             //译码
    string ret = "";
    for (unsigned i = 0; i < code.length(); ) {
        Tree *now = root;
        while (1) {
            if (code[i] == '0') {
                if (now -> lt == NULL) {
                    ret += now -> c;                        //编码为0,取左子树字符
                    break;
                } else now = now -> lt;
            } else {
                if (now -> rt == NULL) {
                    ret += now -> c;                        //编码为1,取右子树字符
                    break;
                } else now = now -> rt;
            }
            ++i;
        }
    }
    return ret;
}

int main() {
    cin >> n;--n;
    for (int i = 0; i <= n; ++i) cin >> cc[i];
    for (int i = 0; i <= n; ++i) {
        cin >> ww[i];
        t[i] = new Tree(ww[i], cc[i]);
    }
    buildTree();
    string str; cin >> str;
    string ans = getCode(str);
    cout << ans << endl;
    cout << getMessage(ans) << endl;
}
