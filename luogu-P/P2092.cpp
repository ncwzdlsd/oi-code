#include <bits/stdc++.h>
using namespace std;
long long n,ans;
queue<long long> q;
signed main()
{
	cin>>n;
    for(long long i=2;i*i<=n;i++)
    	while(n%i==0) q.push(i),n/=i;
    if(n!=1) q.push(n);
    if(q.size()==2) cout<<2;
    else if(q.size()==1) cout<<1;
    else
    {
		cout<<1<<endl;
        ans=q.front();
        q.pop();
        prlong longf("%long longd\n",ans*q.front());
    }
    return 0;
}