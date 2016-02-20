#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n; vector<int>l[(int)10E5];
vector<int>v;
int main() {
	cin >> n;
	for (int j; n--&&cin >> j;)
		v.push_back(j);
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; --i) {
		for (int j = i - 1; j >= 0; --j) {
			l[v[i] - v[j]].push_back(v[j]);
			if (((v[i] - v[j]) / 2) * 2 == (v[j] - v[i]))
				if (!l[(v[i] - v[j]) / 2].empty()) {
					cout << (l[v[i] - v[j]].front() + v[j] + v[i]) << endl;
					return 0;
				}
		}
		for (int k = 0; k < v[i]; ++k)
			l[k].clear();
	}
}