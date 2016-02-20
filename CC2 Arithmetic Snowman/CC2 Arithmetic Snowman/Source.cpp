#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<int>v;
int main() {
	cin >> n;
	for (int i; n-- && cin >> i;)
		v.push_back(i);
	sort(v.rbegin(), v.rend());
	for (const int&i : v) {
		for (const int&j : v) {
			if (i - j > 0) {
				int a = 2 * j - i;
				if (binary_search(v.rbegin(), v.rend(), a))
					m = max(m, a + i + j);
			}
		}
	}
	cout << m << endl;
}