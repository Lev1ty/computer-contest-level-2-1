#define HASH ('#')
#define DOT ('.')
#define DOUBLELAYERS ('#' + 1)
#define TRIPLELAYERS ('#' + 2)
#include<iostream>
#include<vector>
using namespace std;
int n, h, d, t;
vector<vector<short>>v;
int main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			char k; cin >> k;
			if (k == HASH) {
				v[i].push_back(HASH);
				++h;
			}
			else {
				v[i].push_back(DOT);
			}
		}
	}
	for (int i = 1; i <= n - 1; ++i) {
		for (int j = 1; j <= n - 1; ++j) {
			if (v[i][j] == HASH&&v[i + 1][j] == HASH&&v[i + 1][j + 1] == HASH&&v[i + 1][j - 1] == HASH) {
				v[i][j] = DOUBLELAYERS;
				++d;
			}
		}
	}
	for (int i = 1; i <= n - 2; ++i) {
		for (int j = 2; j <= n - 3; ++j) {
			if (v[i][j] == DOUBLELAYERS) {
				bool flag = false;
				for (int k = j - 2; k <= j + 2; ++k) {
					if (v[i + 2][k] == DOT) {
						flag = true;
					}
				}
				if (!flag) {
					v[i][j] = TRIPLELAYERS;
					++t;
				}
			}
		}
	}
	cout << (h + d + t) << endl;
}