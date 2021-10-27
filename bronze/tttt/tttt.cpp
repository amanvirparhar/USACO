#include <bits/stdc++.h>
using namespace std;

ifstream fin("tttt.in");
ofstream fout("tttt.out");

int main() {
	char list[9];

	for (int i = 0; i < 9; i++) {
		fin >> list[i];
	}

	char combos[8][3] = {
		{ list[0], list[1], list[2] },
		{ list[3], list[4], list[5] },
		{ list[6], list[7], list[8] },
		{ list[0], list[3], list[6] },
		{ list[1], list[4], list[7] },
		{ list[2], list[5], list[8] },
		{ list[0], list[4], list[8] },
		{ list[2], list[4], list[6] },
	};

	set<char> indies;
	set<pair<char, char>> teams;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			int cnt = count(&combos[i][0], &combos[i][0] + 3, combos[i][j]);
			if (cnt == 3) {
				indies.insert(combos[i][0]);
				break;
			} else if (cnt == 2) {
				set<char> chars;
				chars.insert(combos[i][0]);
				chars.insert(combos[i][1]);
				chars.insert(combos[i][2]);
				teams.insert({ *next(chars.begin(), 0), *next(chars.begin(), 1) });
				break;
			}
		}
	}

	fout << indies.size() << endl << teams.size() << endl;
}