#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int p[N];

int main()
{
    int n,k;
    cin>>n>>k;
    if(k==0)
        puts("-1")，exit(0);
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=k-1;i++) p[i]=p[i+1];
    p[k]=1;
    for(int i=1;i<=n;i++) cout<<p[i]<<' ';
    return 0;
}