#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>v; int n, maxx;
bool iscss(const vector<int>&v) {
	//for (const int&i : v)
	//	cout << i << ' ';
	//cout << v.size() << endl;
	for (int i = 1; i < v.size() - 1; ++i)
		if (abs(v[i - 1] - v[i])>2 || abs(v[i] - v[i + 1]) > 2)
			return false;
	if (v.size() >= 3)
		return true;
	else return false;
}
int main() {
	cin >> n; v.reserve(n);
	for (int i; n--&&scanf("%d", &i);)
		v.push_back(i);
	for (int i = 1; i < v.size(); ++i)
		for (int j = i; j < v.size(); ++j)
			if (iscss(vector<int>(v.begin() + i - 1, v.begin() + j + 1)))
				maxx = max(maxx, j - i + 2);
	cout << maxx << endl;
	//cin >> n;
}