#include <bits/stdc++.h>
using namespace std;
#define int long long


int f[20];//i表示栈内，j表示栈外 

signed main()
{
	int n;cin>>n;
	// f[0][0]=1;
	// for(int j=0;j<=n;j++)
		// for(int i=0;i<=n;i++)
		// {
			// if(i)
				// f[i][j]+=f[i-1][j];//队列元素-1，
			// if(j)
				// f[i][j]+=f[i+1][j-1];//队列中元素-1，栈内元素+1
		// }
	// cout<<f[0][n];
	f[1]=1;f[2]=2;
	for(int i=3;i<=n;i++) 
		f[i]=(f[i-1]*(4*i-2))/(i+1);
	cout<<f[n];
	return 0;
}