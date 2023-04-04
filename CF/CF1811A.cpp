#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
string b;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,d;cin>>n>>d;
		cin>>b;
		// string res=b;
		// for(int i=0;i<n;i++) 
			// if(b[i]-'0'<d) 
			// {
	            // res.insert(i,1,d+'0');
				// break;
			// }
		// cout<<res<<endl;
		int i=0;
        while(i<n&&b[i]-'0'>=d) ++i;
        if(i==n) cout<< b + to_string(d)<<endl;
        else cout<<b.substr(0, i) + to_string(d) + b.substr(i)<<endl;
		// for(int i=1;i<=n+1;i++) a[i]=0;
		// for(int i=n;i;i--) 
		// {
			// char ch;cin>>ch;
			// a[i]=ch-'0';
		// }
		// int pos=n;
		// for(int i=n;i;i--)
			// if(a[i]<=d) {pos=i;break;}
		// if(d&&pos!=n)
		// {
			// for(int i=n;i>pos;i--) ans[i]=a[i];
			// ans[pos]=d;
			// for(int i=pos;i;i--) ans[i]=a[i];
			// for(int i=n;i;i--) cout<<ans[i];
			// cout<<endl;
		// }
		// else if(pos==n)
		// {
			// cout<<d;
			// for(int i=n;i;i--) cout<<a[i];
			// cout<<endl;
		// }
		// else
		// {
			// for(int i=n;i;i--) cout<<a[i];
			// cout<<0<<endl;
		// }
	}
	return 0;
}