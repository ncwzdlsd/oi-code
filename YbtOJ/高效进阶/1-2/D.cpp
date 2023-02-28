#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,k,w[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;

signed main()
{
	cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>w[i],q.push(make_pair(w[i],1));
    while((q.size()-1)%(k-1)) q.push(make_pair(0,1)); 
    int ans=0;
    while(q.size()>=k)
    {
        int h=-1,w=0;
        for(int i=1;i<=k;i++)
        { 
            pair<int,int> qwq=q.top();
            q.pop();
            h=max(h,qwq.second),w+=qwq.first;
        }
        ans+=w;
        q.push(make_pair(w,h+1));
    }
    cout<<ans<<endl<<(q.top().second-1);
    return 0;
}
