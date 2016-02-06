#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, s; vector<vector<int>>v;
#define DOT 0
#define HASH 1
int Min(const int&a, const int&b, const int&c) {
	return min(min(a, b), min(b, c));
}
int main() {
	cin >> n;
	v.resize(n);
	for (vector<int>&vv : v) {
		vv.resize(n);
	}
	for (int i = 0; i < n; ++i) {
		char c;
		for (int j = 0; j < n; ++j) {
			cin >> c;
			v[i][j] = c == '.' ? DOT : HASH;
		}
	}
	for (int i = v.size() - 1; i >= 1; --i) {
		for (int j = 0; j < v.size() - 2; ++j) {
			bool triple = true;
			for (int k = 0; k <= 2; ++k) {
				if (v[i][j + k] == DOT) {
					triple = false;
				}
			}
			if (v[i - 1][j + 1] == DOT) {
				triple = false;
			}
			if (triple) {
				v[i - 1][j + 1] = Min(v[i][j], v[i][j + 1], v[i][j + 2]) + 1;
			}
		}
	}
	for (vector<int>&vv : v) {
		for (int&i : vv) {
			s += i;
		}
	}
	cout << s << endl;
}