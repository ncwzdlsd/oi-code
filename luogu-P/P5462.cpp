#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int n,a[maxn],l[maxn]/*前一个数*/,r[maxn]/*后一个数*/;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],r[a[i-1]]=a[i],l[a[i]]=a[i-1];
	for(int i=n;i;i--) if(r[i]) cout<<i<<' '<<r[i]<<' ',r[l[i]]=r[r[i]],l[r[l[i]]]=l[i],r[r[i]]=0;
	return 0;
}