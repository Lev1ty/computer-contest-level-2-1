#include<iostream>
#define SIZE (int)10e7
using namespace std;
int t, a, b, k, cnt, sieve[SIZE + 2];
void fill() {
	memset(sieve, 1, sizeof(sieve));
	for (int i = 2; i < SIZE + 2; ++i)
		if (sieve[i] == 1)
			for (int j = 2 * i; j < SIZE + 2; j += i)
				sieve[j] = sieve[j - i] + 1;
}
int main() {
	fill();
	cin >> t;
	for (int i = 1; i <= t; ++i, cnt = 0) {
		cin >> a >> b >> k;
		for (;a <= b;++a)
			if (sieve[a] == k)
				++cnt;
		printf("Case #%d: %d\n", i, cnt);
	}
}