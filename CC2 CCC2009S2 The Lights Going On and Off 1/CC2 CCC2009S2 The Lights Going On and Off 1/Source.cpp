#define debug(a) /*a*/
#ifdef DEBUG
#define debug(a) a
#endif // DEBUG
#include <iostream>
using namespace std;
int R, L;
bool g[31][9];
int main() {
	cin >> R >> L;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= L; ++j) {
			cin >> g[i][j];
		}
	}
	for (int i = 1; i <= 30; ++i) {

	}
}