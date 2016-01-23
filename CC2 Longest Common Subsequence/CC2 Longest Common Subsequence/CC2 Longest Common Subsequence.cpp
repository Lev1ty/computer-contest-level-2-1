#define d(x) /*x*/
#define debug
#ifdef debug
#define d(x) x
#endif
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int s1s, s2s;
vector<int> s1; vector<int> s2;
vector<vector<int>> v;
int main() {
	cin >> s1s >> s2s;
	s1.reserve(s1s);
	s2.reserve(s2s);
	for (int i = 0, j; i < s1s; i++) { cin >> j; s1.push_back(j); }
	for (int i = 0, j; i < s2s; i++) { cin >> j; s2.push_back(j); }
	v.resize(s1.size());
	for (vector<int>&vec : v) vec.resize(s2.size());
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (i == 0 || j == 0) v.at(i).at(j) = 0;
			else if (s1.at(i) == s2.at(j)) v.at(i).at(j) = v.at(i).at(j - 1);
		}
	}
	d(for_each(v.begin(), v.end(), [](vector<int>&vec)
	{for_each(vec.begin(), vec.end(), [](int&i)
	{cout << i << ' ';});cout << endl;});)
}

