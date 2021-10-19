#include <bits/stdc++.h>
using namespace std;

ifstream fin("cownomics.in");
ofstream fout("cownomics.out");

int main() {
	int n, m;
	fin >> n >> m;

	char spotty[n][m];
	char plain[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fin >> spotty[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fin >> plain[i][j];
		}
	}

	int locs = 0;

	for (int i = 0; i < m; i++) {
		bool spotty_ATCG[4] = { 0 };
		bool plain_ATCG[4] = { 0 };

		for (int j = 0; j < n; j++) {
			if (spotty[j][i] == 'A') {
				spotty_ATCG[0] = true;
			} else if (spotty[j][i] == 'T') {
				spotty_ATCG[1] = true;
			} else if (spotty[j][i] == 'C') {
				spotty_ATCG[2] = true;
			} else if (spotty[j][i] == 'G') {
				spotty_ATCG[3] = true;
			}

			if (plain[j][i] == 'A') {
				plain_ATCG[0] = true;
			} else if (plain[j][i] == 'T') {
				plain_ATCG[1] = true;
			} else if (plain[j][i] == 'C') {
				plain_ATCG[2] = true;
			} else if (plain[j][i] == 'G') {
				plain_ATCG[3] = true;
			}
		}

		bool flag = true;
		for (int i = 0; i < 4; i++) {
			if (spotty_ATCG[i] && plain_ATCG[i]) {
				flag = false;
			}
		}

		if (flag) {
			locs++;
		}
	}

	fout << locs << endl;
}