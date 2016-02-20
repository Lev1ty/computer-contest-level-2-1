#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int main() {
	scanf("%d", &n);
	while (n--&&scanf("%d", &m)) {
		vector<int>v;
		int z = 2;
		while (z*z <= m)
			if (m%z == 0) {
				v.push_back(z);
				m /= z;
			}
			else
				++z;
		sort(v.begin(), v.end());
		for (const int&i : v)
			printf("%d ", i);
		if (m > 1)
			printf("%d", m);
		printf("\n");
	}
}