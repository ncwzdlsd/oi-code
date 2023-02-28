#include<bits/stdc++.h>
using namespace std;

map<string,int> gg;

int main()
{
    int n;cin>>n;
    string tmp;int ans;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp;
        int mua=i-gg[tmp];
        if(gg[tmp]>=mua) ans++;
        gg[tmp]++;
    }
    cout<<ans;
    return 0;
}