#include <bits/stdc++.h>
using namespace std;

int a[20],tmp,f[20][170][170];

int dfs(int len,int ress,int sum,bool flag)
{
	if(!len) return sum==tmp&&!ress;
	if(!flag&&f[len][ress][sum]!=-1) return f[len][ress][sum];
	int up=(flag?a[len]:9);int res=0;
	for(int i=0;i<=up;++i) res+=dfs(len-1,((ress<<3)+(ress<<1)+i)%tmp,sum+i,flag&&i==up);
	if(!flag) f[len][ress][sum]=res;
	return res;
}
inline int qq(int x)
{
	if(!x) return 0;
	memset(f,-1,sizeof f);
	int len=0;
	while(x) a[++len]=(x%10),x/=10;
	return dfs(len,0,0,1);
}

int main()
{
	int l,r,ans=0;cin>>l>>r;
	for(int i=1;i<=162;++i) tmp=i,ans+=qq(r)-qq(l-1);
	cout<<ans;
	return 0;
}
