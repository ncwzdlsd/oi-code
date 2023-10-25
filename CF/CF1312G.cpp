#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int p;char c;cin>>p>>c;
        tr[p][c-'0']=i;
    }
    int k;cin>>k;
    return 0;
}