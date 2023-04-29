#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

signed main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,m,tmp=1;cin>>n>>m;
		bool flag=1;
		for(int i=2;i<=n;i++)
        {
            tmp*=2;
            if(tmp>m)
            {
                cout<<"No"<<endl;flag=0;
                break;
            }
        }
        if(flag)
        {
        	tmp=1;
        	cout<<"Yes"<<endl<<1<<' ';
        	for(int i=2;i<=n;i++)
        		tmp*=2,cout<<tmp<<' ';
        	cout<<endl;
        }
	}
	return 0;
}