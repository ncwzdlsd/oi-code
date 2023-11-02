#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vp,vd,f,c;double t;cin>>vp>>vd>>t>>f>>c;
    if(vp>=vd) cout<<0,exit(0);
    double s1=vp*t,s2=0;
    int ans=0;
    while(s1<c)
    {
        t+=(double)(s1-s2)/(vd-vp);
        s1=s2=vp*t;
        if(s1>=c) break;
        t+=s2/vd+f,s1=vp*t,s2=0,ans++;
    }
    cout<<ans;
    return 0;
}