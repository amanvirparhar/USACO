#include <bits/stdc++.h>
using namespace std;

ifstream fin("lostcow.in");
ofstream fout("lostcow.out");

int main() {
	int x, y;
	fin >> x >> y;

	if (x == y) {
		fout << 0 << endl;
		return 0;
	}

	int p = 0;
	int moved = 0;
	int loc = x;
	int sign = 1;

	// cout << loc << " " << moved << endl;

	if (x > y) {
		while (loc > y) {
			int m = sign * pow(2, p);
			// cout << "m: " << m << endl;

			moved += abs(loc - x);
			loc = x + m;
			moved += abs(m);

			// cout << loc << " " << moved << endl;

			p++;
			sign *= -1;
		}
	} else {
		while (loc < y) {
			int m = sign * pow(2, p);
			// cout << "m: " << m << endl;

			moved += abs(loc - x);
			loc = x + m;

			moved += abs(m);

			// cout << loc << " " << moved << endl;

			p++;
			sign *= -1;
		}
	}

	if (loc != y) {
		moved -= abs(loc - y);
	}

	fout << moved << endl;
}