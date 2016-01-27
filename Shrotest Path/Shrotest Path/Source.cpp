#include<iostream>
#include<vector>
#include<utility>
#define debug(x) /*x*/
#define DEBUG
#ifdef DEBUG
#define debug(x) x
#endif // DEBUG

using namespace std;
int nv, ne;
vector<vector<pair<int,int>>>v;
vector<vector<int>>vv;
vector<int>q;

int main() {
	scanf("%d%d", &nv, &ne);
	v.resize(nv + 1);
	int s, e, l;
	while (ne--&&scanf("%d%d%d", &s, &e, &l))
		v.at(s).push_back(pair<int, int>(e, l));
	debug(for (const vector<pair<int, int>>&vv : v) {
		for (const pair<int, int>&p : vv) {
			printf("%d %d\t", p.first, p.second);
		}
		printf("\n");
	});
	q.push_back(1);
	while (!q.empty()) {
		int s = q.front(); q.erase(q.begin());
		for (int i = 0; i < v.at(s).size(); i++) {
			
		}
	}
}