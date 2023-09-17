#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int a,b,c;cin>>a>>b>>c;
	if((a+b)==c) cout<<"plus";
	else if((a-b)==c) cout<<"minus";
	else cout<<"illegal";
	return 0;
}