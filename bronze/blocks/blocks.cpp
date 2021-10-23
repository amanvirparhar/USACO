#include <bits/stdc++.h>
using namespace std;

ifstream fin("blocks.in");
ofstream fout("blocks.out");

int main() {
	int n;
	fin >> n;

	vector<pair<string, string>> words;

	string first, second;
	for (int i = 0; i < n * 2; i++) {
		if (i % 2 == 0) {
			fin >> first;
		} else {
			fin >> second;
			words.push_back({ first, second });
		}
	}

	int c[26] = { 0 };
	for (pair<string, string> p : words) {
		for (int i = 97; i < 123; i++) {
			c[i - 97] += max(count(p.first.begin(), p.first.end(), (char)i), count(p.second.begin(), p.second.end(), (char)i));
		}
	}

	for (int i : c) {
		fout << i << endl;
	}
}