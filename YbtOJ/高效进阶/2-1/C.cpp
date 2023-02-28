#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s1[100],s2[100];
	scanf("%s%s",s1,s2);
	if(strlen(s1)<strlen(s2))
	{
		char tmp[100];
		strcpy(tmp,s1);
		strcpy(s1,s2);
		strcpy(s2,tmp);
		//其实上面的逆天操作就是为了让s1是长的那个
	}
	strcat(s1,s1);//把s1复制两倍
	if(strstr(s1,s2)==NULL) puts("false");
	else puts("true");
	return 0;
} 
