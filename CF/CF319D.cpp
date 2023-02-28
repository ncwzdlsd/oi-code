#include<bits/stdc++.h>
using namespace std;

char str[50005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    cin>>str;
    int len=strlen(str);
    for(int i=1;i<=len/2;i++)
        for(int j=0;j<len-i+1;j++)
        {
            bool flag=1;
            for(int k=0;k<i;k++)
                if(str[j+k]!=str[j+k+i]) {flag=0;break;}
            if(flag==1)
            {
                for(int k=j;k<len;k++)
                {
					if(k+i>=len)str[k]='\0';
					else str[k]=str[k+i];
				}
                j--;len-=i;
            }
        }
    cout<<str;
    return 0;
}