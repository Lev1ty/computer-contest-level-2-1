#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int dp[100002], sum[100002], last[100002];
//int sum(const int&index) { int sum = 0; for (int i = 1; i <= index; i++) sum += a[i]; return sum; }
int main() {
	cin >> s;
	dp[0] = 1;
	for (int i = 1; i <= s.length(); i++) {
		int lastpos = upper_bound(s.begin(), s.end(), s[i]) - s.begin();
		dp[i] = sum[i - 1] - sum[last[s[i]] - 1];
		sum[i] = sum[i - 1] + dp[i];
		last[s[i]] = i;
	}
	cout << sum[s.length()] << endl;
}