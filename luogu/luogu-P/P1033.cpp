#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    double H,S1,V,L,K,n;cin>>H>>S1>>V>>L>>K>>n;
    double mxt=sqrt(H/5),mit=sqrt((H-K)/5);
    cout<<(min((int)(S1-mit*V+L),(int)n)-max((int)(S1-mxt*V),0));
    return 0;
}