#include<bits/stdc++.h>
using namespace std;
int a[4000005];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int maxgcd=a[1];
    for(int i=2;i<=n;i++)
    {
        maxgcd=__gcd(maxgcd,a[i]);
        if(maxgcd==1) break;
    } 
    int rr=1;
    while(rr<=n&&a[rr]==maxgcd) rr++;
    int ans=0;
    int sta=1,t,l,r,u;
    for(int i=rr;i<=n;i++)
    {
        if(sta==1&&a[i]!=maxgcd)
        {
            t=a[i];
            sta=2;
            l=i;
        }
        else if(sta==2)
        {
            t=__gcd(a[i],t);
            if(t==maxgcd)
            {
                sta=3;
                u=k;
                r=i;
            }
        }
        else if(sta==3)
        {
            if(a[i]==maxgcd)
            {
                if(u==0)
                {
                    ans+=(r-l+1+k);
                    sta=1;
                }
                else
                    u--;
            }
            else
                u=k,r=i;
        }
    }

    if(sta>=2)
        ans+=(n-l+1+k+(sta==2));
    cout<<ans; 
    return 0;
}