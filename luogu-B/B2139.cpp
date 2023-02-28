#include <bits/stdc++.h>
using namespace std;

int prime(int n)
{
	if(n==1)
	return 0;
	int i;
	for(i=2;i*i<=n;i++)
		if(n%i==0) return 0;
	return 1;
}

int main()
{
	int m,n;cin>>m>>n;
	bool flag=0;
	for(int i=m;i<=n;i++)
	{
		string t = to_string(i);
        reverse(t.begin(),t.end());
        int j=stoi(t);
		if(prime(i)&&prime(j))
		{
			if(flag) cout<<',';
			cout<<i;
			flag=1;
		}
	}
	if(!flag) puts("NO");
	return 0;
}