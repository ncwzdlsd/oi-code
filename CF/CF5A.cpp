#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int cnt=0,ans=0;
    while(getline(cin,s))
    {
        if(s[0]=='+') cnt++;
        else if(s[0]=='-') cnt--;
        else
        {
            int p=s.find(':');
            ans+=cnt*(s.length()-p-1);
        }
    }
    cout<<ans;
    return 0;
}