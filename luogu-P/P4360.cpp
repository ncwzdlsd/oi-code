#include<bits/stdc++.h>
using namespace std;

const int maxm=3e4+5;
int n,q[maxm],qwq,qaq,ans=2e9+5,sum,s[maxm],d[maxm],w[maxm];

double calc(int j,int k)
{
	return 1.0*(d[j]*s[j]-d[k]*s[k])/(s[j]-s[k]);
}

int count(int i,int j){return sum-d[j]*s[j]-d[i]*(s[i]-s[j]);}

int main()
{
	cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i]>>d[i];
    for(int i=n;i>=1;i--) d[i]+=d[i+1];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+w[i],sum+=d[i]*w[i];
    for(int i=1;i<=n;i++)
    {
        while(qwq<qaq&&calc(q[qwq],q[qwq+1])>d[i]) ++qwq;
        ans=min(ans,count(i,q[qwq]));
        while(qwq<qaq&&calc(q[qaq-1],q[qaq])<calc(q[qaq],i)) --qaq;
        q[++qaq]=i;
    }
	cout<<ans;
    return 0;
}