#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int maxn=5005;
ull hh[maxn],base[maxn];

unsigned long long hashh(int l,int r)
{
	return hh[r-1]-hh[l]*base[r-l+1];
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	
	return 0;
}