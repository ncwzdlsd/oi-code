#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],ans,father[1000005];
int find(int x)
{
	if(father[x]!=x) father[x]=find(father[x]);
	return father[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) father[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
		if(find(a[i])==i)
			father[i]=i,ans++;
		else father[i]=a[i];
	}
	printf("%d",ans);
    return 0; 
}