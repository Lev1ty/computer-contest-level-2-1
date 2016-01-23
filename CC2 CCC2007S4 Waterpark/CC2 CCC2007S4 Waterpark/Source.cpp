#define RUN
#define DEBUG(x) x
#include<iostream>
#include<vector>
#ifdef RUN
#define DEBUG(x) /*x*/
#endif // RUN
using namespace std;
int n, m[10001], s, e;
vector<vector<int>> v;
int main() {
	scanf("%d", &n);
	v.resize(n + 1);
	do {
		scanf("%d%d", &s, &e);
		v.at(e).push_back(s);
	} while (s != 0);
	m[1] = 1;
	for (int i = 1; i <= n; i++)
		for (int&j : v.at(i))
			m[i] += m[j];
	DEBUG(
		cout << "n: " << n << endl;
		for (vector<int>&vec : v) {
			for (int&i : vec) {
				cout << i << ' ';
			}
			cout << endl;
		}
		for (int i = 0; i <= n + 1; i++) cout << i << ": " << m[i] << endl;
		cout << n << endl;
		)
		printf("%d\n", m[n]);
}