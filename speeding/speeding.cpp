#include <bits/stdc++.h>
using namespace std;

ifstream fin("speeding.in");
ofstream fout("speeding.out");

int main() {
	int n, m;
	fin >> n >> m;

	int total_miles = 0;

	int miles[n];
	int limits[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				fin >> miles[i];
				total_miles += miles[i];
			} else if (j == 1) {
				fin >> limits[i];
			}
		}
	}

	int speeds[total_miles];

	int section = 0;
	int uptill = 0;
	for (int i = 0; i < total_miles; i++) {
		if ((i - uptill) > miles[section]) {
			uptill += miles[section];
			section++;
		}
		speeds[i] = limits[section];
	}

	int d_miles[m];
	int d_speeds[m];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				fin >> d_miles[i];
			} else if (j == 1) {
				fin >> d_speeds[i];
			}
		}
	}

	int r_speeds[total_miles];

	int section2 = 0;
	int uptill2 = 0;
	for (int i = 0; i < total_miles; i++) {
		if ((i - uptill2) > d_miles[section2]) {
			uptill2 += d_miles[section2];
			section2++;
		}
		r_speeds[i] = d_speeds[section2];
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << d_miles[i] << " " << d_speeds[i] << endl;
	// }
	
	// cout << "\n";

	int max_speed = r_speeds[0] - speeds[0];

	for (int i = 0; i < total_miles; i++) {
		if ((r_speeds[i] - speeds[i]) > max_speed) {
			max_speed = r_speeds[i] - speeds[i];
		}
	}

	if (max_speed < 0) {
		max_speed = 0;
	}

	fout << max_speed << endl;
}