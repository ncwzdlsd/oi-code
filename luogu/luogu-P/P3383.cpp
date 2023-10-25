#include <bits/stdc++.h>
using namespace std;

const int maxn=1e8+5;
int v[maxn],prime[maxn];

void primes(int n)
{
    memset(v,0,sizeof(v));//存储最小质因子
    int m=0;//质数数量
    for(int i=2;i<=n;i++)
    {
        if(v[i]==0)
        {
            v[i]=i;
            prime[++m]=i;
        }
        for(int j=1;j<=m;j++)
        {
            //i有比prime[j]更小的质因子或者超出n的范围
            if(prime[j]>v[i]||prime[j]>n/i) break;
            v[i*prime[j]]=prime[j];
        }
    }
}

int main()
{
	int n,q;cin>>n>>q;
	primes(n);
	for(int i=1;i<=q;i++)
	{
		int k;cin>>k;
		cout<<prime[k]<<endl;
	}
	return 0;
}