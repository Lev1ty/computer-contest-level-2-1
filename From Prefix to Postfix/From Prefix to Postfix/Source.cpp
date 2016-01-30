#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string>v;
string ss;
int main() {
	cin >> ss;
	while (!ss.empty()) {
		char c = ss.back(); ss.pop_back();
		string s; s.push_back(c);
		if (c >= 'a'&&c <= 'z')
			v.push_back(s);
		else {
			string s1 = v.back(); v.pop_back();
			string s2 = v.back(); v.pop_back();
			string s3 = s1 + s2 + s;
			v.push_back(s3);
		}
		//for (auto it = v.rbegin(); it != v.rend(); ++it)
		//	cout << *it << endl;
	}
}