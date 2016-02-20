#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<vector<int>>v;
#define DOT -1
#define HASH 0
int main() {
	cin >> n;
	v.resize(n + 2);
	for (vector<int>&vv : v)
		vv.resize(n + 2);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			char c; cin >> c;
			v[i][j] = c == '.' ? DOT : HASH;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (v[i][j] == HASH) {
				for (int k = 1; i + k <= n; ++k) {
					bool flag = false;
					for (int l = j - k; l <= j + k; ++l)
						if (l == 0 && l > n&&v[i][l] == DOT) {
							flag = true;
							break;
						}
					if (!flag) {
						++v[i][j];
					}
				}
			}
		}
	}
}