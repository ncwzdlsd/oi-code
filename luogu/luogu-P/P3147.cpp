#include <bits/stdc++.h>
using namespace std;

const int maxn=262150,mxt=60;
int f[mxt][maxn];

int main()
{
	int N;cin>>N;
	for(int i=1,t;i<=N;i++) cin>>t,f[t][i]=i+1;
	int ans=0;
	 for(int i=2;i<=58;++i)
        for(int j=1;j<=N;++j)
        {
            if(!f[i][j]) f[i][j]=f[i-1][f[i-1][j]];
            if(f[i][j]) ans=i;
        }
	cout<<ans;
	return 0;
}