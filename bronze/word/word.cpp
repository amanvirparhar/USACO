#include <bits/stdc++.h>
using namespace std;

ifstream fin("word.in");
ofstream fout("word.out");

int num_spaces(string word) {
	int space_count = 0;

	for (char c : word) {
		if (isspace(c)) space_count++;
	}

	return space_count;
}

int main() {
	int n, k;
	fin >> n >> k;

	vector<string> words;
	string temp;

	for (int i = 0; i < n; i++) {
		if (fin >> temp) {
			if (i != 0 && (int)(words[i - 1].length() - num_spaces(words[i - 1]) + temp.length()) <= k) {
				words[i - 1] = words[i - 1] + " " + temp;
				i--;
			} else {
				words.push_back(temp);
			}
		}
	}

	for (string word : words) {
		cout << word << endl;
	}
}