#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
int n, m; vector<pair<int, int>>x, y, z;
int main() {
	scanf("%d", &n);
	for (int i = 0, j, k; i < n && scanf("%d%d", &j, &k); ++i) {
		x.push_back(pair<int, int>(j, k));
		y.push_back(pair<int, int>(k, j));
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	scanf("%d", &m);
	for (int i = 0, j, k; i < m && scanf("%d%d", &j, &k); ++i)
		z.push_back(pair<int, int>(j, k));
	while (z.size() > 2) {
		pair<int, int>s = z.front(); 
		z.erase(z.begin());
		pair<int, int>e = z.front();
		if (s.first == e.first) {

		}
		else {

		}
	}
}