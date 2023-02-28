#include <bits/stdc++.h>

const int N = 100010; //题中没有要求，可自己随意开，但尽量开大些
using namespace std;

char a[N], b[N], c[N];
map <char, char> m;
map <char, char> check;

int main () {
	scanf ("%s%s%s", a, b, c);
	int len = strlen (a);
	if (len < 26) {
		cout << "Failed" << endl;
		return 0;
	}
	for (int i = 0; i < len; i++) {
		if (check[b[i]]) {//反向搜索，其中有一个点需要反过来查错
			if (check[b[i]] != a[i]) {
				cout << "Failed" << endl;
				return 0;
			}
		}
		if (m[a[i]]) {//正向搜索，没有反向可拿90pts
			if (m[a[i]] != b[i]) {
				cout << "Failed" << endl;
				return 0;
			}
		}
		else {
			m[a[i]] = b[i];
			check[b[i]] = a[i];
		}
	}
	for (int i = 1; i <= 26; i++) {//查看26个字母是否都被赋值
		if (!m[(char)(i+'A'-1)]) {
			cout << "Failed" << endl;
			return 0;
		}
	}
	len = strlen (c);
	for (int i = 0; i < len; i++) {//输出
		cout << m[c[i]];
	}
	cout << endl;
	return 0;
}
