#include <bits/stdc++.h>
using namespace std;

bool visx[10][10],visy[10][10],vis[10][10];
int out[10][10];
char s[100];

int check(int x,int y)
{
	if(x<=3&&y<=3) return 1;
	if(x<=6&&y<=3) return 2;
	if(x<=9&&y<=3) return 3;
	if(x<=3&&y<=6) return 4;
	if(x<=6&&y<=6) return 5;
	if(x<=9&&y<=6) return 6;
	if(x<=3&&y<=9) return 7;
	if(x<=6&&y<=9) return 8;
	if(x<=9&&y<=9) return 9;
}

bool flag=0;

void dfs(int x,int y)
{
	if(x>9)
	{
		flag=1;
		for(int i=1;i<=9;i++)
			for(int j=1;j<=9;j++) cout<<out[i][j];
		puts("");
		return;
	}
	if(s[(x-1)*9+y]!='.')
	{
		if(y!=9) dfs(x,y+1);
		else dfs(x+1,1);
		return;
	}
	int wh=check(x,y);
	for(int i=1;i<=9;i++)
	{
		if(visx[x][i]||visy[y][i]||vis[wh][i]) continue;
		out[x][y]=i,visx[x][i]=visy[y][i]=vis[wh][i]=1;
		if(y!=9) dfs(x,y+1);
		else dfs(x+1,1);
		if(flag) return;
		visx[x][i]=visy[y][i]=vis[wh][i]=0;
	}
}

int main()
{
	while(114514)
	{
		scanf("%s",s+1);
		if(s[1]=='e') exit(0);
		for(int i=1;i<=10;i++) 
			for(int j=1;j<=10;j++) vis[i][j]=0,visx[i][j]=0,visy[i][j]=0;
		for(int i=1;i<=9;i++)
			for(int j=1;j<=9;j++)
			{
				int p/*pos*/=(i-1)*9+j;
				if(s[p]=='.') continue;
				int q=s[p]-48;
				visx[i][q]=visy[j][q]=vis[check(i,j)][q]=1;
				out[i][j]=q;
			}
		flag=0;dfs(1,1);
	}
	return 0;
}