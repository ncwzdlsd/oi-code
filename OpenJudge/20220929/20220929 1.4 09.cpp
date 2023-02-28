#include <bits/stdc++.h>
using namespace std;

int main()
{
	bool isN = true;
	long long x;
	
	scanf("%lld", &x);
	
	if(x%3 == 0){
		printf("%d ", 3);		
		isN = false;
	}
	
	if(x%5 == 0){
		printf("%d ", 5);
		isN = false;
	}
	
	if(x%7 == 0){
		printf("%d ", 7);
		isN = false;
	}
	
	if(isN){
		printf("%c",'n');
	}
	
	return 0;
}
