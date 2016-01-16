#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> v;
vector<string> vv;
int main() {
	int N; cin >> N;
	v.reserve(N); vv.reserve(N);
	auto lread = [N](vector<string>&vec) {string in; for (int i = 0; i < N; ++i) {
		cin >> in; vec.push_back(in);
	}};
	lread(v); lread(vv);
	for (int i = 0; i < N; ++i) {
		if (v.at(i).compare(vv.at(i)) == 0) {
			cout << "bad";
			return 0;
		}
	}
	for (int i = 0; i < N; ++i) {
		bool good = false;
		string s = v.at(i);
		string ss = vv.at(i);
		for (int j = 0; j < N; ++j) {
			if (v.at(j).compare(ss) == 0 && vv.at(j).compare(s) == 0) {
				good = true;
			}
		}
		if (!good) {
			cout << "bad";
			return 0;
		}
	}
	cout << "good";
}