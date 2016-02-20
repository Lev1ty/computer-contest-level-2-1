#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int>al[8], q, ans;
bool nodes[8]; int ins[8];
void dfs(const int&pos) {
	for (const int&i : al[pos])
		--ins[i];
	ans.push_back(pos);
	nodes[pos] = true;
	vector<int>qq;
	for (auto it = al[pos].begin(); it != al[pos].end(); ++it)
		if (!nodes[*it] && !ins[*it])
			qq.push_back(*it);
	sort(qq.begin(), qq.end());
	for (const int&i : qq)
		dfs(i);
}
int main() {
	memset(nodes, true, sizeof(nodes));
	al[1].push_back(7); ins[7]++;
	al[1].push_back(4);	ins[4]++;
	al[2].push_back(1); ins[1]++;
	al[3].push_back(4); ins[4]++;
	al[3].push_back(5); ins[5]++;
	for (int i, j; cin >> i >> j, i&j;)
		al[i].push_back(j), ins[j]++;
	for (vector<int>&v : al) {
		sort(v.begin(), v.end());
		for (const int&i : v)
			nodes[i] = false;
	}
	for (int i = 1; i < 8; ++i)
		if (nodes[i])
			q.push_back(i);
	while (!q.empty()) {
		dfs(q.front());
		q.erase(q.begin());
	}
	for (const bool&b : nodes)
		if (!b) {
			cout << "Cannot complete these tasks. Going to bed.\n" << endl;
			return 0;
		}
	for (const int&i : ans)
		cout << i << ' ';
	cout << endl;
}