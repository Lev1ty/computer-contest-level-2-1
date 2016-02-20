#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define HASH 1
#define DOT -1
vector<vector<int>>v;
int n;
int main() {
	cin >> n;
	v.resize(n);
	for (vector<int>&vv : v)
		vv.resize(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c; cin >> c;
			v[i][j] = c == '.' ? DOT : HASH;
		}
	}
	for (int row = n - 1; row >= 1; --row) {
		for (int col = 0; col < n; ++col) {
			if (v[row][col] >= HASH&&col + 1 < n&&v[row - 1][col + 1] == HASH) {
				bool triple = true;
				for (int triplet = 0; triplet < 3; ++triplet) {
					if (col + triplet == n || v[row][col + triplet] == DOT) {
						triple = false;
						break;
					}
				}
				if (triple) {
					v[row - 1][col + 1] = v[row][col] + 1;
				}
			}
		}
	}
	int s = 0;
	for (vector<int>&vv : v)
		for (int&i : vv)
			if (i>0)
				s += i;
	cout << s << endl;
}