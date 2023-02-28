#include <bits/stdc++.h>
using namespace std;

int du[500001],fa[500001],n=0;
char s[15];

int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}

bool unionn(int x,int y)//判断能否合并
{
	int xx=find(x),yy=find(y);
	if(xx==yy) return false;//相同不能合并
	fa[xx]=yy;return true;//合并
}

unordered_map<string,int> m;
//map默认按key从小到大排序，这里无需这种操作
int getid(const char *s)
{
	if(m[s]) return m[s];
	return m[s]=++n;
}

bool check()
{
	int cnt=0,xx,yy;
	for(int i=1;i<=50005;i++) fa[i]=i;
	while(~scanf("%s",s))
	{
		xx=getid(s);
		scanf("%s",s);yy=getid(s);
		if(unionn(xx,yy)) ++cnt;//记录合并次数
		++du[xx],++du[yy];
	}
	if(cnt<n-1) return false;
	cnt=0;//改为记录度数为奇数的点的个数
	for(int i=1;i<=n;i++) if((du[i]&1)&&++cnt>2) return false;
	return true;
}

int main()
{
	puts(check()?"Possible":"Impossible");
	return 0;
}