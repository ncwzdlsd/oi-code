#include <bits/stdc++.h>
using namespace std;

int maxr=2e5+5,maxn=5005;
struct edge{int to,nxt,e;}e[maxr];
int head[maxn];
struct node
{
	int id,d;
	bool friend operator < (node a,node b){return a.d>b.d;}
};
priority_queue<int> q;

void add(int x,int y,int z){e[++cnt]={hy,head[x],w},head[x]=cnt;}

void dij(int s)
{
	
}

int main()
{
	
	return 0;
}