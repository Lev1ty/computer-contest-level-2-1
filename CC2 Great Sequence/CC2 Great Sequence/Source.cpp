#include<cstdio>
#include<string>
using namespace std;
int n, k, q, a[static_cast<int>(10e5) + 1];
int aa, bb, xx, yy, c;
bool b1, b2;
int main() {
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	while (q--&&scanf("%d%d%d%d", &aa, &bb, &xx, &yy)&&!(c=0)&&!(b1=false)&&!(b2=false)) {
		for (;xx <= yy;c += a[xx++]) 
			a[xx] == aa ? b1 = true : a[xx] == bb ? b2 = true : false;
		printf((b1&&b2&&c > k ? "Yes\n" : "No\n"));
	}
}