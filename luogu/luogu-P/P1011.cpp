#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f1[25],f2[25];

int main()
{
    int a,n,m,x;cin>>a>>n>>m>>x;
    f1[2]=1,f1[3]=2;
    for(int i=4;i<n;i++) f1[i]=f1[i-1]+f1[i-2]-1,f2[i]=f2[i-1]+f2[i-2]+1;
	cout<<(a*f1[x]+((m-a*f1[n-1])/f2[n-1])*f2[x]);
    return 0;
}