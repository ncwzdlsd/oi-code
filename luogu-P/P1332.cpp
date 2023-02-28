#include<bits/stdc++.h>
using namespace std;

int n,m,a,b,xa[250005],ya[250005],xb[250005],yb[250005],maxx[250005];

int main()
{
	cin>>n>>m>>a>>b;
    for(int i=1;i<=a;i++) cin>>xa[i]>>ya[i];
    for(int i=1;i<=b;i++) cin>>xb[i]>>yb[i];
    memset(maxx,127,sizeof(maxx));
    for(int i=1;i<=b;i++)
        for(int j=1;j<=a;j++)
            maxx[i]=min(maxx[i],abs(xa[j]-xb[i])+abs(ya[j]-yb[i]));
    for(int i=1;i<=b;i++) cout<<maxx[i]<<endl;
    return 0;
}