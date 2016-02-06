#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ar[100002];
int k, a, b, t;
int main() {
	memset(ar, 1, sizeof(ar));
	for (int i = 1; i <= 100000; ++i) {
		if (ar[i]) {
			for (long long j = i*i; j <= 100000; j += i) {
				ar[j] = 0;
			}
		}
	}
	cin >> t;
	while (t--) {
		cin >> k >> a >> b;
		if (k == 1 && a > 1) {
			cout << 0 << endl;
			continue;
		}
		else {
			cout << 1 << endl;
			continue;
		}
		if (k == 2) {
			int s = 0;
			for (; a <= b; ++a) {
				if (ar[a]) {
					s += 1;
				}
			}
			cout << s << endl;
		}
		else {
			int s = 0;
			for (; a <= b; ++a) {
				int j = 0;
				if (!ar[a]) {
					for (int i = a; i >= 1; --a) {
						if (a%i == 0) {
							++j;
						}
					}
				}
				if (j == k) {
					++s;
				}
			}
			cout << s << endl;
		}
	}
}