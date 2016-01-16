#include <iostream>
#include <vector>
//#define DEBUG
#define debug(a) /*a*/
#ifdef DEBUG
#include <algorithm>
#define debug(a) a
#endif // DEBUG
using namespace std;
void t(int n) {
	vector<int>t; t.reserve(n);
	int nc = n;
	while (nc--) {
		int nn; cin >> nn;
		t.push_back(nn);
	}
	debug(auto lwrite = [](int&i) {cout << i << ' ';};
	for_each(t.begin(), t.end(), lwrite); cout << endl;)
	int c = 1;
	vector<int>l; l.reserve(n);
	vector<int>b; b.reserve(n);
	while (!t.empty()) {
		int nn = t.back(); t.pop_back();
		if (nn == c) {
			++c;
			l.push_back(nn);
		}
		else {
			b.push_back(nn);
		}
		while (!b.empty()&&b.back() == c) {
			++c;
			l.push_back(b.back());
			b.pop_back();
		}
	}
	while (!b.empty()&&b.back() == c) {
		l.push_back(b.back()); b.pop_back();
		++c;
	}
	debug(cout << c << endl;
	for_each(b.begin(), b.end(), lwrite); cout << endl;
	for_each(l.begin(), l.end(), lwrite); cout << endl;)
	cout << (b.empty() ? "Y" : "N") << endl;
}
int main() {
	int n, nn; cin >> n;
	while (n--) {
		cin >> nn;
		t(nn);
	}
}