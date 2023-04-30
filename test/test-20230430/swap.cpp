#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
char A[maxn]; 

bool check(char s1[],s2[])
{
	for(int i=1;i<=strlen(s1);i++)
	{
		if(s1[i]==s2[i]) continue;
		else if(s1[i]<s2[i]) return 1;
		else return 0;
	}
} 

int main()
{
	freopen("swap.in","r",stdin);
	freopen("swap.out","w",stdout);
	int n,K;cin>>n>>K;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=n-K;i++) 
	{
		swap(A[i],A[i+K]);
		if(check)
	}
	for(int i=1;i<=n;i++) cout<<A[i];
	return 0;
}
