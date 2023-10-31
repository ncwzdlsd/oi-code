#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll A,B;cin>>A>>B;
	for(int i=0;i<60;i++)
	{
		ll tmp=1ll<<i;
		if((A|tmp)<=B) A|=tmp;
	}
	ll ans=0;
	while(A) 
	{
		if(A&1) ans++;
		A>>=1;
	}
	cout<<ans;
	return 0;
}