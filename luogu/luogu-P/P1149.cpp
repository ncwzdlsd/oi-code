#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t[10]={6,2,5,5,4,5,6,3,7,6};

int calc(int x)
{
    if(x==0) return t[0];
    int res=0;
    while(x) res+=t[x%10],x/=10;
    return res;
}

int main()
{
    int n;cin>>n;
    int ans=0;
    for(int i=0;i<=5000;i++)
        for(int j=0;j<=5000;j++)
            if(calc(i)+calc(j)+calc(i+j)+4==n) ans++;
    cout<<ans;
    return 0;
}