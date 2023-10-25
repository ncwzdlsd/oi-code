#include <bits/stdc++.h>
const int MAXN=1000005
using namespace std;
int dp[MAXN][25],N,M;
inline void build()
{
    for(int j=1;j<=20;++j)
        for(int i=1;i<=N;++i)
            if(i+(1<<j)-1<=N)
                dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int main()
{
	cin>>N>>M;
    for(i=1;i<=N;++i) cin>>dp[i][0];
    build();
    for(int j=1;j<=N-M+1;++j)
    {
        int k=log2(M);
        cout<<min(dp[j][k],dp[j+M-1-(1<<k)+1][k])<<endl;
    }
    return 0;
}