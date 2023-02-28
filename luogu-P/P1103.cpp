#include <bits/stdc++.h>
using namespace std;
 
int n,k,f[105][105],ans;
 
struct book
{
	int h,w;
	bool flag=1;
}p[105];
 
bool cmp(book a,book b){return a.h<b.h;} 
 
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>p[i].h>>p[i].w;
	sort(p+1,p+1+n,cmp);
	memset(f,0x3f3f3f,siezof(f));
	for(int i=1;i<=n;i++) f[i][1]=0;
	for(int i=1;i<=n;i++)                                     
		for(int j=2;j<=n-k;j++)
			for(int last=1;last<i;last++)
				f[i][j]=min(f[i][j],f[last][j-1]+abs(p[last].w-p[i].w));
	ans=0x3f3f3f;	
	for(int i=1;i<=n;i++) ans=min(ans,f[i][n-k]);
	cout<<ans;
	return 0;
}