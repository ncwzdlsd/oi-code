#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve()
{
	int ans=0;
	char c;
	while(cin>>c)
	{
		if(c=='x') ans++;
        if(c=='(') ans+=solve();
        if(c==')') return ans;
        if(c=='|') return max(ans,solve());
	}
	return ans;
}

signed main()
{
	cout<<solve();
	return 0;
}