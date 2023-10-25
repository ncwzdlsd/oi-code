#include <bits/stdc++.h>
using namespace std;

const int maxn=3e4+5,maxm=35;
int f[maxn],w[maxm],v[maxm];

int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>v[i]>>w[i],w[i]*=v[i];
	for(int i=1;i<=m;i++)
        for(int j=n;j>=v[i];j--)
            if(j>=v[i])
                f[j]=max(f[j],f[j-v[i]]+w[i]);
    cout<<f[n]<<endl;
    return 0;
}