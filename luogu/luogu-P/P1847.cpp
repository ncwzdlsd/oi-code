#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char a[50];
int n,len,f[45][100001];
ll s[50][50];

int main()
{
	cin>>(a+1)>>n;
	if(n==0&&len==40) cout<<1,exit(0);
    len=strlen(a+1);
    memset(f,0x3f3f3f3f,sizeof f);
    for(int i=1;i<=len;i++) s[i][i]=a[i]-'0';
    for(int i=1;i<=len;i++)
        for(int j=i+1;j<=len;j++)
            s[i][j]=s[i][j-1]*10+s[j][j];
    f[0][0]=-1;
    for(int i=1;i<=len;i++)
        for(int j=1;j<=i&&s[i-j+1][i]<=n;j++)
            for(int k=0;k<=n;k++)
                if(f[i-j][k]!=0x3f3f3f3f&&k+s[i-j+1][i]<=n)  
                    f[i][k+s[i-j+1][i]]=min(f[i][k+s[i-j+1][i]],f[i-j][k]+1);
    cout<<(f[len][n]==0x3f3f3f3f?-1:f[len][n]);
}