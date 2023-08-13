#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int a[maxn];

void write(__int128 x)
{
	if(x<0)x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	__int128 ans=0;
	if(n%2)
	{
		for(int i=2;i<=n;i+=2)
		{
			ans+=i;
		}
		write(ans);
	}
	else write(ans);
	return 0;
}