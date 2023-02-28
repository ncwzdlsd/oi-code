#include <bits/stdc++.h>
using namespace std;

void work(int a,int b,int &p,int &q,int c,int d)//注意这里的p、q前要加取地址符，因为p、q没有传入但是需要传出
{
	if(a<b&&c>d) p=1,q=1;
	else
		work(d%c,c,q,p,b-(d/c)*a,a),q+=(d/c)*p;
}

int main()
{
	int a,b,c,d,p,q;
	while(cin>>a>>b>>c>>d)
	{
		work(a,b,p,q,c,d);
		cout<<p<<'/'<<q<<endl;
	}
	return 0;
}