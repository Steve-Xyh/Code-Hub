//动态规划DP(Dynamic Programming)

//1.最大连续子段和
//dp[i]表示以第i个元素为结尾的最大连续子段和
dp[1]=a[1];
for(int i=2;i<=N;i++)
{
    dp[i]=max(a[i],dp[i-1]+a[i]);
}
int ans=0;
for(int i=1;i<=N;i++)
{
    ans=max(ans,dp[i]);
}


//2.最长上升子序列
//dp[i]表示前i个元素的LIS(最长上升子序列)
for(int i=1;i<=N;i++)
{
    dp[i]=1;
    for(int j=1;j<i;j++)
    {
        if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);  //a[i]定位最后一个,a[j]从前向后搜索
    }
}
int ans=1;
for(int i=1;i<=N;i++)
{
    ans=max(ans,dp[i]);
}

