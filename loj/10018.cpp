#include <bits/stdc++.h>
using namespace std;

// 上下界剪枝（可行性剪枝），求x1+x2+x3+...+xk=n
// 我们定义序列为递增序列避免重复，所以可以确定下界是a[i-1]<a[i]
// 当我们求第i个数字时，还需要凑出k-i+1个数字，如果当前数字过大就会导致后面的数字拼不起来
// 可以发现当前数不能超过n/(k-i+1)，这就是我们搜索的上界，如果超过了上下界我们就直接return

int ans,a[20000005],n,k;

void dfs(int kk)
{
	if(n==0) return;//因为每次扣掉已经选的数的值如果n=0了证明选的数过大了
	if(kk==k) if(a[kk-1]<=n) {ans++;return;}//已经到第m份了且前一个满足条件
	for(int i=a[kk-1];i<=n/(k-kk+1);i++) a[kk]=i,n-=i,dfs(kk+1),n+=i;
}

int main()
{
	cin>>n>>k;
	a[0]=1;
	dfs(1);
	cout<<ans;
	return 0;
}