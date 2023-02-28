#include <bits/stdc++.h>
using namespace std;

int n,a[4][30],ans[30],jin[30];
bool vis[30],use[30];

bool check(int t)
{
	int x=ans[a[1][t]],y=ans[a[2][t]],z=ans[a[3][t]];
	if((x+y+jin[t])%n!=z) return 0;
	jin[t-1]=(x+y+jin[t])/n;
	for(int i=t-1;i>0;i--)
		if(use[a[1][i]]&&use[a[2][i]]&&use[a[3][i]]&&!(ans[a[3][i]]==(ans[a[1][i]]+ans[a[2][i]])%n||ans[a[3][i]]==(ans[a[1][i]]+ans[a[2][i]]+1)%n)) return 0;
	return 1;
}

void print()
{
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	exit(0);
}

void search(int t,int num)
{
	if(t==0) print();
	if(num>3)
	{
		if(check(t)) search(t-1,1);
		return;
	}
	if(use[a[num][t]]){search(t,num+1);return;}
	for(int i=0;i<n;i++)
		if(!vis[i])
		{
			ans[a[num][t]]=i,vis[i]=1,use[a[num][t]]=1;;
			search(t,num+1);
			vis[i]=0,use[a[num][t]]=0;
		}
}

int main()
{
	cin>>n;	
	char ch;
	int cnt=0;
	while(1)
	{
		ch=getchar();
		if(ch>='A'&&ch<='Z') a[1][++cnt]=ch-'A'+1;
		if(cnt==n) break;
	}
	cnt=0;
	while(1)
	{
		ch=getchar();
		if(ch>='A'&&ch<='Z') a[2][++cnt]=ch-'A'+1;
		if(cnt==n) break;
	}
	cnt=0;
	while(1)
	{
		ch=getchar();
		if(ch>='A'&&ch<='Z') a[3][++cnt]=ch-'A'+1;
		if(cnt==n) break;
	}
	search(n,1);
	return 0;
}