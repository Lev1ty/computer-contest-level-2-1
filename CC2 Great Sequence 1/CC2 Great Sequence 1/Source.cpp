#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>p, v;
bool barr[2001];
int n, k, q, a, b, x, y, t;
int main() {
	cin >> n >> k >> q;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		p.push_back(p.empty() ? t : p.back() + t);
		v.push_back(t);
		if (t >= -1000 && t <= 1000)
			barr[t + 1000] = true;
	}
	for (int i = 0; i < q; ++i) {
		cin >> a >> b >> x >> y;
		cout << (barr[a + 1000] && barr[b + 1000] && (abs(p.at(--x) - p.at(y - 1)) > k) ? "Yes" : "No") << endl;
	}
}