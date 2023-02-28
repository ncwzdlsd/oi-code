#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<ll,vector<ll>,greater<ll> > q;

int main()
{
    int ans=0,n,l;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>l,q.push(l);
    for(int i=1;i<=n-1;i++)
    {
        int a=q.top();q.pop();
        int b=q.top();q.pop();
        int tmp=a+b;
        ans+=tmp;
        q.push(tmp);
    }
    cout<<ans;
    return 0;
}