#include<bits/stdc++.h>
using namespace std;
int f[205][205]={1},sum[205][205],n,m,k;
char a[1005],b[205];
int main()
{
    cin>>n>>m>>k>>a>>b;
    for(int i=1;i<=n;i++)
    	for(int j=m;j>=1;j--)
    		for(int kk=k;kk>=1;kk--)
            	f[j][kk]=(f[j][kk]+(sum[j][kk]=a[i-1]==b[j-1]?sum[j-1][kk]+f[j-1][kk-1]:0))%1000000007;
    cout<<f[m][k];
    return 0;
}