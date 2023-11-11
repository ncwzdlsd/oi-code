#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,M;cin>>a>>b>>c>>d>>M;
    int s1=5*c,s2=0;
    if(s1<=M) s1-=(b-d)*20;
    else s1+=d*20,s1-=(b-d)*20;
    if(s1<0) cout<<0;
    else cout<<s1;
    return 0;
}