#include <bits/stdc++.h>
using namespace std;

ifstream fin("billboard.in");
ofstream fout("billboard.out");

const int s = 2000;

int main() {
	int b1[4];
	for (int i = 0; i < 4; i++) {
		int temp = 0;
		fin >> temp;
		b1[i] = temp + 1000;
	}

	int b2[4];
	for (int i = 0; i < 4; i++) {
		int temp = 0;
		fin >> temp;
		b2[i] = temp + 1000;
	}

	char arr[s][s];
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			arr[i][j] = 'O';
		}
	}

	int x_count = 0;
	for (int i = b1[0]; i < b1[2]; i++) {
		for (int j = b1[1]; j < b1[3]; j++) {
			arr[i][j] = 'X';
			x_count++;
		}
	}

	for (int i = b2[0]; i < b2[2]; i++) {
		for (int j = b2[1]; j < b2[3]; j++) {
			arr[i][j] = 'O';
		}
	}

	if ((b1[0] <= b2[0] && b1[1] >= b2[1] && b1[2] >= b2[2] && b1[3] <= b2[3]) || (b2[0] <= b1[0] && b2[1] >= b1[1] && b2[2] >= b1[2] && b2[3] <= b1[3])) {
		fout << x_count << endl;
		return 0;
	}

	int max_l = 0;
	for (int i = 0; i < s; i++) {
		int l = 0;

		for (int j = 0; j < s; j++) {
			if (arr[i][j] == 'X') {
				l++;
			}
		}

		if (l > max_l) {
			max_l = l;
		}
	}

	int max_w = 0;
	for (int i = 0; i < s; i++) {
		int w = 0;

		for (int j = 0; j < s; j++) {
			if (arr[j][i] == 'X') {
				w++;
			}
		}
		if (w > max_w) {
			max_w = w;
		}
	}

	fout << max_l * max_w << endl;
}