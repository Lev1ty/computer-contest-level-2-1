#include<iostream>
#include<vector>
#include<algorithm>
#define SIZE (int)10E5
using namespace std;
int n, in[SIZE + 2], maxx;
int main() {
	scanf("%d", &n);
	for (int i = 0, j; i < n&&scanf("%d", &j); ++i)
		in[i] = j;
	sort(in, in + n);
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i - 1; j >= 0; --j) {
			for (int k = j - 1; k >= 0; --k) {
				if (in[i] - in[j] == in[j] - in[k]) {
					if ((in[i] + in[j] + in[k])>maxx) {
						maxx = in[i] + in[j] + in[k];
					}
				}
			}
		}
	}
	printf("%d\n", maxx);
}