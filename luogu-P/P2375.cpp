#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
int n,qwq[1000010],num[1000010],ans;
char a[1000010];
int main()
{
    int nn,i,j;scanf("%d",&nn);
    while(nn--)
    {
        scanf("%s",a);n=strlen(a);
        memset(qwq,0,sizeof(qwq));
        j=0;num[0]=0;num[1]=1;
        for(i=1;i<n;i++)
        {
            while(j&&(a[i]!=a[j])) j=qwq[j];
            j+=(a[i]==a[j]);qwq[i+1]=j;num[i+1]=num[j]+1;
        }
        
        j=0;ans=1;
        for(i=1;i<n;i++)
        {
            while(j&&(a[i]!=a[j])) j=qwq[j];
            j+=(a[i]==a[j]);
            while((j<<1)>(i+1)) j=qwq[j];
            ans=(ans*(ll)(num[j]+1))%mod;
        }
		cout<<ans<<endl;
    }
    return 0;
}