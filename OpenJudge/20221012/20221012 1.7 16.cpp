#include <bits/stdc++.h>

using namespace std;

void upper(char* str)
{
	while(*str != 0)
	{
		if(*str >= 'a' && *str <= 'z')
		{
			*str = *str - ((int)'a' - (int)'A');
		}
		str++;
	}		
}

int main()
{
	
	char a[200],b[200];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	
	cin.getline(a, 200);
	cin.getline(b, 200);
	
	upper(a);
	upper(b);
	
	int result=strcmp(a,b);
	if(result == 0)
	{
		cout<<"="<<endl;
	}
	else if(result > 0)
	{
		cout<<">"<<endl;
	}
	else
	{
		cout<<"<"<<endl;
	}
		
	return 0;
}
