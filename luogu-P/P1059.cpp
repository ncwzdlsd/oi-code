#include <bits/stdc++.h>
using namespace std;

set<int> gg;
int a[105];

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],gg.insert(a[i]);
    cout<<gg.size()<<endl;
    while(!gg.empty())
    {
        cout<<*gg.begin()<<" ";
        gg.erase(gg.begin());
    }
    return 0;
}