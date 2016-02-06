#include<iostream>
using namespace std;
#define SIZE 1000000
bool prime[SIZE + 2];
int main() {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= SIZE; ++i) {
		if (prime[i]) {
			cout << i << " is prime" << endl;
			for (long long j = 1LL*i*i; j <= 100000; ++j) {
				prime[j] = false;
			}
		}
	}
}