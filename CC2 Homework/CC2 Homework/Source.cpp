#include<iostream>
#include<algorithm>
using namespace std;
int t, a, b, k;
constexpr int SIZE = (int)10e7;
bool prime[SIZE + 2], factors[SIZE + 2];
int main() {
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= SIZE; i++) {
		if (prime[i]) {
			//cout << i << " is prime" << endl;
			for (long long j = 1LL*i*i; j <= SIZE; j += i)
				prime[j] = false;
		}
	}
	cin >> t;
	for (int i = 1, cnt; cnt = 0, i <= t; ++i) {
		memset(factors, 0, sizeof(factors));
		scanf("%d%d%d", &a, &b, &k);
		for (int n, z, amt; amt = 0, n = a, z = 2, a <= b; ++a) {
			while (z*z <= n)
				if (n%z == 0)
					factors[z] = true, n /= z;
				else
					++z;
			for (long long i = 0; i <= a; ++i)
				if (factors[i] && prime[i])
					++amt;
			if (amt == k)
				++cnt;
		}
		printf("Case #%d: %d\n", i, cnt);
	}
}