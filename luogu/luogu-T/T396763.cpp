#include <bits/stdc++.h>
using namespace std;

int a[10];

int main()
{
    int c1=0,c2=0,c3=0;
    for(int i=1,v;i<=8;i++)
    {
        cin>>v;
        if(v>=118) c3++;
        if(v>=63) c2++;
        if(v>=41) c1++;
    }
    if(c3>=1) cout<<10,exit(0);
    if(c2>=4) cout<<8,exit(0);
    if(c1>=4) cout<<3,exit(0);
    cout<<1;
    return 0;
}