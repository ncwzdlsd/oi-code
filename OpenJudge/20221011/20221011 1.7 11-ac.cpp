#include <bits/stdc++.h>

const int N = 100010; //����û��Ҫ�󣬿��Լ����⿪������������Щ
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
		if (check[b[i]]) {//����������������һ������Ҫ���������
			if (check[b[i]] != a[i]) {
				cout << "Failed" << endl;
				return 0;
			}
		}
		if (m[a[i]]) {//����������û�з������90pts
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
	for (int i = 1; i <= 26; i++) {//�鿴26����ĸ�Ƿ񶼱���ֵ
		if (!m[(char)(i+'A'-1)]) {
			cout << "Failed" << endl;
			return 0;
		}
	}
	len = strlen (c);
	for (int i = 0; i < len; i++) {//���
		cout << m[c[i]];
	}
	cout << endl;
	return 0;
}
