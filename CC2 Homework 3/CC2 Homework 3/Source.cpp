#include<iostream>
#include<map>
using namespace std;
int t, a, b, k, se[(int)10e7 + 2];
multimap<int, int>m;
int main() {
	for (int i = 2; i < (int)10e7 + 2; ++i)
		if (se[i] == 0)
			for (int j = i; j < (int)10e7 + 2; j += i)
				++se[j];
	for (int i = 2; i < (int)10e7 + 2; ++i)
		m.insert(se[i], i);
}