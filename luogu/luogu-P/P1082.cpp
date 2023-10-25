#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x,y;

void exgcd(ll a,ll b)
{
	if(!b) {x=1,y=0;return;}
	exgcd(b,a%b);
	ll tx=x;
	x=y,y=tx-(ll)a/b*y;
}

int main()
{
	ll a,b;cin>>a>>b;
	exgcd(a,b);
	cout<<(x+b)%b;
	return 0;
}