#include <bits/stdc++.h>
using namespace std;

ifstream fin("abc.in");
ofstream fout("abc.out");

int main() {
	int nums[7], currentnum, a = INT_MAX, ai, b, c, abc = INT_MIN, bc;

	for (int i = 0; i < 7; i++) {
		fin >> currentnum;
		nums[i] = currentnum;

		if (nums[i] < a) {
			a = nums[i];
			ai = i;
		}

		if (nums[i] > abc) {
			abc = nums[i];
		}
	}

	bc = abc - a;

	for (int i = 0; i < 7; i++) {
		for (int j = i; j < 7; j++) {
			if (nums[i] + nums[j] == bc && i != ai && j != ai) {
				if (nums[i] > nums[j]) {
					b = nums[j];
					c = nums[i];
				} else {
					b = nums[i];
					c = nums[j];
				}
			}
		}
	}

	fout << a << " " << b << " " << c << endl;
}