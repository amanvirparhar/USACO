#include <bits/stdc++.h>
using namespace std;

ifstream fin("herding.in");
ofstream fout("herding.out");

int main() {
	vector<int> v;
	int input;

	for (int i = 0; i < 3; i++) {
		fin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	int diff_1 = v[1] - v[0];
	int diff_2 = v[2] - v[1];

	// Already consecutive (both)
	if (diff_1 == 1 && diff_2 == 1) {
		fout << 0 << endl << 0 << endl;
		return 0;
	}

	if (diff_1 == 2) {
		// One move (min)
		fout << 1 << endl;
		fout << diff_2 - 1 << endl;
	} else if (diff_2 == 2) {
		// One move (min)
		fout << 1 << endl;
		fout << diff_1 - 1 << endl;
	} else if (diff_1 < diff_2) {
		// Anything else is 2 moves (min)
		fout << 2 << endl << diff_2 - 1 << endl;
	} else if (diff_1 > diff_2) {
		// Anything else is 2 moves (min)
		fout << 2 << endl << diff_1 - 1 << endl;
	}

	// cout << v[0] << " " << v[1] << " " << v[2] << " " << endl;
}