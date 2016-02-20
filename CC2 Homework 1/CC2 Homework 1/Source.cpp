#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t, a, b, k, cnt;
int primes(int n) {
	int z = 2; vector<int>v;
	//cout << n << endl;
	while (z*z <= n)
		if (n%z == 0) {
			n /= z;
			if (v.empty() || v.back() < z) {
				v.push_back(z);
			}
		}
		else
			++z;
	if (v.empty() || n != v.back())
		v.push_back(n);
	//for (const int&i : v)
	//	cout << i << ' ';
	//cout << endl;
	return v.size();
}
int main() {
	cin >> t;
	for (int i = 1; i <= t; ++i, cnt = 0) {
		cin >> a >> b >> k;
		int length = b - a;
		for (;a <= b;++a)
			if (primes(a) == k)
				++cnt;
		printf("Case #%d: %d\n", i, cnt);
	}
	cin >> t;
}