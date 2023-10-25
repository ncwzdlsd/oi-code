#include <bits/stdc++.h>
using namespace std;
char a[1000010];
int n,nxt[1000010];
int main()
{
    scanf("%d",&n);scanf("%s",a);
    int cnt=0;
    for(int j=0,i=1;i<n;i++)
    {
        while(j&&(a[i]!=a[j])) j=nxt[j];
        if(a[i]==a[j]) j++;
        nxt[i+1]=j;
    }
    for(i=1;i<=n;i++)
    {
        j=i;
        while(nxt[j]) j=nxt[j];
        if(nxt[i]!=0) nxt[i]=j;
        cnt+=i-j;
    }
	cout<<cnt;
    return 0;
}