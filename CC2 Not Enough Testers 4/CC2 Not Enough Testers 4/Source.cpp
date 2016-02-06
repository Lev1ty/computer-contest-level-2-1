#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define M 100000
int t, k, a, b, cnt[M + 2];
vector<int>sol[M + 2];
int main() {
	for (int i = 1; i <= M; i++) {
		for (int j = i; j <= M; j += i) {
			++cnt[j];
		}
		sol[cnt[i]].push_back(i);
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &k, &a, &b);
		printf("%d\n", upper_bound(sol[k].begin(), sol[k].end(), b)
			- lower_bound(sol[k].begin(), sol[k].end(), a));
	}
}