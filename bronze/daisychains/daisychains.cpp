#include <bits/stdc++.h>
using namespace std;

ifstream fin("daisychains.in");
ofstream fout("daisychains.out");

int main() {
	int n;
	fin >> n;

	int flowers[n];
	int avgf = 0;

	for (int i = 0; i < n; i++) {
		fin >> flowers[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			double sum = 0;

			for (int k = i; k <= j; k++) {
				sum += flowers[k];
			}

			for (int k = i; k <= j; k++) {
				if (flowers[k] == sum / (j - i + 1)) {
					avgf++;
					break;
				}
			}
		}
	}

	fout << avgf << endl;
}