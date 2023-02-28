#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int a[2*maxn],s[2*maxn];
deque<int> q;

int main()
{
    int n,tot=1,ans;cin>>n;
    memset(s,0,sizeof(s));
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++) a[i+n]=a[i];
    for(int i=1;i<2*n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<2*n;i++)
    {
        while(!q.empty()&&s[q.back()]>=s[i]) q.pop_back();
        q.push_back(i);
        if(i>=n)
        {
            while(!q.empty()&&q.front()<=i-n) q.pop_front();
            if(s[q.front()]>=s[i-n]) ans++;
        }
    }
    cout<<ans;
    return 0;
}