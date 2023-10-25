#include <bits/stdc++.h>
using namespace std;

double f[10005],gg[10005];

int main() 
{
	int n;cin>>n;
	for(int i=n-1;i>=0;i--) 
		f[i]=f[i+1]+(1.0*n)/(1.0*(n-i)),gg[i]=(1.0*i)/(1.0*(n-i))*(f[i]+1)+gg[i+1]+f[i+1]+1;
	printf("%.2lf",gg[0]);
	return 0;
}