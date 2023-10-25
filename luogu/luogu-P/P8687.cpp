#include <bits/stdc++.h>
using namespace std;
int dp[1 << 20];
int a[105];
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    int x;
    for(int i = 0;i < n;i++)
    {
        int t = 0;
        for (int j = 0;j < k;j++)
        {
            cin >> x;
            t|=(1 << (x - 1));
        }
        dp[t] = 1;
        a[i] = t;
    }
    int q = (1 << m) - 1;
    for (int i = 1;i <= q;i++)
    {
        if(dp[i])
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i|a[j]]==0||(dp[i|a[j]]>(dp[i]+1)))
                    dp[i|a[j]]=dp[i]+1;
            }
        }
    }
    if(dp[q])
   		cout<<dp[q];
    else
        cout << "-1";
    return 0;
}