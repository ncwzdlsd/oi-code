#include<bits/stdc++.h>
using namespace std;

int main()
{
	char a[14],mod[12]="0123456789X";
	gets(a);
	int cnt=1,t=0;
	for(int i=0;i<12;i++) 
	{
	    if(a[i]=='-') continue;
		t+=(a[i]-'0')*cnt++;
	}
	if(mod[t%11]==a[12]) puts("Right");
	else a[12]=mod[t%11],puts(a);
	return 0;
}