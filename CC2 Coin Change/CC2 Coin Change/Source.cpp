#include <iostream>
#include <algorithm>
using namespace std;
int ndist, nclub, in[100001], memo[10001];
int main() {
	cin >> ndist >> nclub;
	for (int i = 0; i < nclub; i++) {
		cin >> in[i];
	}
	for (int i = 1; i <= ndist; i++) {
		int mval = INT16_MAX;
		bool found = false;
		for (int j = 0; j < nclub; j++) {
			if (i - in[j] >= 0 && memo[i - in[j]] >= 0 && memo[i - in[j]] < mval) {
				mval = memo[i - in[j]];
				found = true;
			}
		}
		if (!found) memo[i] = -1;
		else memo[i] = mval + 1;
	}
	/*for (int i = 0; i <= ndist; i++)
	cout << memo[i] << ' ';*/
	cout << memo[ndist];
	/*if (memo[ndist] >= 0) cout << "Roberta wins in " << memo[ndist] << " strokes.";
	else cout << "Roberta acknowledges defeat.";*/
}