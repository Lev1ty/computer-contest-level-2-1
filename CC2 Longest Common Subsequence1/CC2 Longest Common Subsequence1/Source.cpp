#include<iostream>
#include<algorithm>
using namespace std;
int ss1, ss2, m[1002][1002], s1[1002], s2[1002];
int main() {
	cin >> ss1 >> ss2;
	for (int i = 1; i <= ss1; i++) 
		cin >> s1[i];
	for (int i = 1; i <= ss2; i++) 
		cin >> s2[i];
	for (int i = 1; i <= ss1; i++)
		for (int j = 1; j <= ss2; j++) {
			if (s1[i] == s2[j]) m[i][j] = m[i - 1][j - 1] + 1;
			else m[i][j] = max(m[i - 1][j], m[i][j - 1]);
		}
	cout << m[ss1][ss2] << endl;
}