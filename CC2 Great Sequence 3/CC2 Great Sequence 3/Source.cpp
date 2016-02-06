#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define M (int)10e5
vector<int>ar(M + 2), aj[2002];
int n, k, q, a, b, x, y, sm[M + 2];
bool search(const int&a) {
	for (const int&i : aj[a + 1000])
		if (i >= x&&i <= y)
			return true;
	return false;
}
int main() {
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1, j; i <= n; ++i) {
		scanf("%d", &j);
		ar[i] = j;
		sm[i] = sm[i - 1] + j;
		if (j >= -1000 && j <= 1000) {
			aj[j + 1000].push_back(i);
		}
	}
	while (q--) {
		scanf("%d%d%d%d", &a, &b, &x, &y);
		printf("%s\n", abs(sm[y] - sm[x]) > k && search(a) && search(b) ? "Yes" : "No");
	}
}