#include<bits/stdc++.h>
using namespace std;
double a1,b1,c1,a2,b2,c2;
int solve() 
{
	if(b1||b2) 
	{
		if((!a1&&!b1&&!c1)||(!a2&&!b2&&!c2)) return -1;
		if((!a1&&!b1)||(!a2&&!b2)) return 0;
		if(!b1||!b2) return 1;
	} 
	else 
	{
		if((!a1&&c1)||(!a2&&c2)) return 0;
		if(!(c2||c1)||!(a2||a1)||a1/c1==a2/c2) return -1;
		return 0;
	}
	if(a1/b1==a2/b2) 
	{
		if(c1/b1==c2/b2) return -1;
		return 0;
	}
	return 1;
}
int main() 
{
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	cout<<solve();
	return 0;
}
