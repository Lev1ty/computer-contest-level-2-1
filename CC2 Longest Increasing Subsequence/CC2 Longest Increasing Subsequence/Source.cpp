#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> v1, v2;
#define debug(x) /*x*/
#ifdef debugmode
#define debug(x) x
#endif
int main() {
	cin >> N;
	v1.reserve(N + 1);
	v1.push_back(0);
	for (int i = 1, j; i <= N; i++) { cin >> j; v1.push_back(j); }
	v2.resize(N + 1);
	int h = 0;
	for (int i = 1, k = 0; i <= N; i++, k = 0) {
		for (int j = i - 1; j >= 0; j--) {
			if (v1.at(j) < v1.at(i)) k = max(v2.at(j), k);
		}
		v2.at(i) = ++k;
		h = max(k, h);
	}
	debug(
	for (int&i : v1) cout << i << ' '; cout << endl;
	for (int&i : v2) cout << i << ' '; cout << endl;
	)
		//sort(v2.rbegin(), v2.rend());
		//cout << v2.at(0) << endl;
		cout << h << endl;
}