#include<bits/stdc++.h>
using namespace std;

int f[10005];
vector<int> v[10005];
int main()
{
	int n,k;cin>>n>>k;
    while(k--)
    {
    	int p,t;cin>>p>>t;
        v[p].push_back(t);
    }
    for(int i=n;i;--i)
    {
        if(v[i].size())
            for(int j=0;j<v[i].size();++j)
                f[i]=max(f[i],f[i+v[i][j]]);
        else f[i]=f[i+1]+1;            
    }
	cout<<f[1];
	return 0;
}