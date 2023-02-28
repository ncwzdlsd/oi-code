#include<iostream>
using namespace std;
int du[10],m,i,a,b;
int main()
{
	cin>>m;
	for(i=1;i<=m;++i)
		cin>>a>>b,++du[a],++du[b];
	for(i=1;i<=5;++i)
		if(du[i]!=2)
			puts("WIN"),exit(0);
	puts("FAIL");
	return 0;
}