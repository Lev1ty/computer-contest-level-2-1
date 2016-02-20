#include<iostream>
#include<vector>
#include<algorithm>
#define ERROR_MESSAGE "Cannot complete these tasks. Going to bed.\n"
using namespace std;
vector<int>var[8], q, ans;
int main() {
	var[1].push_back(7);
	var[1].push_back(4);
	var[2].push_back(1);
	var[3].push_back(4);
	var[3].push_back(5);
	for (int i, j; scanf("%d%d", &i, &j), i&j;)
		var[i].push_back(j);
	for (int i = 1; i < 8; ++i)
		if (var[i].empty())
			q.push_back(i);
	sort(q.begin(), q.end());
	while (!q.empty()) {
		int i = q.front(); q.erase(q.begin());
		ans.push_back(i);
		vector<int>qs;
		for (int&ii : var[i])
			qs.push_back(ii);
		var[i].clear();
		sort(qs.begin(), qs.end());
		for (const int&ii : qs)
			var[i].push_back(ii);
	}
	for (const vector<int>&v : var)
		if (!v.empty() && printf(ERROR_MESSAGE))
			return 0;
	for (const int&i : ans)
		printf("%d ", i);
	printf("\n");
}