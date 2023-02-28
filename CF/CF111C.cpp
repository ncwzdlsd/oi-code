#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,r;cin>>n>>m;
	if(n>m) swap(n,m);//n、m顺序无影响
	switch(n)
	{
		case 1:r=m/3+(m%3!=0);break;
		case 2:r=m/2+1;break;
		case 3:r=m-(m-1)/4;break;
		case 4:r=m+1-(m==4||m==7||m==8||m==10);break;
		case 5:r=7*(m==5)+8*(m==6)+9*(m==7)+11*(m==8);break;
		case 6:r=10;break;
	}
	cout<<n*m-r;
	return 0;
}