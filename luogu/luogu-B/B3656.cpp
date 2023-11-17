#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
list<int> q[maxn];

int main()
{
	int qq;cin>>qq;
	while(qq--)
	{
		string s;cin>>s;
		int a,x;
		if(s=="push_back") cin>>a>>x,q[a].push_back(x);
		if(s=="pop_back") 
		{
			cin>>a;
			if(!q[a].empty()) q[a].pop_back();
		}
		if(s=="push_front") cin>>a>>x,q[a].push_front(x);
		if(s=="pop_front")
		{	
			cin>>a;
			if(!q[a].empty()) q[a].pop_front();
		}
		if(s=="size") cin>>a,cout<<q[a].size()<<endl;
		if(s=="front") 
		{
			cin>>a;
			if(!q[a].empty()) cout<<q[a].front()<<endl;
		}
		if(s=="back")
		{
			cin>>a;
			if(!q[a].empty()) cout<<q[a].back()<<endl;
		}
	}
	return 0;
}