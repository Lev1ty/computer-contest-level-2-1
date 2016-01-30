#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, nn;
vector<int>v;
int bsearch(int n, int low, int high) {
	int piv = -1;
	while (low <= high) {
		piv = low + (high - low)/2;
		if (v[piv] == n) return piv;
		else if (v[piv] > n) high = piv - 1;
		else low = piv + 1;
	}
	return piv;
}
int main() {
	cin >> n >> nn;
	for (int k = 0; n--&&cin >> k;)
		v.push_back(k);
	sort(v.begin(), v.end());
	int pos = bsearch(nn, 0, v.size() - 1);
	cout << (pos == -1 ? "Range error" : pos == 0 ? "Not found." : "") << (pos > 0 ? pos : ' ') << endl;
}