//***//并查集union-find sets//***//
int pre[N]                          //父亲结点

//查找根结点(递归写法)
int fin(int n)
{
    if(pre[n]==n)return n;
    else return pre[n]=fin(pre[n]); //根结点为父亲的父亲
}
//查找根结点(条件运算符的递归写法)
int fin(int n)
{
    return pre[n]==n?n:pre[n]=fin(pre[n]);
}

//初始化
for(int i=1;i<N;i++)pre[i]=i;
//合并a,b
void merge(int a,int b){
    int x=fin(a);
    int y=fin(b);
    pre[x]=y;
    //必要时可写成pre[min(x,y)]=max(x,y);
}

//集合数量
int cntset()
{
    int tot=0;
    for(int i=1;i<=N;i++){
        if(fin(i)==i) tot++;
    }
    return tot;
}

//求连通分量
int getnum()
{
    for(int i=0;i<N;i++)pre[i]=i;
    for(int i=0;i<edge.size();i++){
        int u=edge[i].first,v=edge[i].second;
        pre[fin(u)]=fin(v);
    }
    int tot=0;
    for(int i=0;i<N;i++)if(w[i]&&(fin(i)==i))tot++;
    return tot;
}
