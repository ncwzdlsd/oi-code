#include <bits/stdc++.h>
using namespace std;
bool dp[10005][105]; 
int a[10005];
int main()
{
	int m,n,k,v;
	cin >> m;
	while(m--)
	{
	    memset(dp,0,sizeof(dp));
    	cin >> n >> k;
    	dp[0][0] = true;
    	for(int i = 1;i <= n;++i)
    	{
    		cin >> a[i];
            a[i] = abs(a[i]); 
        }
    	for(int i = 1;i <= n;++i)
    		for(int j = 0;j < k;++j) 
    			dp[i][j] = dp[i-1][(k+j-a[i]%k)%k] || dp[i-1][(j+a[i])%k]; 
        cout << (dp[n][0] ? "Divisible" : "Not divisible") << endl;
    }
    return 0;
}