#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    int x=0,w=0;char ch=0;
    while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return w?-x:x;
}

int main()
{
	int n=read(),k=read();	
	return 0;
}