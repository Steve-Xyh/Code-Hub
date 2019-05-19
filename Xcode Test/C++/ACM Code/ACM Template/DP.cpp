*************************************************
         动态规划DP(Dynamic Programming)
*************************************************


1.最大连续子段和
//dp[i]表示以第i个元素为结尾的最大连续子段和
dp[1]=a[1];
for(int i=2;i<=N;i++)dp[i]=max(a[i],dp[i-1]+a[i]);
int ans=0;
for(int i=1;i<=N;i++)ans=max(ans,dp[i]);


2.最长上升子序列
//dp[i]表示前i个元素的LIS(最长上升子序列)
for(int i=1;i<=N;i++){
    dp[i]=1;
    for(int j=1;j<i;j++)if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+1);
    //a[i]定位最后一个,a[j]从前向后搜索
}
int ans=1;
for(int i=1;i<=N;i++)ans=max(ans,dp[i]);


3.最⻓公共⼦序列
//dp[i][j]表示A串前i个字符和B串前j个字符的LCS(最⻓公共子序列)
int la=strlen(a);
int lb=strlen(b);
for(int i=1;i<=la;i++){
    for(int j=1;j<=lb;j++){
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        if(a[i-1]==b[j-1])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    }
}


4.01背包
void bag01(int cost,int weight){
    for(i=v;i>=cost;--i)dp[i]=max(dp[i],dp[i-cost]+weight);
}

5.完全背包
void complete(int cost,int weight){
    for(i=cost;i<=v;++i)dp[i]=max(dp[i],dp[i-cost]+weight);
}

6.多重背包
void multiply(int cost,int weight,int amount){
    if(cost*amount>=v)complete(cost,weight);
    else{
        k=1;
        while(k<amount){
            bag01(k*cost,k*weight);
            amount-=k;
            k+=k;
        }
        bag01(cost*amount,weight*amount);
    }
}


7.其他背包算法
int dp[1000000];
int c[55],m[110];
int sum;

void CompletePack(int c){
    for(int v=c;v<=sum/2;++v)dp[v]=max(dp[v],dp[v-c]+c);
}

void ZeroOnePack(int c){
    for(int v=sum/2;v>=c;--v)dp[v]=max(dp[v],dp[v-c]+c);
}

void multiplePack(int c,int m){
    if(m*c>sum/2)CompletePack(c);
    else{
        int k=1;
        while(k<m){
            ZeroOnePack(k*c);
            m-=k;
            k<<=1;
        }
        if(m!=0)ZeroOnePack(m*c);
    }
}
