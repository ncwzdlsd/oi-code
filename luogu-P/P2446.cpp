#include <bits/stdc++.h>
using namespace std;

const int maxn=3*1e3+5;
int head[maxn],to[maxn],nxt[maxn],v[maxn],cnt;

void add(int x,int y,int z)
{
	to[++cnt]=y;
	v[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

int main()
{
	return 0;
}