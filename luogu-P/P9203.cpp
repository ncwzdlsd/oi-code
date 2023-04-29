#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a,b;cin>>a>>b;
	int pos1=1,pos2=1;
	for(int i=1;i<a.length();i++) if(a[i]=='.') {pos1=i;break;}
	for(int i=1;i<b.length();i++) if(b[i]=='.') {pos2=i;break;}
	bool flag=1;
	int cnt1=0,cnt2=0;
	char aa[105],bb[105];
	for(int i=pos1;i<a.length();i++) aa[++cnt1]=a[i];
	for(int i=pos2;i<b.length();i++) bb[++cnt2]=b[i];
	for(int i=1;i<=max(strlen(aa),strlen(bb));i++) if(aa[i]!=bb[i]) {flag=0;break;}
	if(flag) cout<<"YES";
	else cout<<"NO";
	return 0;
}