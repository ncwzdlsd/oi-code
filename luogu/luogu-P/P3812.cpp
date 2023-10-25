#include <bits/stdc++.h>
using namespace std;
#define int long long

int p[55];

void insert(int x)
{
    for(int i=50;i>=0;--i)
        if(x&(1ll<<i))
        {
            if(!p[i]) {p[i]=x;break;}
            else x^=p[i];
        }
}

int pmax()
{
    int ans=0;
    for(int i=50;i>=0;--i)
		if((ans^p[i])>ans) ans^=p[i];
	return ans;
}

signed main()
{
	int n,x;cin>>n;
	for(int i=1;i<=n;i++) cin>>x,insert(x);
	cout<<pmax();
	return 0;
}