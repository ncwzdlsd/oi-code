#include <bits/stdc++.h>
using namespace std;

const int maxn=300005;
int father[maxn],x,y;

int find(int x)
{
	if(father[x]!=x) father[x]=find(father[x]);
	return father[x];
}

void unionn(int x,int y)
{
	int xx=find(father[x]);
	int yy=find(father[y]);
	father[xx]=yy;
}

int main()
{
	int N,K,gg,ans=0;cin>>N>>K;
	for(int i=1;i<=3*N;i++) father[i]=i;
	for(int i=1;i<=K;i++) 
	{
		cin>>gg>>x>>y;
		if(x>n||y>n) {ans++;continue;}
		if(gg==1)
		{
			if(find(x+N)==find(y)||find(x+2*N)==find(y)) {ans++;continue;}
			unionn(x,y);unionn(x+N,y+N);unionn(x+2*N,y+2*N);
		}
		else if(gg==2)
		{
			if(x==y) {ans++;continue;}
			if(find(x)==find(y)||find(x+2*N)==find(y)) {ans++;continue;}
			unionn(x,y+2*N);unionn(x+N,y);unionn(x+2*N,y+N);
		}
	}
	cout<<ans;
	return 0;
}