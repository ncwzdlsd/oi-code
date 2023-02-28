#include <bits/stdc++.h>
using namespace std;

int n;

struct node
{
	string na;
	int m;
	int d;
}a[100005];

bool cmp(node x,node y)
{
	if(x.m!=y.m) return x.m<y.m;
	if(x.d!=y.d) return x.d<y.d;
	if(x.na.size()!=y.na.size()) return x.na.size()<y.na.size();
	return x.na<y.na;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].na>>a[i].m>>a[i].d;	
	sort(a+1,a+1+n,cmp);
	bool t=0,flag=0;
	for(int i=1;i<=n;i++)
	{
		if(t) cout<<a[i].na<<" ";
		if(a[i].m==a[i+1].m&&a[i].d==a[i+1].d)
		{
			if(!t) cout<<endl<<a[i].m<<" "<<a[i].d<<" "<<a[i].na<<" ";
			t=1;
			flag=1;
		}
		else t=0;
	}
	if(!flag) cout<<"None";
	return 0;
}