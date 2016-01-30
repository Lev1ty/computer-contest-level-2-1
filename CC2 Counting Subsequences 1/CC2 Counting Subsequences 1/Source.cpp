#include<iostream>
#include<string>
#define M 10007
using namespace std;
string s;
int dp[100003], memo[26];
int main() {
	cin >> s; s.insert(0, 1, '$');
	for (int i = 1; i < s.size(); ++i) {
		if (memo[s[i] - 'a'] == 0) {
			dp[i] = (2 * dp[i - 1] + 1) % M;
		}
		else {
			dp[i] = (2 * dp[i - 1] - dp[memo[s[i] - 'a'] - 1] + M) % M;
		}
		memo[s[i] - 'a'] = i;
	}
	cout << dp[s.size() - 1] << endl;
}