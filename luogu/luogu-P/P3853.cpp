#include<bits/stdc++.h>
using namespace std;

int a[100005],L,N,K,ans;

bool check(int x)
{
    int ans=0;
    for(int i=2;i<=n;i++)
        ans=ans+(a[i]-a[i-1]-1)/x;
    if(ans>k)
        return 0;
    return 1;
}
int main()
{
	cin>>L>>N>>K;
    for(int i=1;i<=n;i++) cin>a[i];
    int l=0,r=L*2;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid))
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
	cout<<ans;
    return 0;
}