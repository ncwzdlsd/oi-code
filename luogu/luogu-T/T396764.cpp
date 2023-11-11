#include <bits/stdc++.h>
using namespace std;

bool check(int x)
{
	for(int i=2;i<=sqrt(x);i++) if(x%i==0) return 0;
	return 1;	
}

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c='A'+i-1;
		int cnt=0;
		for(int j=1;;j++)
		{
			if(!check((int)c+j)) cout<<' ';
			else cout<<c,c++,cnt++;
			if(c>'Z') c='A';
			if(cnt==i*i) break;
		}
		cout<<endl;
	}
	return 0;
}