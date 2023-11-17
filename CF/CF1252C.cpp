#include <bits/stdc++.h>
using namespace std;
#define y1 y11
#define y2 y22

const int maxn=1e6+5;
int s1[maxn],s2[maxn];

int main()
{
    int N,Q;cin>>N>>Q;
    for(int i=1,R;i<=N;i++) 
    {
        cin>>R;
        if(R%2) s1[i]=s1[i-1]+1;
        else s1[i]=s1[i-1];
    }
    for(int i=1,C;i<=N;i++)
    {
        cin>>C;
        if(C%2) s2[i]=s2[i-1]+1;
        else s2[i]=s2[i-1];
    }
    while(Q--)
    {
        int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        if(!s1[i])
    }
    return 0;
}