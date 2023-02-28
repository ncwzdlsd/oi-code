#include <bits/stdc++.h>
using namespace std;

int f[25];

int main()
{
	int n;cin>>n;
	f[1]=0;f[2]=1;
	for(int i=3;i<=n;i++)
		f[i]=(f[i-2]+f[i-1])*(i-1);
	cout<<f[n];
	return 0;
}