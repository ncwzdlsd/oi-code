#include <bits/stdc++.h>
using namespace std;

int qwq(int x,int y)
{
	int s1,s2,s3,s4;
	if(x<y) swap(x,y);
	if(x==2&&y==1) return 2;
	else if(x==2&&y==2) return 3;
	s1=x-y;
	s2=s1%4;
	s3=s1/4;
	s4=s3+s2+(x+y-s2*3)/4;
	return s4;
}

int main()
{
	int a,b,c,d;
	cin>>a>>b;cout<<qwq(a,b)<<endl;
	cin>>c>>d;cout<<qwq(c,d);
	return 0;
} 