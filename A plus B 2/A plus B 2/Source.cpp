#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string s, t;
int n, o;
bool neg, sneg, tneg, hneg, lneg;
int mmax(const string&s, const string&t) {
	bool eq_size = false;
	if (s.size() == t.size())
		eq_size = true;
	int size = min(s.size(), t.size());
	for (int i = 0; i < size; ++i) {
		if (s[i] == t[i])
			continue;
		else if (s[i] > t[i])
			return 0;
		else if (s[i] < t[i])
			return 1;
	}
	if (eq_size)
		return 2;
}
int main() {
	cin >> s >> t;
	if (s.front()=='-'&&t.front()=='-') {
		s.erase(s.begin());
		t.erase(t.begin());
		neg = true;
	}
	else if (s.front() == '-') {
		s.erase(s.begin());
		sneg = true;
	}
	else if (t.front() == '-') {
		t.erase(t.begin());
		tneg = true;
	}
	vector<int>vh, vl, v;
	switch (mmax(s, t)) {
	case 0:
		hneg = sneg;
		lneg = tneg;
		for (const char&c : s)
			vh.push_back(c - '0');
		for (const char&c : t)
			vl.push_back(c - '0');
		break;
	case 1:
		hneg = tneg;
		lneg = sneg;
		for (const char&c : s)
			vh.push_back(c - '0');
		for (const char&c : t)
			vl.push_back(c - '0');
		break;
	case 2:
		if ((sneg || tneg) && !(sneg&&tneg)) {
			cout << 0 << endl;
			return 0;
		}
	default:
		break;
	}
	v.resize(max(vh.size(), vl.size()));
	if (sneg || tneg) {
		int i = vh.size() - 1;
		for (int j = vl.size() - 1; i >= 0 && j >= 0; --i, --j) {
			if (vh[i] < vl[j]) {
				vh[i - 1]--;
				vh[i] += 10;
			}
			v[i] = vh[i] - vl[j];
		}
		while (i-- > 0) {
			v[i] = vh[i];
		}
		if (hneg == true)
			cout << '-';
		int spos = 0;
		for (int i = 0; i < v.size(); ++i)
			if (v[i] != 0) {
				spos = i;
				break;
			}
		for (int i = spos; i < v.size(); ++i)
			cout << v[i];
		cout << endl;
	}
	else {
		int i = vh.size() - 1;
		for (int j = vl.size() - 1; i >= 0 && j >= 0; --i, --j) {
			v[i] += vh[i] + vl[j];
			if (v[i] >= 10) {
				if (i == 0)
					v.insert(v.begin(), 1);
				else
					v[i - 1]++;
				v[i] -= 10;
			}
		}
		while (i-- > 0) {
			v[i] += vh[i];
		}
		int spos = 0;
		for (int i = 0; i < v.size(); ++i)
			if (v[i] != 0) {
				spos = i;
				break;
			}
		for (int i = spos; i < v.size(); ++i)
			cout << v[i];
		cout << endl;
	}
}