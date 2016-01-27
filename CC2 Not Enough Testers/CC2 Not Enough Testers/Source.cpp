#include<cstdio>
using namespace std;
int t, k, a, b, n;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &k, &a, &b);
		int match = 0;
		for (int i = a; i <= b; ++i) {
			int power = 0, ii = i, factors = 1;
			for (int j = 2; j*j <= i; ++j) {
				while (ii%j == 0) {
					ii /= j;
					++power;
				}
				factors *= (power + 1);
			}
			if (factors == k) ++match;
			printf("%d %d %d %d %d\n", match, factors, power, i, ii);
		}
		printf("%d\n", match);
	}
}