#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

const int basex=131,basey=87;
unsigned long long a[1005][1005],b[1005][1005],c[1005][1005],ans,qx[1005],qy[1005];
int n,m;
// a原矩阵，b上下颠倒矩阵，c左右颠倒矩阵

// ---OK---
bool check(int x11,int y11,int x22,int y22)
{
	if(x11<1||y11<1||x22>n||y22>m) return 0;
	//对于部分的Hash值，用前缀和差分处理
	//原矩阵Hash值
	unsigned long long xx=a[x22][y22]-a[x22][y11-1]*qy[y22-y11+1]-a[x11-1][y22]*qx[x22-x11+1]+a[x11-1][y11-1]*qx[x22-x11+1]*qy[y22-y11+1];
	int xx1=n-x22+1,xx2=n-x11+1;//上下颠倒
	unsigned long long yy=b[xx2][y22]-b[xx2][y11-1]*qy[y22-y11+1]-b[xx1-1][y22]*qx[xx2-xx1+1]+b[xx1-1][y11-1]*qx[xx2-xx1+1]*qy[y22-y11+1];
	int yy1=m-y22+1,yy2=m-y11+1;//左右颠倒
	unsigned long long zz=c[x22][yy2]-c[x22][yy1-1]*qy[yy2-yy1+1]-c[x11-1][yy2]*qx[x22-x11+1]+c[x11-1][yy1-1]*qx[x22-x11+1]*qy[yy2-yy1+1];
	return (xx==yy)&&(xx==zz);
}
// ---------

signed main()
{
	cin>>n>>m;
	qx[0]=qy[0]=1;
	for(int i=1;i<=max(m,n);i++) qx[i]=qx[i-1]*basex,qy[i]=qy[i-1]*basey;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin>>a[i][j],b[n-i+1][j]=a[i][j],c[i][m-j+1]=a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=a[i][j-1]*basey+a[i][j],b[i][j]=b[i][j-1]*basey+b[i][j],c[i][j]=c[i][j-1]*basey+c[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=a[i-1][j]*basex+a[i][j],b[i][j]=b[i-1][j]*basex+b[i][j],c[i][j]=c[i-1][j]*basex+c[i][j];
// 	二分寻找对称正方形，如果边长是奇数以一个格子为中心，是偶数以一个点为中心
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int l=0,r=min(m,n),tmp=0;
			//格子
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(check(i-mid+1,j-mid+1,i+mid,j+mid)) l=mid+1,tmp=mid;
				else r=mid-1;
			}
			ans+=tmp;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			//点
			int l=0,r=min(m,n),tmp=0;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(check(i-mid,j-mid,i+mid,j+mid)) l=mid+1,tmp=mid;
				else r=mid-1;
			}
			ans+=tmp;
		}
	cout<<ans+n*m;//加上小正方形的贡献
	return 0;
}