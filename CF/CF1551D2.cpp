#include <bits/stdc++.h>
using namespace std;

const int maxn=105;
char ans[105][105];
int n,m,k;

void op1(int a,int b,int k)
{
    int cnt=0;
    for(int i=1;i<=a/2;i++)
        for(int j=1;j<=b/2;j++)
        {
            cnt++;
            char c=(((i+j)%2)?'a':'c');
            if(cnt>k/2) ans[i*2][j*2-1]=c,ans[i*2-1][j*2-1]=c,ans[i*2][j*2]=c+1,ans[i*2-1][j*2]=c+1;
            else ans[i*2][j*2-1]=c,ans[i*2-1][j*2-1]=c+1,ans[i*2][j*2]=c,ans[i*2-1][j*2]=c+1;
        }
}

void op2()
{
    op1(n-1,m,k-m/2);
    int tmp=0;
    for(int i=1;i<m;i+=2)
    {
        tmp++;
        if(tmp%2) ans[n][i]='e',ans[n][i+1]='e';
        else ans[n][i]='f',ans[n][i+1]='f';
    }
}

void op3()
{
    op1(n,m-1,k);
    int tmp=0;
    for(int i=1;i<n;i+=2)
    {
        tmp++;
        if(tmp%2) ans[i][m]='e',ans[i+1][m]='e';
        else ans[i][m]='f',ans[i+1][m]='f';
    }
}

void solve()
{
    bool flag=0;
    cin>>n>>m>>k;
    if(n%2==0){if(k%2==0&&n*(m/2)>=k) flag=1;}
    else {if(m%2==0&&(k-m/2)%2==0&&k>=m/2) flag=1;}
    if(!flag) return cout<<"NO\n",void();
    cout<<"YES\n";
    if(n%2==0&&m%2==0) op1(n,m,k);
    else if(n%2!=0&&m%2==0) op2();
    else if(n%2==0&&m%2!=0) op3();
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=m;j++) cout<<ans[i][j];
        cout<<'\n';
    }
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}