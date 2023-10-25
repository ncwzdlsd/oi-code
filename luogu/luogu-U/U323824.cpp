#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
	int ans=a+b+c+d+e;
	if(ans<100) cout<<"Gray";
	else if(ans<120) cout<<"Blue";
	else if(ans<170) cout<<"Green";
	else if(ans<230) cout<<"Orange";
	else cout<<"Red";
	return 0;
}