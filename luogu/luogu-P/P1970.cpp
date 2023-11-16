#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
int h[maxn];

int main()
{
    int n,lst;cin>>n>>lst;
    int ans=1,op=0;
    for(int i=2,h;i<=n;i++)
    {
        cin>>h;
        if(h>lst&&op!=1) op=1,ans++;
        else if(h<lst&&op!=2) op=2,ans++;
        lst=h;
    } 
    cout<<ans;
    return 0;
}