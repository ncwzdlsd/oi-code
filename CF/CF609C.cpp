#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
int m[maxn];

int main()
{
	int n;cin>>n;
	ll tot=0;
	for(int i=1;i<=n;i++) cin>>m[i],tot+=m[i];
	sort(m+1,m+n+1);
	ll tmp=0;
	for(int i=1;i<=(n-tot%n);i++) tmp+=abs(m[i]-tot/n);
	for(int i=n-tot%n+1;i<=n;i++) tmp+=abs(m[i]-tot/n-1);
	cout<<tmp/2;
	return 0;
}