#include<bits/stdc++.h>
using namespace std;

int n,a[55],sum,maxx,num,ans;
bool flag;

void dfs(int step,int len,int last)
{
	if(len>ans) return; 
	if(step==num+1) {flag=true;return;} 
	if(len==ans)
	{
		dfs(step+1,0,maxx);
		if(flag) return;
	}
	else
		for(int i=last;i>=1;i--)
		{
			if(!a[i])continue;
			a[i]--;
			dfs(step,len+i,i);
			a[i]++;
			if(flag) return;
			if(len==0||len+i==ans) return;
		}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x>50)continue; 
		a[x]++,sum+=x;
		if(x>maxx) maxx=x;
	}
	for(int i=maxx;i<=sum/2;i++)
	{
		if(sum%i) continue;
		ans=i;num=sum/i;
		dfs(1,0,maxx);
		if(flag) cout<<ans,exit(0);
	}
	cout<<sum;
	return 0;
}