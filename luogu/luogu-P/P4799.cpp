#include <bits/stdc++.h>
using namespace std;
#define int long long

// 对于此题的两次 DFS 来说，要统计 1 个 sum（当前消耗钱数）和 pos（已经搜到哪里了）

const int maxn=33554432;//左移 25 位相当于 2 的 25 次方
int q1[maxn],q2[maxn],co[45],ans,N,M,cnt1,cnt2,mid;

void dfs1(int sum,int pos)
{
    if(sum>M) return;
    if(pos>mid) {q1[++cnt1]=sum;return;}
    dfs1(sum+co[pos],pos+1);
    dfs1(sum,pos+1);//考虑不选当前位，继续向下搜
}

void dfs2(int sum,int pos)
{
    if(sum>M) return;
    if(pos>N) {q2[++cnt2]=sum;return;}
    dfs2(sum+co[pos],pos+1);
    dfs2(sum,pos+1);
}

signed main()
{
    cin>>N>>M;
    mid=(N+1)/2;
    for(int i=1;i<=N;i++) cin>>co[i];
    dfs1(0,1);
    sort(q1+1,q1+cnt1+1);
    dfs2(0,mid+1);
    for(int i=1;i<=cnt2;i++)
    	ans+=upper_bound(q1+1,q1+cnt1+1,M-q2[i])-q1-1;
    // cout<<cnt<<endl;
    // cout<<N/2<<endl;
    cout<<ans;
    return 0;
}