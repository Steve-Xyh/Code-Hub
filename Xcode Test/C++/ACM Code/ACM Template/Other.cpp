1.二进制表
void binarylist(long long b[])		//b[i]为i的二进制形式
{
	b[0]=0;
	b[1]=1;
	for(int i=2;i<N;i++)b[i]=10*b[i/2]+1%2;
}