#include <bits/stdc++.h>
using namespace std;

ifstream fin("circlecross.in");
ofstream fout("circlecross.out");

int main() {
	vector<pair<int, int>> p;

	for (int i = 0; i < 26; i++) {
		p.push_back({ -1, -1 });
	}

	char temp;
	for (int i = 0; i < 52; i++) {
		fin >> temp;
		if (p[(int)(temp - 65)].first == -1) {
			p[(int)(temp - 65)].first = i;
		} else {
			p[(int)(temp - 65)].second = i;
		}
	}

	int cross_count = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			if (p[j].first > p[i].first && p[j].first < p[i].second && p[j].second > p[i].second) {
				cross_count++;
			} else if (p[i].first > p[j].first && p[i].first < p[j].second && p[i].second > p[j].second) {
				cross_count++;
			}
		}
	}

	fout << cross_count << endl;
}