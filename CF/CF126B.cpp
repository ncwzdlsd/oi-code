#include<bits/stdc++.h>
using namespace std;

char a[1000005];
int nxt[1000005],n,maxx=0;

int main()
{
    cin>>a+1;
    n=strlen(a+1);
	nxt[1]=0;
    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&a[i]!=a[j+1])j=nxt[j];
        if(a[i]==a[j+1])j++;
        nxt[i]=j;
        if(i!=n)maxx=max(nxt[i],maxx);
    }    int x=nxt[n];
    if(x==0) cout<<"Just a legend"<<endl;
    else
    {
        while(x>maxx)x=nxt[x];
        if(x==0)
        	cout<<"Just a legend"<<endl,exit(0);
        for(int i=2;i<n;i++)
         if(x==nxt[i])
         {
            for(int j=i-nxt[i]+1;j<=i;j++) cout<<a[j];
			cout<<endl;
            return 0;
         }
    }
    return 0;
} 