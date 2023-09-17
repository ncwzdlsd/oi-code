#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f

const int Maxn=2e6+5;
int n,a[Maxn],mx,L[Maxn],R[Maxn],C[Maxn];
ll ans;

signed main() 
{
    cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	rotate(a,max_element(a,a+n),a+n);
	a[n]=a[0];
	for(int i=n-1;i>=0;i--) 
    {
		R[i]=i+1;
		while(R[i]<n&&a[R[i]]<a[i])
			R[i]=R[R[i]];
		if(R[i]<n&&a[R[i]]==a[i])
			C[i]=C[R[i]]+1,R[i]=R[R[i]];
	}
	for(int i=0;i<n;i++) 
    {
		ans+=C[i];
		if(a[i]==a[0]) continue;
		L[i]=i-1;
		while(L[i]>0&&a[L[i]]<=a[i]) L[i]=L[L[i]];
		ans+=2;
		if(L[i]==0&&R[i]==n) ans--;
	}
	printf("%lld",ans);
}