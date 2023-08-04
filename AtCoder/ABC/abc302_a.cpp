#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int A,B;cin>>A>>B;
	if(A%B) cout<<(A/B+1);
	else cout<<A/B;
	return 0;
}