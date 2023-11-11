#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

signed main()
{
    int a,b,R,V,M;cin>>b>>a>>R>>V>>M;
    cout<<(R*a+2*R*b*2)<<' '<<(V*a+V*3*b*2)<<' '<<(M*a+M*3*b*2);
    return 0;
}