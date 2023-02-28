#include <bits/stdc++.h>
using namespace std;

int N,qwq;

int main()
{
    cin>>N;
    while(N) qwq=qwq*10+N%10,N/=10;
    cout<<qwq;
    return 0;
}