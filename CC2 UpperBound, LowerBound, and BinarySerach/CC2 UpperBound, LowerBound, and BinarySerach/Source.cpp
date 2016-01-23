#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main() {
	v = { 1,2,4,6,8,10,20,20,20,20 };
	cout << lower_bound(v.begin(), v.end(), 20) - v.begin() << endl;
	cout << upper_bound(v.begin(), v.end(), 20) - v.begin() << endl;
}