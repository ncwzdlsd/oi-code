#include <bits/stdc++.h>
using namespace std;

const int maxn=2e6+5;
int t[maxn][65],cnt[maxn],tot;
char s[maxn];

int getn(char x)
{
    if(x<='Z'&&x>='A') return x-'A';
    else if(x<='z'&&x>='a') return x-'a'+26;
    else return x-'0'+52;
}

void insert(char s[])
{
    int p=0,len=strlen(s);//根节点为0
    for(int i=0;i<len;i++)
    {
        int u=getn(s[i]);//当前字母子节点
        if(!t[p][u]) t[p][u]=++tot;//如果当前子节点不存在就创造一个点来存储子节点
        p=t[p][u];//让p走到子节点的位置
    }
    cnt[p]++;//结尾是p的字符串个数增加
}

int ask(char s[])
{
    int p=0,len=strlen(s),cntt=0;
    for(int i=0;i<len;i++)
    {
        int u=getn(s[i]);
        p=t[p][u];
        if(!p) return cntt;
        cntt+=cnt[p];
    }
    return cntt;
}

int main()
{
	int N,M;cin>>N>>M;
    for(int i=0;i<tot;i++)
        for(int j=0;j<65;j++) t[i][j]=0;
    for(int i=0;i<tot;i++) cnt[i]=0;
    tot=0;
    for(int i=1;i<=N;i++)
        cin>>s,insert(s);
    for(int i=1;i<=M;i++)
        cin>>s,cout<<ask(s)<<endl;
    return 0;
}