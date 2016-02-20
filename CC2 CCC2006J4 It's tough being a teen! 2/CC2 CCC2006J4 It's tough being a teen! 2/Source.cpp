#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>al[8], q, ans; int to[8];
int main() {
	al[1].push_back(7);
	al[1].push_back(4);
	al[2].push_back(1);
	al[3].push_back(4);
	al[3].push_back(5);
	to[7] = 1;
	to[4] = 2;
	to[1] = 1;
	to[5] = 1;
	for (int i, j; cin >> i >> j, i&j;)
		al[i].push_back(j), ++to[j];
	for (vector<int>&v : al)
		sort(v.begin(), v.end());
	for (int i = 1; i < 8; ++i)
		if (!to[i])
			q.push_back(i);
	while (!q.empty()) {
		int pos = q.front(); 
		q.erase(q.begin());
		ans.push_back(pos);
		for (const int&i : al[pos])
			--to[i];
		for (const int&i : al[pos])
			if (!to[i])
				q.push_back(i);
		sort(q.begin(), q.end());
	}
	for (const int&i : to)
		if (i&&cout << "Cannot complete these tasks. Going to bed." << endl)
			return 0;
	for (const int&i : ans)
		cout << i << ' ';
	cout << endl;
	cin >> to[0];
}