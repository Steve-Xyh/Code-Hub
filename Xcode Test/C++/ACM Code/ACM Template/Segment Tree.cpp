*************************************************
         	   线段树(Segment Tree)
*************************************************

1.a.单点修改,区间查询（wys版）
-------------------------------------------------------------------
struct seg{							//线段结构
	int l,r,sum;					//区间左右端点l,r,区间和sum
}tree[maxn<<2];						//线段树数组tree

void build(int p,int l,int r)		//建树
{
	tree[p].l=l;
	tree[p].r=r;
	tree[p].sum=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}

void add(int p,int x,int y)			//在p区间把x节点的值+y
{	if(tree[p].l==tree[p].r){tree[p].sum+=y;return;}
	int mid=(tree[p].l+tree[p].r)>>1;
	if(x<=mid)add(p<<1,x,y);
	else add(p<<1|1,x,y);
	tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
}

int ask(int p,int l,int r)			//在p区间内查询[l,r]区间和
{
	if(l==tree[p].l && r==tree[p].r)return tree[p].sum;
	int mid=(tree[p].l+tree[p].r)>>1;
	if(r<=mid)return ask(p<<1,l,r);
	else if(l>mid)return ask(p<<1|1,l,r);
	else return ask(p<<1,l,mid)+ask(p<<1|1,mid+1,r);
}
-------------------------------------------------------------------



1.b.单点修改,区间查询（雨神版）
-------------------------------------------------------------------
int a[maxn],tree[4*maxn];					//节点信息a,线段树数组tree

void build(int p,int l,int r)				//建树
{		//tree数组下标p,区间左右端点l,r,初始调用为build(1,1,n)
	if(l==r){tree[p]=a[l];return;}			//l==r缩为单点,进行赋值
	int mid=(l+r)>>1;						//求区间中间点相当于(l+r)/2
	build(p*2,l,mid);						//建左右子树
	build(p*2+1,mid+1,r);					
	tree[p]=tree[p*2]+tree[p*2+1];			//区间和更新为左右子树之和
}
											
void add(int p,int l,int r,int x,int num)	//给点x增加num
{		//tree数组下标p,区间左右端点l,r,目标点x,修改值num	,初始调用为add(1,1,n,x,num)
	if(l==r){tree[p]+=num;return;}			//找到目标点,单点修改
	int mid=(l+r)>>1; 
	if(x<=mid)add(p*2,l,mid,x,num);			//二分查找目标点
	else add(p*2+1,mid+1,r,x,num);
	tree[p]=tree[p*2]+tree[p*2+1];			//更新区间和
}

int ask(int p,int l,int r,int x,int y)		//询问区间[x,y]之和
{		//tree数组下标p,查找区间[l,r],目标区间[x,y],初始调用为ask(1,1,n,x,y)
	if(x<=l&&r<=y)return tree[p];							//查找区间缩小至目标区间,直接返回结果
	int mid=(l+r)>>1;
	if(y<=mid)return ask(p*2,l,mid,x,y);					//若目标区间完全位于查找区间左半边,缩小查找区间至[l,mid]
	if(x>mid)return ask(p*2+1,mid+1,r,x,y);					//若完全位于右半边,缩小至[mid+1,r]
	return ask(p*2,l,mid,x,mid)+ask(p*2+1,mid+1,r,mid+1,y);	//若跨越中点,查找区间拆分为[l,mid]+[mid+1,r],目标区间拆分为[x,mid]+[mid+1,y]
}
-------------------------------------------------------------------



2.区间加,求区间和,最大值（wys）
-------------------------------------------------------------------
int a[maxn];
struct seg{
	int l,r;
	int sum,mx;
	int tag;
}tree[maxn<<2];

void build(int p,int l,int r)
{
	tree[p].l=l;tree[p].r=r;
	tree[p].sum=tree[p].tag=tree[p].mx=0;
	if(l==r){tree[p].mx=tree[p].sum=a[l];return;}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	push_up(p);				/***********/?????
}

void add(int p,int l,int r,long long x)
{
	if(tree[p].l==l&&tree[p].r==r){
		tree[p].sum+=1LL*(r-l+1)*x;
		tree[p].mx+=x;
		tree[p].tag+=x;
		return;
	}
	int mid=(tree[p].l+tree[p].r)>>1;
	push_down(p);			/***********/??????
	if(r<=mid)add(p<<1,l,r,x);
	else if(l>mid)add(p<<1|1,l,r,x);
	else {
		add(p<<1,l,mid,x);
		add(p<<1|1,mid+1,r,x);
	}
	push_up(p);				/***********/??????
}

long long ask_mx(int p,int l,int r)
{
	if(tree[p].l==l&&tree[p].r==r)return tree[p].mx;
	push_down(p)			/***********/??????
	long long ans=0;
	int mid=(tree[p].l+tree[p].r)>>1;
	if(r<=mid)ans=ask_mx(p<<1,l,r);
	else if(l>mid)ans=ask_mx(p<<1|1,l,r);
	else ans=max(ask_mx(p<<1,l,mid),ask_mx(p<<1|1,mid+1,r));
	push_up(p);
	return ans;
}

long long ask_sum(int p,int l,int r)
{
	if(tree[p].l==l&&tree[p].r==r)return tree[p].sum;
	push_down(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	if(r<=mid)return ask_sum(p<<1,l,r);
	if(l>mid)return ask_sum(p<<1|1,l,r);
	return ask_sum(p<<1,l,mid)+ask_sum(p<<1|1,mid+1,r);
}
-------------------------------------------------------------------





























