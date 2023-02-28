#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int n,nxt[1000005],num[1000005],ans;
char a[1000005];

int main()
{
    int nn;cin>>nn;
    while(nn--)
    {
        scanf("%s",a+1);n=strlen(a+1);
        num[0]=0;num[1]=1;
        for(int i=1,j=0;i<=n;i++)
        {
            while(j&&(a[i+1]!=a[j+1])) j=nxt[j];
            if(a[i+1]==a[j+1]) j++;
            nxt[i+1]=j;num[i+1]=num[j]+1;
        }
        ans=1;
        for(int i=1,j=0;i<=n;i++)
        {
            while(j&&(a[i+1]!=a[j+1])) j=nxt[j];
            if(a[i+1]==a[j+1]) j++;
            while((j<<1)>i+1) j=nxt[j];
            ans=(ans*(num[j]+1))%mod;
        }
		cout<<ans<<endl;
    }
    return 0;
}