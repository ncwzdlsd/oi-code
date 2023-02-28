#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
    while(cin>>s)
    {
    	int z1,z2,z3;
    	z1=z2=z3=0;
    	for(int i=0;i<s.length();++i)
    	{
    		z3++;
    		if(s[i]=='0') z1++;
    		if(s[i]=='0'&&s[(i+1)%s.length()]=='0') z2++;
    	}
    	if(z2*z3==z1*z1) puts("EQUAL");
    	else if(z2*z3<z1*z1) puts("ROTATE");
    	else puts("SHOOT");
    }
    return 0;
}