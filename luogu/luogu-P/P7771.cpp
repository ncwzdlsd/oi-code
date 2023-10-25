#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5,maxm=2e5+5;
struct edge{int to,nxt;}e[maxm];
int head[maxn],ru[maxn],chu[maxn],cnt;
struct node{int uu,vv;}a[maxn];

bool cmp(node a,node b){return a.v>b.v;}

void add(int x,int y){e[++cnt]={y,head[x]},head[x]=cnt;}

int main()
{
	int n,m;cin>>n>>m
	return 0;
}