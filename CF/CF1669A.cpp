#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int x;cin>>x;
		if(x<1400) cout<<"Division 4"<<endl;
		else if(x<1600) cout<<"Division 3"<<endl;
		else if(x<1900) cout<<"Division 2"<<endl;
		else cout<<"Division 1"<<endl;
	}
	return 0;
} 