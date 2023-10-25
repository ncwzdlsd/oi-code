#include <bits/stdc++.h>
using namespace std;
#define int long long

int sum,N,ans;

struct node
{
    int T,D;
}cow[100008];

bool cmp(node a,node b)
{
    return a.D*1.0/a.T>b.D*1.0/b.T;
}

signed main()
{
	cin>>N;
    for(int i=1;i<=N;i++)
      cin>>cow[i].T>>cow[i].D,sum+=cow[i].D;
    sort(cow+1,cow+N+1,cmp);
    for(int i=1;i<=N;i++)
        sum-=cow[i].D,ans+=sum*cow[i].T*2;
    cout<<ans;
    return 0;
}