#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int a1,a2,a3,b1,b2,b3;
    cin>>a1>>a2>>a3>>b1>>b2>>b3;
    cout<<(n-min(a1,b1+b3)-min(a2,b2+b1)-min(a3,b3+b2))<<' '<<(min(a1,b2)+min(a2,b3)+min(a3,b1));
    return 0;
}