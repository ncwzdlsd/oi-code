#include <bits/stdc++.h>
using namespace std;
struct e{int lr,mod;} ans[105][105][15];
int n,m,k,a[105][105],f[105][105][15],w;
char ch;
void print (int x,int y,int q) 
{
    if (x == n) printf("%d\n",y);
    else 
    {
        print (x + 1,y + ans[x][y][q].lr,ans[x][y][q].mod);
        if (ans[x][y][q].lr == 1) putchar('L');
        else putchar('R');
    }
}
int main(){
    scanf ("%d %d %d", &n,&m,&k); k++;
    for (int i = 1;i <= n; i++)
    	for (int j = 1;j <= m;j++)  cin >> ch,a[i][j] = ch -'0';
    memset (f, -1, sizeof (f));
    for (int i = 1; i <= m; i++)  f[n][i][a[n][i]%k] = a[n][i];
    for (int i = n - 1; i; i--)
    	for (int j = 1; j <= m; j++)
    		for (int p = 0; p < k; p++) 
    		{
          		int t = (p + a[i][j]) % k;
	          	if (j != 1 && f[i+1][j-1][p] >= 0)
	            	f[i][j][t] = f[i+1][j-1][p] + a[i][j],ans[i][j][t] = (e){-1,p};
	          	if (j != m && f[i+1][j+1][p] >= 0 && f[i+1][j+1][p] + a[i][j] > f[i][j][t])
	            	f[i][j][t] = f[i+1][j+1][p] + a[i][j],ans[i][j][t] = (e){1, p};
        	}
    for (int i = 1;i <= m;i++) if(f[1][i][0] > f[1][w][0]) w = i;
    if (!w) {puts("-1");return 0;}
    printf("%d\n",f[1][w][0]);
    print(1,w,0);
    return 0;
}