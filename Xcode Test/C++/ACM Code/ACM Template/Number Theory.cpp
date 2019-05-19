*************************************************
			   数论(Number Theory)
*************************************************					

1.求两个数的最大公约数和最小公倍数(gcd&lcm)
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
	return a/gcd(a,b)*b;	//先除后乘更安全
}
该算法的时间复杂度为O(logn)。
用该方法求斐波那契数列中相邻两项的最大公约数时，将消耗最多的时间。


2.求方程𝒂𝒙+𝒃𝒚=𝐠𝐜𝐝⁡(𝒂,𝒃)的一组解
  结论：该方程有解当且仅当𝐠𝐜𝐝⁡(𝒂,𝒃)|𝑳。
  结论：先解方程𝒂𝒙+𝒃𝒚=𝒈，设该方程的一组解为(𝒙_𝟎,𝒚_𝟎)，那么通解为(𝒙_𝟎+𝒃/𝒈*𝒕,𝒚_𝟎−𝒂/𝒈*𝒕)
//参数a和b即为方程中的a和b，引用x和y存放方程的一组解
long long ex_gcd(long long a,long long b,long long &x,long long &y) 
{
    if(b==0){                  //注意对比与gcd函数的相似处，都以b==0为递归边界
		x=1;    
		y=0;
		return a;
	}
	else{
		long long r=ex_gcd(b,a%b,y,x);	//注意交换x和y，然后再对y进一步运算
		y-=x*(a/b);
		return r;
	}
}
该算法的时间复杂度为O(logn)。


3.求正整数n的标准分解式(素因子分解)
int p[maxn],a[maxn],cnt;
void getFactor()
{
	int now=n;
    for(int i=2;i<=n/i;i++){     //i<=n/i等价于i*i<=n,i<=sqrt(n)
		if(now%i==0){
			p[++cnt]=i;
			a[cnt]=0;
			while(now%i==0){
				a[cnt]++;
				now/=i;
			}
		}
	}
	if(now!=1){
		p[++cnt]=now;
		a[cnt]=1;
	}
}
该算法的时间复杂度为O(√𝑛)。
这里的素因子分解是没有提前维护素数表的。


4.素数筛法
//素数筛
bool isprime[1~n];//**************************
memset(isprime,true,sizeof(isprime));
for(int i=2;i<=n;i++){
    if(isprime[i]){
        for(int j=2*i;j<=n;j+=i){
            isprime[j]=false;
        }
    }
}

//Eratosthenes筛法(埃氏筛),O(n*log(log n))
bool isprime[1~n];
void Eratosthenes()
{
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=n/i;i++)                //除法更安全
        if(isprime[i])                     //用遇到的素数去筛合数
            for(int j=i*i;j<=n;j+=i)
                isprime[j]=false;
}

//Euler筛法(欧氏筛)
bool isprime[1~n];
int primenum[maxn],cnt;
void Euler()
{
	memset(isprime,true,sizeof(isprime));
	isprime[1]=false;
	for(int i=2;i<=n;i++){
		if(isprime[i]) primenum[++cnt]=i;
		for(int j=1;j<=cnt&&i*primenum[j]<=n;j++){
			isprime[i*primenum[j]]=false;
			if(i%primenum[j]==0)break;    //最为关键的一句话
		}
	}
}
该算法的时间复杂度为O(n)。		

/*Miller-Rabin米勒罗宾素数判定法(利用费马小定理，二次剩余定理)
 *随机测试t次
 */

5.扩展欧几里得求逆元
要求一个数a在模p乘法下的逆元x，就是要解方程𝑎𝑥≡1(𝑚𝑜𝑑 𝑝)。
这个方程还可以写成这样的形式：𝑎𝑥=𝑘𝑝+1，亦即𝑎𝑥+𝑘𝑝=1,𝑘∈𝑍。看到这个方程有没有联想到什么？

long long mod_reverse(long long a, long long p){
	long long x,y;
	long long d=extend_gcd(a,p,x,y);
	if(d==1) return (x%M+M)%M;
	else return -1;
}
有扩展欧几里得部分的知识，我们不难发现a的模p乘法逆元存在的充要条件是a和p互素。另外一提，这种求逆元的算法是通用方法。


6.费马小定理求逆元
对于素数p和与p互素的整数a，𝑎^(𝑝−1)≡1(𝑚𝑜𝑑 𝑝)恒成立。
回顾模p乘法逆元的定义：求x使得𝑎𝑥≡1(𝑚𝑜𝑑 𝑝)。容易发现，当p为素数时，𝑎^(𝑝−2)就是a的一个模p乘法逆元。
[代码实现]用费马小定理求a的模p乘法逆元
//费马小定理求a的模p乘法逆元,O(p),p为素数
long long inv(long long a, long long p)
{
	long long ans=1;
	for(int i=1;i<=p-2;i++){
		ans=ans*a%p;
	}
	return ans;
}
该算法的时间复杂度为O(p)，且具有一定的局限性——要求p必须是素数。


7.快速幂运算(循环写法)
long long pow_mod(long long a,long long x,long long p)
{
	long long tmp=a%p,ans=1;
	while(x>=1){
		if(x%2==1)ans=ans*tmp%p;     //if里的条件也可以写成x&1
		tmp=tmp*tmp%p;
		x=x/2;
	}
	return ans;
}

8.快速幂运算(递归写法)
long long pow_mod(long long a,long long x,long long p)
{
	if(x==0) return 1;
	long long tmp=pow_mod(a,x/2,p);
	tmp=tmp*tmp%p;
	if(x&1) tmp=tmp*a%p;
	return tmp;
}
无论是循环写法还是递归写法，快速幂运算的时间复杂度为O(logx)。
但值得一提的是，循环写法比递归写法更快一些。


9.用费马小定理求a的模p乘法逆元
我们回到原来的话题——用费马小定理求模p乘法下的逆元。
long long inv(long long a, long long p)
{
	return pow_mod(a,p-2,p);
}
该算法的时间复杂度为O(logp)。


10.递推法求[1,n]内所有数的模p乘法逆元
long long inv[1~n];
void getInv()
{
	inv[1]=1;
	for(int i=2;i<=n;i++){
		inv[i]=(p-p/i)*inv[p%i]%p;
	}
}
如果使用之前求单个逆元的方法来求区间内所有数的逆元，复杂度为O(nlogp)。
该算法的时间复杂度为O(n)。


11.解一元模线性方程𝒂𝒙≡𝒃(𝒎𝒐𝒅 𝒏)
vector<long long> linearModEquation(long long a,long long b,long long n)
{
	long long x,y;
	long long g=ex_gcd(a,n,x,y);	    //直接调用exgcd
	vector<long long> ans;
	ans.clear();
    if(b%d==0){	                        //如果有解
		x%=n,x+=n,x%=n;
		ans.push_back(x*(b/d)%(n/g));	//得到一个解
		for(int i=1;i<g;i++)
			ans.push_back((ans[0]+i*(n/g))%n);	
	}
	return ans;
}


12.中国剩余定理 求一元模线性方程组𝒙≡𝒂_𝒊 (𝒎𝒐𝒅 𝒎_𝒊 ),𝟎≤𝒊<𝒏,且𝒎_𝟎,𝒎_𝟏,…,𝒎_(𝒏−𝟏)两两互质
long long CRT(long long a[],long long m[],int n)
{
	long long M=1;
	for(int i=0;i<n;i++) M*=m[i];	//先将所有模数的乘积算出来
	long long ans=0;
	for(int i=0;i<n;i++){
		long long x,y;
		long long tmp=M/m[i];	    //得到定理中的𝑀_𝑖
		ex_gcd(tmp,m[i],x,y);	    //使用exgcd解方程
		ans=(ans+tmp*x%M*a[i]%M)%M;	//将该次的结果加到ans中
	}
	return (ans+M)%M;
}


13.求组合数𝑪_𝒏^𝒎
long long getComb(long long n,long long m)
{
	if(m>n-m) m=n-m;	   //利用组合数的对称性
	long long a=1,b=1;
	for(long long i=n;i>=n-m+1;i--) a*=i;
	for(long long i=m;i>=1;i--) b*=i;
	return a/b;
}


14.求组合数表𝑪_𝒊^𝒋%𝒑,𝟏≤𝒊≤𝒏,𝟎≤𝒋≤𝒊，其中n为𝟏𝟎^𝟑级别
long long comb[n+5][n+5],p;
void getCombList()
{
	comb[1][0]=comb[1][1]=1%p;	//初始化
	for(int i=2;i<=n;i++){
		comb[i][0]=1;	        //初始化
		for(int j=1;j<=i;j++)
			comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%p;
	}
}


15.卢卡斯（Lucas）定理求𝑪_𝒏^𝒎%𝒑，其中𝒏为𝟏𝟎^𝟏𝟖级别， 𝒑为𝟏𝟎^𝟓到𝟏𝟎^𝟔级别
long long Lucas(long long n,long long m,long long p)
{
	long long ans=1;
    while(n!=0 && m!=0){	        //获得n和m的p进制表达式的每一位
		ans=ans*getComb(n%p,m%p,p);	//计算乘积
		n/=p,m/=p;
	}
	return ans;
}

[代码实现]Lucas定理中的getComb()函数
long long getComb(long long n,long long m,long long p)
{
	if(n<m) return 0;		//*****非常重要
	if(m>n-m) m=n-m;	    //组合数的对称性
	long long a=1,b=1;
	for(long long i=n;i>=n-m+1;i--) a=a*i%p;
	for(long long i=m;i>=1;i--) b=b*i%p;
	return a*getInv(b)%p;	//getInv()求逆元
}
