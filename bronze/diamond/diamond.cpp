#include <bits/stdc++.h>
using namespace std;

ifstream fin("diamond.in");
ofstream fout("diamond.out");

int main() {
	int n, k;
	fin >> n >> k;

	vector<int> v;

	int temp;
	for (int i = 0; i < n; i++) {
		fin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int total = 0;

	for (u_int i = 0; i < v.size(); i++) {
		int c = 1;

		for (u_int j = i + 1; j < v.size(); j++) {
			if (v[j] - v[i] <= k) {
				c++;
			} else {
				break;
			}
		}

		total = max(total, c);
	}

	fout << total << endl;
}