#include <iostream>
#include <string>
using namespace std;
int N, good[31];
string first[31], second[31];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> first[i];
	for (int i = 0; i < N; i++) cin >> second[i];
	for (int i = 0; i < N; i++) {
		good[i] = true;
		string firstname = first[i];
		string secondname = second[i];
		if (firstname.compare(secondname) == 0) {
			cout << "bad";
			return 0;
		}
		for (int j = 0; j < N; j++) {
			bool inverseoffirst = false;
			bool inverseofsecond = false;
			if (first[i].compare(secondname) == 0) {
				inverseoffirst = true;
			}
			if (second[i].compare(firstname) == 0) {
				inverseofsecond = true;
			}
			if (inverseoffirst&&inverseofsecond) {
				for (int k = 0; k < N; k++) {
					if (first[k].compare(secondname) == 0) {
						good[k] = true;
					}
				}
			}
		}
	}
	bool flag = true;
	for (int i = 0; i < N; i++) if (good[i] == 0) flag = false;
	cout << (flag ? "good" : "bad");
}