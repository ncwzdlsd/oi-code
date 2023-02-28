#include <bits/stdc++.h>
using namespace std;

void work(int l,int r)
{
	int mid=(l+r)/2;
	work(l,mid);work(mid+1,r);
}

int main()
{
	
	return 0;
}