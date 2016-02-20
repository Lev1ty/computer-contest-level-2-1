#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int n, k, q, a, b, x, y;
vector<int> ps;
multimap<int, int>m;
bool search(const int&i) {
	for (auto it = m.lower_bound(i); it != m.upper_bound(i); ++it)
		if (it->second >= x&&it->second <= y)
			return true;
	return false;
}
int main() {
	scanf("%d%d%d", &n, &k, &q);
	ps.resize(n + 2);
	for (int i = 1, j; i <= n; ++i) {
		scanf("%d", &j);
		ps[i] = ps[i - 1] + j;
		m.insert(pair<int, int>(j, i));
	}
	while (q--) {
		scanf("%d%d%d%d", &a, &b, &x, &y);
		printf("%s\n", ps[y] - ps[x - 1] > k && search(a) && search(b) ? "Yes" : "No");
	}
}