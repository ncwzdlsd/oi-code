#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const double eps = 1e-8;
struct run
{
	long long date;
	double l;
	int st,ed,stp,step;
};
vector<run> v[N];
unordered_map<long long,int> mp;
int cnt[N],sum[N],mon[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
long long id[N];
char timee[11],s[11],sex[N][2],heal[2],t[11];
bool flag[N];
int cacltime1()
{
	int x,y,z;
	x = (timee[1] - '0') * 10 + timee[2] - '0';
	y = (timee[4] - '0') * 10 + timee[5] - '0';
	z = (timee[7] - '0') * 10 + timee[8] - '0';
	return x * 3600 + y * 60 + z;
}
int cacltime2(){
	int i = 1,x = 0,y = 0,m;
	m = strlen(timee + 1);
	while(timee[i] >= '0' && timee[i] <= '9'){
		x = x * 10 + timee[i] - '0';
		++i;
	}
	++i;
	while(i <= m && timee[i] >= '0' && timee[i] <= '9'){
		y = y * 10 + timee[i] - '0';
		++i;
	}
	return x * 60 + y;
}
int cacltime3()
{
	int x,y;
	x = (timee[5] - '0') * 10 + timee[6] - '0';
	y = (timee[7] - '0') * 10 + timee[8] - '0';
	return mon[x - 1] + y;
} 
int exam(int id)
{
	int x = cacltime2();
	if(flag[id])
	{
		if(x <= 750) return 20;
		if(x <= 780) return 18;
		if(x <= 810) return 16;
		if(x <= 840) return 14;
		if(x <= 870) return 12;
		if(x <= 910) return 10;
		if(x <= 950) return 8;
		if(x <= 990) return 6;
		if(x <= 1030) return 4;
		if(x <= 1080) return 2;
		return 0;
	}
	else
	{
		if(x <= 400) return 20;
		if(x <= 417) return 18;
		if(x <= 434) return 16;
		if(x <= 451) return 14;
		if(x <= 470) return 12;
		if(x <= 485) return 10;
		if(x <= 500) return 8;
		if(x <= 515) return 6;
		if(x <= 530) return 4;
		if(x <= 540) return 2;
		return 0;
	}
}
int sunrun(int x){
	if(x >= 21) return 10;
	if(x >= 19) return 9;
	if(x >= 17) return 8;
	if(x >= 14) return 7;
	if(x >= 11) return 6;
	if(x >= 7) return 4;
	if(x >= 3) return 2;
	return 0;
}
int attend(int x)
{
	if(x >= 18) return 5;
	if(x >= 15) return 4;
	if(x >= 12) return 3;
	if(x >= 9) return 2;
	if(x >= 6) return 1;
	return 0;
}
int longrun(int id)
{
	#define u v[id][i]
	int i,ret,ccnt = 0;
	long long lst,lstdate,ti,delta;
	bool valid,ok = 0;
	for(i = 0;i < (int)v[id].size();i++){
		valid = 1;
		assert(u.ed > u.st);
		if(u.ed < u.st){
			ti = u.ed + 86400 - u.st;
			--u.date;
		}
		else ti = (u.ed - u.st);
		if(u.stp > 270) valid = 0;
		if((int)u.l < 2 * ti || (int)u.l > 5 * ti) valid = 0;
		if(flag[id] && u.l < 3000 || !flag[id] && u.l < 1500) valid = 0;
		if(u.l > 1.5 * u.step) valid = 0;
		if(ok)
		{
			delta = (u.date - lstdate) * 86400 + u.st - lst;
			if(delta < 21600) valid = 0;
		}
		if(valid)
		{
			ok = 1;
			lstdate = u.date,lst = u.ed;
			++ccnt;
		}
	}
	ret = sunrun(ccnt);
	cnt[id] += ccnt;
	ret += attend(cnt[id]);
	return ret;
}
string grade(int sc)
{
	if(sc >= 95) return "A";
	if(sc >= 90) return "A-";
	if(sc >= 85) return "B+";
	if(sc >= 80) return "B";
	if(sc >= 77) return "B-";
	if(sc >= 73) return "C+";
	if(sc >= 70) return "C";
	if(sc >= 67) return "C-";
	if(sc >= 63) return "D+";
	if(sc >= 60) return "D";
	return "F";
}
int main(){
	int i,n,tt,temp;
	long long lemp;
	scanf("%d",&tt);
	for(i = 1;i <= tt;i++)
	{
		scanf("%lld",&id[i]);
		mp[id[i]] = i;
		scanf("%s",sex[i] + 1);
		if(sex[i][1] == 'M') flag[i] = 1;
		scanf("%d",&sum[i]);
		scanf("%s",timee + 1);
		sum[i] += exam(i);
		scanf("%s",heal + 1);
		if(heal[1] == 'P') sum[i] += 10;
		scanf("%d",&temp);
		sum[i] += temp;
		scanf("%d",&cnt[i]);
	}
	scanf("%d",&n);
	run s;
	for(i = 1;i <= n;i++)
	{
		scanf("%s",timee + 1);
		s.date = cacltime3();
		scanf("%lld",&lemp);
		temp = mp[lemp];
		scanf("%s",timee + 1);
		s.st = cacltime1();
		scanf("%s",timee + 1);
		s.ed = cacltime1();
		scanf("%lf",&s.l);
		s.l *= 1000;
		scanf("%s",timee + 1);
		s.stp = cacltime2();
		scanf("%d",&s.step);
		v[temp].push_back(s);
	}
	for(i = 1;i <= tt;i++)
	{
		sum[i] += longrun(i);
		printf("%lld ",id[i]);
		printf("%d ",sum[i]);
		cout << grade(sum[i]) << endl;
	}
	return 0;
}