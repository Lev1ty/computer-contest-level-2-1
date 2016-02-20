#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int t, a, b, k;
int primacity(int num) {
	vector<int>v;
	for (int i = 2; i <= num; ++i) {
		if (num == 1)
			break;
		while (num%i == 0) {
			if (!binary_search(v.begin(), v.end(), i))
				v.push_back(i);
			num /= i;
		}
	}
	return v.size();
}
int main() {
	scanf("%d", &t);
	for (int i = 1, cnt; cnt = 0, i <= t; ++i) {
		scanf("%d%d%d", &a, &b, &k);
		for (;a <= b;++a)
			if (primacity(a) == k)
				++cnt;
		printf("Case #%d: %d\n", i, cnt);
	}
}