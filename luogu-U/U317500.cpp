#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int p1,p2,a[maxn];

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]) {p1=i;break;}
	for(int i=n;i;i--)
		if(a[i]) {p2=i;break;}
	if(!p2) cout<<0;
	else if(p2==p1) cout<<1;
	else cout<<(p2-p1+1);
	return 0;
}