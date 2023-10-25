#include <bits/stdc++.h>
using namespace std;
int n,i;
long long ans;
struct node
{
    int x,v;
}a[100005],tmp[100005];
bool cmp(node x,node y)
{
    return x.v<y.v;
}
void work(int l,int r)
{
    if(l>=r)
        return;
    int mid=(l+r)/2,ll=l,i;
    long long s1=0,s2=0;
    work(l,mid);
    work(mid+1,r);
    for(i=l;i<=mid;i++)
        s1+=a[i].x;
    for(i=mid+1;i<=r;i++)
    {
        while(ll<=mid&&a[ll].x<a[i].x)
            s2+=a[ll].x,s1-=a[ll].x,ll++;
        ans+=(1ll*a[i].x*(ll-l)-s2-1ll*a[i].x*(mid-ll+1)+s1)*a[i].v;
    }
    int l1=l,l2=mid+1,k=l-1;
    while(l1<=mid||l2<=r)
    {
        if((a[l1].x>a[l2].x||l1>mid)&&l2<=r)
            tmp[++k]=a[l2],l2++;
        else
            tmp[++k]=a[l1],l1++;
    }
    for(i=l;i<=r;i++)
        a[i]=tmp[i];
}
int main()
{
	cin>>n;
    for(i=1;i<=n;i++) cin>>a[i].v>>a[i].x;
    sort(a+1,a+1+n,cmp);
    work(1,n);
    cout<<ans;
    return 0;
}