#include <bits/stdc++.h>
using namespace std;

ifstream fin("lineup.in");
ofstream fout("lineup.out");

int main() {
	int n;
	fin >> n;

	vector<string> names = { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue" };
	vector<pair<string, string>> pairs;

	string str;
	string first;
	for (int i = 0; i < n * 2; i++) {
		fin >> str;
		if (find(names.begin(), names.end(), str) != names.end()) {
			if (i % 2 == 0) {
				first = str;
			} else {
				pairs.push_back(make_pair(first, str));
			}
		} else {
			i--;
		}
	}

	sort(names.begin(), names.end());

	do {
		bool combo = true;
		for (int i = 0; i < n; i++) {
			if (abs(find(names.begin(), names.end(), pairs[i].first) - find(names.begin(), names.end(), pairs[i].second)) != 1) {
				combo = false;
			}
		}

		if (combo) {
			for (auto n: names) {
				fout << n << endl;
			}

			return 0;
		}
	} while (next_permutation(names.begin(), names.end()));
}