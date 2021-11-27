#include <bits/stdc++.h>
using namespace std;

ifstream fin("mixmilk.in");
ofstream fout("mixmilk.out");

int main() {
	int m[3];
	int c[3];

	for (int i = 0; i < 3; i++) {
		fin >> c[i] >> m[i];
	}

	for (int i = 1; i < 101; i++) {
		if (i % 3 == 1) {
			if (m[0] + m[1] < c[1]) {
				m[1] += m[0];
				m[0] = 0;
			} else {
				m[0] -= (c[1] - m[1]);
				m[1] = c[1];
			}
		} else if (i % 3 == 2) {
			if (m[1] + m[2] < c[2]) {
				m[2] += m[1];
				m[1] = 0;
			} else {
				m[1] -= (c[2] - m[2]);
				m[2] = c[2];
			}
		} else if (i % 3 == 0) {
			if (m[2] + m[0] < c[0]) {
				m[0] += m[2];
				m[2] = 0;
			} else {
				m[2] -= (c[0] - m[0]);
				m[0] = c[0];
			}
		}
	}

	fout << m[0] << endl << m[1] << endl << m[2] << endl;
}