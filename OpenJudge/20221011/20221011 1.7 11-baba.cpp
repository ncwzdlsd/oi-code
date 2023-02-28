#include <bits/stdc++.h>
using namespace std;

int main()
{
	char cipertext[200],originaltext[200],sampletext[200];
	
	cin>>cipertext>>originaltext>>sampletext;
	
	int len_c=strlen(cipertext),len_s=strlen(sampletext);
	
	char cipertable[26],originaltable[26];
	memset(cipertable,0,sizeof(cipertable));
	memset(originaltable,0,sizeof(originaltable));
	
	for(int i=0;i<len_c;i++)
	{
		char c=cipertext[i];//cipertext
		char o=originaltext[i];//originaltext
		
		int j_o=o-'A';
		if(j_o >= 0 && j_o <= 25)
		{
			char ct=cipertable[j_o];
			
			if(ct != 0)
			{
				if(ct != c )
				{
					cout<<"Failed"<<endl;
					return 0;
				}
			}
			else
			{
				cipertable[j_o]=c;
			}			
		}
		
		int j_c=c-'A';
		if(j_c >= 0 && j_c <= 25)
		{
			char ot=originaltable[j_c];
			if(ot !=0 ){
				if(ot != o)
				{
					cout<<"Failed"<<endl;
					return 0;
				}
			}
			else
			{
				originaltable[j_c]=o; 
			}
		}
	}
	
	for(int i=0;i<26;i++)
	{
		if(cipertable[i] == 0 || originaltable[i] == 0)
		{
			cout<<"Failed"<<endl;
			return 0;
		} 
	}
		
	for(int i=0;i<len_s;i++)
	{
		char j=sampletext[i]-'A';
		
		if(j >= 0 && j <= 25)
		{
			cout<<originaltable[j];
		}
	}	
	
	cout<<endl;

	return 0;
}
