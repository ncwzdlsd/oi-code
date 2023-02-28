#include<bits/stdc++.h>
using namespace std;
map<string,string>fa;
string find(string x)
{
    if(x!=fa[x]) 
        fa[x]=find(fa[x]);
    return  fa[x];
}
string s,s1;
int main()
{
    char ch;
    cin>>ch;
    while(ch!='$')
    {
        cin>>s;
        if(ch=='#')
        {
            s1=s;
            if(fa[s]=="") fa[s]=s;
        }
        else if(ch=='+')
            fa[s]=s1;
        else 
            cout<<s<<' '<<find(s)<<endl;    
    }
    return 0;
}