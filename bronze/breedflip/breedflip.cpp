#include <bits/stdc++.h>
using namespace std;

ifstream fin("breedflip.in");
ofstream fout("breedflip.out");

int main() {
	int len;
	fin >> len;

	char str1[len];
	char str2[len];
	vector<char> diff;

	for (int i = 0; i < len; i++) {
		fin >> str1[i];
	}

	int counter = 0;
	for (int i = 0; i < len; i++) {
		fin >> str2[i];

		if (str1[i] == str2[i]) {
			diff.push_back('_');
			if (i != 0 && diff[i - 1] != '_') {
				counter++;
			}
		} else {
			diff.push_back(str1[i]);
		}
	}

	// for (auto e : diff) {
	// 	cout << e << " ";
	// }
	// cout << endl << counter << endl;

	fout << counter << endl;
}