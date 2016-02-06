#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 100000
int ar[SIZE + 2];
vector<int>v[SIZE + 2];
int t, k, a, b;
int main() {
	memset(ar, 1, sizeof(ar));
	for (int i = 2; i <= SIZE; ++i) {
		for (int j = i; j <= SIZE; j += i) {
			++ar[j];
			v[ar[j]].push_back(j);
		}
	}
	cin >> t;
	while (t--) {
		cin >> k >> a >> b;
		if (!v[k].empty()) {
			cout << (upper_bound(v[k].begin(), v[k].end(), b) - lower_bound(v[k].begin(), v[k].end(), a)) << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}