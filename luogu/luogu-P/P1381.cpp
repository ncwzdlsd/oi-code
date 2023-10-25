#include<bits/stdc++.h>
using namespace std;

map<string,int>sum;
map<string,bool>flag;
int ans1,ans2=-0x3f3f3f,n,m,l=1;//l记录最左边的单词
string s[100005],ss; 

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>ss,flag[ss]=true;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s[i];
		if(flag[s[i]]) sum[s[i]]++;//该单词出现次数
		if(sum[s[i]]==1) ans1++;
	}
	for(int i=1;i<=m;i++)
	{
		ans2=i-l+1;
		while(l<=i)
		{
			if(!flag[s[l]]){l++;continue;}//当前单词不要背
			if(sum[s[l]]>=2){sum[s[l]]--,l++;continue;}
		}		
		ans2=min(ans2,i-l+1);
	}
	cout<<ans1<<endl<<ans2;
	return 0;
}