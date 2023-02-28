#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long x;
	
	scanf("%lld", &x);
	
	if(x%3 == 0 && x%5 == 0){
		printf("%s", "YES"); 
	}
	else
	{
		printf("%s", "NO"); 
	}
	
	return 0;
}
