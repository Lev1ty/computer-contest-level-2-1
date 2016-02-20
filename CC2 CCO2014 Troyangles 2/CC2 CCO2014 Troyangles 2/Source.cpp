#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define DOT -1
#define HASH 1
int n, o;
vector<vector<int>>v;
int main() {
	cin >> n;
	v.resize(n);
	for (vector<int>&vv : v)
		vv.resize(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			char k; cin >> k;
			v[i][j] = k == '.' ? DOT : HASH;
		}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] == HASH) {
				for (int k = 1, b = 0; k < n; ++k, b = 0) {
					for (int l = j - k; l <= j + k; ++l) {
						if (l < 0 || l >= n || i + k >= n || v[i + k][l] == DOT) {
							b = 1;
							break;
						}
					}
					if (b == 0) {
						++v[i][j];
					}
				}
			}
		}
	}
	for (vector<int>&vv : v)
		for (int&i : vv)
			if (i>0)
				o += i;
	cout << o << endl;
}