#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q;

int main()
{
	int n;cin>>n;
	while(n--)
	{
		int op;cin>>op;
		if(op==1)
		{
			int x;cin>>x;
			q.push(x);
		}
		if(op==2) cout<<q.top()<<'\n';
		if(op==3) q.pop();
	}
	return 0;
}