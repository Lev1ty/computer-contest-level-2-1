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
#ifdef debugmode
#define debug(x) x
#endif
int s;
vector<int> v1;
int main() {
	cin >> s;
	v1.reserve(s + 1);
	v1.push_back(0);
	for (int i = 0, j; i < s; i++) {
		cin >> j;
		v1.push_back(j);
	}
}