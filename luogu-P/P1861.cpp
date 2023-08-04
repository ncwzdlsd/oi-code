#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int N,M,tmp,ini=0,fin=0;
	cin>>N>>M;
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin>>tmp,ini+=(i*i+j*j)*tmp;
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin>>tmp,fin+=(i*i+j*j)*tmp;
	cout<<(ini-fin)/2;
	return 0;
}