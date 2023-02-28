#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 100005,mod = 1000000007;

int n,f[maxn][2][2];
char s[maxn],w[maxn];

signed main() 
{
	scanf("%lld%s%s",&n,s+1,w+1);
	f[0][0][0]=1;
	for(int i=1;i<=n;++i) 
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k) 
				for(char ch1='0';ch1<='9';++ch1) 
					if(s[i]==ch1||s[i]=='?')
						for(char ch2='0';ch2<='9';++ch2) 
							if (w[i]==ch2||w[i]=='?')
								f[i][j|(ch1<ch2)][k|(ch1>ch2)]=(f[i][j|(ch1<ch2)][k|(ch1>ch2)]+f[i-1][j][k])%mod;
	cout<<f[n][1][1];
	return 0;
}