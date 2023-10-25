#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2030;
int s[maxn*maxn],a[maxn][maxn],id=1;

void init()
{
    for(int i=1;i<=2023;i++)
        for(int j=1;j<=i;j++)
        {
            if(i==1) a[i][j]=1;
            else a[i][j]=id*id+a[i-1][j]+a[i-1][j-1]-a[i-2][j-1];
            s[id]=a[i][j],id++;
        }
}

signed main()
{
    int t;cin>>t;
    init();    
    while(t--)
    {
        int n;cin>>n;
        cout<<s[n]<<endl;
    }
    return 0;
}