#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long x=0,y=0;
	
	scanf("%lld %lld",&x,&y);
		
	if(x>y){
		printf("%s",">");		
	}
	else if(x<y){
		printf("%s","<");		
	}
	else
	{
		printf("%s","=");		
	}
	
	return 0;
}
