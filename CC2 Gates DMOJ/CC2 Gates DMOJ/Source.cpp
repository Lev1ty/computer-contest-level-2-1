#include<iostream>
#include<set>
using namespace std;
int g, p;
set<int>gates;
int main() {
	scanf("%d%d", &g, &p);
	for (int i = 1; i <= g; i++)
		gates.insert(-i);
	for (int i = 0, plane; i < p; i++) {
		scanf("%d", &plane);
		if (gates.lower_bound(-plane) == gates.end()) {
			printf("%d\n", i);
			return 0;
		}
		gates.erase(gates.lower_bound(-plane));
	}
	printf("%d\n", p);
	return 0;
}