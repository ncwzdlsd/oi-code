#include<cstdio>
using namespace std;

char s[105],ss[105];
int q[105],cnt;

int main()
{
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
	    if(s[i]=='(') {q[++cnt]=i;ss[i]=')';continue;}
	    if(s[i]=='[') {q[++cnt]=i;ss[i]=']';continue;}
	    if(s[i]==')'||s[i]==']')
	    {
	        if(!cnt||ss[q[cnt]]!=s[i])
	        {
	            if(s[i] == ')') ss[i]='(';
	             else ss[i]='[';
	         }
	         else ss[q[cnt--]]=' ';
	     }
	 }
	 for(int i=0;i<l;i++)
	 {
	     if(ss[i]=='('||ss[i]=='[') cout<<ss[i];
	     cout<<s[i];
	     if(ss[i]==')'||ss[i]==']') cout<<ss[i];
	 }
	 return ;
}