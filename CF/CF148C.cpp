#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,a,b;cin>>n>>a>>b;
    if(n==1) cout<<1,exit(0);
    if(a==n-1) cout<<-1,exit(0);
    int s=n-a-b;
    if(!b)
    {
        for(int i=1;i<=s;i++) cout<<"1 ";
        for(int i=1;i<=a;i++) cout<<(s++)<<' ';
    }
    else
    {
        int t=1;cout<<t<<' ';
        for(int i=1;i<=b;i++) t+=t,cout<<t<<' ';
        for(int i=1;i<=a;i++) t++,cout<<t<<' ';
        for(int i=1;i<s;i++) cout<<1<<' ';
    }
    return 0;
}