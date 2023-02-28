#include<bits/stdc++.h>
using namespace std;

int a[5005],f[5005],qwq[5005];

int main()
{
    memset(f,0,sizeof(f));memset(qwq,0,sizeof(qwq));
    int n,maxx=-0x3f3f3f,sum=0;cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++) if(a[i]<a[j]) f[i]=max(f[i],f[j]+1);
        if(f[i]==0) f[i]++;
        if(f[i]>maxx) maxx=f[i];
        for(int j=1;j<i;j++) 
        	if(f[i]==f[j]&&a[i]==a[j]) qwq[j]=0;
            else if(f[i]==f[j]+1&&a[i]<a[j]) qwq[i]+=qwq[j];
        if(!qwq[i]) qwq[i]=1;
    }
    for(int i=1;i<=n;i++) if(f[i]==maxx) sum+=qwq[i];
    printf("%d %d",maxx,sum);
    return 0;
}