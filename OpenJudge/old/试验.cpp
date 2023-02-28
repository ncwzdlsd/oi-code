#include  <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,s,t;
	int *pa=&a,*pb=&b;
	a=10;
	b=20;
	s=*pa+*pb;
	t=*pa**pb;
	cout<<*pa<<*pb<<endl;
	cout<<s<<t<<endl;
	return 0; 
}
