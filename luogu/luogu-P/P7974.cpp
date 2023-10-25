#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e6+5,logm=25;
int H[maxn],f[maxn][logm],f1[maxn][logm],f2[maxn][logm],logg[maxn],S,T;

signed main()
{
	int N;cin>>N;
	for(int i=1;i<=N;i++) cin>>H[i],f[i][0]=H[i],f1[i][0]=H[i]-i,f2[i][0]=H[i]+i;
	logg[0]=-1;
	for(int i=1;i<=N;i++) logg[i]=logg[i/2]+1;
	for(int j=1;j<=20;++j)
		for(int i=1;i+(1<<j)-1<=N;++i)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]),f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]),f2[i][j]=max(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
	int Q;cin>>Q;
	while(Q--)
	{
		int mh,ms,mt,ans,cnt;
		cin>>S>>T;
		int l=S,r=T;
		if(l>r) swap(l,r);
		int len=logg[r-l+1];
		mh=max(f[l][len],f[r-(1<<len)+1][len]);
		ms=max(f1[l][len],f1[r-(1<<len)+1][len]);
		mt=max(f2[l][len],f2[r-(1<<len)+1][len]);
		ms-=H[l]-l;
		mt-=H[r]+r;
		if(S>T) swap(ms,mt);
		cnt=abs(T-S)-((mh-ms-H[S])+(mh-mt-H[T]));
		ans=4*(mh-H[S])+(mh-H[T])+2*cnt;
		cout<<ans<<endl;
	}
	return 0;
}