
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,mx[N][20],mn[N][20],a[N],ansl[N],ansr[N],anstot,tot;
int getmx(int l,int r)
{
    int tmp=log2(r-l+1);
    return max(mx[l][tmp],mx[r-(1<<tmp)+1][tmp]);
}
int getmn(int l,int r)
{
    int tmp=log2(r-l+1);
    return min(mn[l][tmp],mn[r-(1<<tmp)+1][tmp]);
}
bool check(int mid)
{
    tot=0;
    for(int i=1;i+mid-1<=n;i++)
        if(getmx(i,i+mid-1)-getmn(i,i+mid-1)<=k) ansl[++tot]=i,ansr[tot]=i+mid-1;
    if(tot) anstot=tot;
    return tot;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],mx[i][0]=mn[i][0]=a[i];
    for(int j=1;j<20;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
        }
    int l=1,r=n;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    check(l);
    cout<<l<<" "<<anstot<<'\n';
    for(int i=1;i<=anstot;i++) cout<<ansl[i]<<" "<<ansr[i]<<'\n';
}