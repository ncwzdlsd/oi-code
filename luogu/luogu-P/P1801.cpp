#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	priority_queue<int> qwq;
	priority_queue<int, vector<int>, greater<int>> qaq;
	deque<int> q;
	cin >> m >> n;
	for (int i = 1;i <= m;i++)
	{
		int tmp;cin >> tmp;
		q.push_back(tmp);
	}
	for (int i = 1;i <= n;i++)
	{
		int tmp;
		cin >> tmp;
		while (m - q.size() < tmp)
			qwq.push(q.front()),q.pop_front();
		while (qwq.size() > i)
			qaq.push(qwq.top()),qwq.pop();
		cout << qwq.top() << endl;
		if (!qaq.empty()) qwq.push(qaq.top()),qaq.pop();
	}
	return 0;
}