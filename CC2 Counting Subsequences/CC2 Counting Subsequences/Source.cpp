#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string s;
int c;
vector<char>v;
int main() {
	cin >> s;
	v.push_back(' ');
	for (auto it = s.begin(); it != s.end(); ++it) {
		c = c * 2 + 1;
		auto itt = lower_bound(v.begin(), v.end(), *it);
		if (!v.empty() && v.back() == *it)
			c -= (v.size() - 1);
		else if (itt != v.end())
			c -= (itt - v.begin());
		v.push_back(*it);
		//for (char&c : v)
		//	cout << c << ' ';
		//cout << endl;
		//cout << c << endl;
	}
	cout << (c % 10007) << endl;
}