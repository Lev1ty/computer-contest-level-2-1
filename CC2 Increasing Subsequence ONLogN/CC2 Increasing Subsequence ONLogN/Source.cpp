/*
Use binary search instead of normal search
Binary search is possible because increasing subsequence is strictly increasing
1 4 6 2 3 5
vec:
1
1 4
1 4 6
124 6 -> 1 2 6
1 236 -> 1 2 3
1 2 3 5
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define debug(x) /*x*/
//#define debugmode
#ifdef debugmode
#define debug(x) x
#endif
int s;
vector<int> v1, v2;
int main() {
	cin >> s; 
	v1.resize(s);
	for_each(v1.begin(), v1.end(), [](int&i) {cin >> i;});
	v2.reserve(s);
	for (int&it : v1) {
		if (it > (v2.size() == 0 ? 0 : v2.back())) v2.push_back(it);
		else *upper_bound(v2.begin(), v2.end(), it) = it;
		debug(for_each(v2.begin(), v2.end(), [](int&i) {cout << i << ' ';}); cout << endl;)
	}
	debug(for_each(v1.begin(), v1.end(), [](int&i) {cout << i << ' ';}); cout << endl;)
		debug(for_each(v2.begin(), v2.end(), [](int&i) {cout << i << ' ';}); cout << endl;)
		cout << v2.size() << endl;
}