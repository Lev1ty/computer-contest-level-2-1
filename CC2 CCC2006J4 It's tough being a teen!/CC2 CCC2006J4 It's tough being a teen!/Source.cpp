#include<iostream>
#include<vector>
#include<algorithm>
#define ERR_MSG "Cannot complete these tasks. Going to bed.\n"
using namespace std;
vector<int>ou[8], in[8], q, ans;
int main() {
	ou[1].push_back(7);
	in[7].push_back(1);
	ou[1].push_back(4);
	in[4].push_back(1);
	ou[2].push_back(1);
	in[1].push_back(2);
	ou[3].push_back(4);
	in[4].push_back(3);
	ou[3].push_back(5);
	in[5].push_back(3);
	for (int i, j; cin >> i >> j, i&j;)
		ou[i].push_back(j), in[j].push_back(i);
	for (int i = 1; i < 8; ++i)
		if (in[i].empty())
			q.push_back(i);
	while (!q.empty()) {
		int start = q.front(); q.erase(q.begin());
		ans.push_back(start);
		for (int i = 0; i < ou[start].size(); ++i)
			for (int j = 0; j < in[ou[start][i]].size(); ++j)
				if (in[ou[start][i]][j] == start)
					in[ou[start][i]].erase(in[ou[start][i]].begin() + j);
		vector<int>qq;
		int cnt = 0;
		for (int i = 0; i < ou[start].size(); ++i) {
			if (in[ou[start][i]].empty()) {
				qq.push_back(i);
				ou[start].erase(ou[start].begin() + i);
			}
		}
		sort(qq.begin(), qq.end());
		for (const int&i : qq)
			q.push_back(i);
	}
	for (const vector<int>&v : ou)
		if (!v.empty() && cout << ERR_MSG)
			return 0;
	for (const int&i : ans)
		cout << i << ' ';
	cout << endl;
}