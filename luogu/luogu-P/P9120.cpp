#include <bits/stdc++.h>
using namespace std;

const int maxn=5e4+5;
int a[maxn][5],mx[5],mi[5],T,k;

void solve()
{
	int n;cin>>n;
	for(int j=1;j<=k;j++) for(int i=1;i<=n;i++) cin>>a[i][j];
	int tt=300,ans=0x3f3f3f;
	while(tt--)
	{
		// mt19937 rd(time(0));
		// shuffle(a+1,a+n+1,rd);
		random_shuffle(a+1,a+n+1);
		memset(mx,-0x3f3f3f,sizeof mx),memset(mi,0x3f3f3f,sizeof mi);
		for(int i=1;i<=n;i++)
		{
			int minstp=0,minv=0x3f3f3f;
			for(int stp=0;stp<k;stp++)
			{
				int vv=0;
				for(int j=1;j<=k;j++)
				{
					int pos=(j+stp-1)%k+1;
					vv=max(vv,max(mx[j],a[i][pos])-min(mi[j],a[i][pos]));
				}
				if(vv<minv) minstp=stp,minv=vv;
			}
			for(int j=1;j<=k;j++) 
			{
				int nowpos=(j+minstp-1)%k+1;
				mx[j]=max(mx[j],a[i][nowpos]),mi[j]=min(mi[j],a[i][nowpos]);
			}
			if(minv>=ans) break;//到当前局面松散度已经超过原答案
			// cout<<minstp<<' '<<minv<<endl;
		}
		int tmp=0;
		for(int i=1;i<=k;i++) tmp=max(tmp,mx[i]-mi[i]);
		ans=min(tmp,ans);
	}
	cout<<ans<<'\n';
}

int main()
{
	cin>>T>>k;
	while(T--) solve();
	return 0;
}