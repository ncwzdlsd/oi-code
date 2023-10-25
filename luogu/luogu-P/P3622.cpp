#include<bits/stdc++.h>
using namespace std;

const int maxn=50005;
int n,m,ans,f[maxn][40],num[maxn][40];

int main()
{
	cin>>n>>m;
    for(register int i=1;i<=m;++i)
    {
    	int a,b,c,tmp,like=0,fear=0; 
		cin>>a>>b>>c;
        for(int j=1;j<=b;++j) cin>>tmp,tmp=(tmp-a+n)%n,fear|=1<<t;
        for(int j=1;j<=c;++j) cin>>tmp,tmp=(tmp-a+n)%n,like|=1<<t;
        for(int j=0;j<32;++j)
		  if(((j&fear)||(~j&like)))++num[a][j]; 
    }    
    for(int i=0;i<32;++i)
    {
        memset(f[0],128,sizeof(f[0]));
        f[0][i]=0;
        for(int j=1;j<=n;++j) 
        	for(int s=0;s<32;++s) 
            	f[j][s]=max(f[j-1][(s&15)<<1],f[j-1][(s&15)<<1|1])+num[j][s];
        if(ans<f[n][i])ans=f[n][i];
    }
	cout<<ans;
    return 0;
}