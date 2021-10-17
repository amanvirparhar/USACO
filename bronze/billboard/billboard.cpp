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

	int t[4];
	for (int i = 0; i < 4; i++) {
		int temp = 0;
		fin >> temp;
		t[i] = temp + 1000;
	}

	char arr[s][s];
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			arr[i][j] = 'O';
		}
	}

	for (int i = b1[0]; i < b1[2]; i++) {
		for (int j = b1[1]; j < b1[3]; j++) {
			arr[i][j] = 'X';
		}
	}

	for (int i = b2[0]; i < b2[2]; i++) {
		for (int j = b2[1]; j < b2[3]; j++) {
			arr[i][j] = 'X';
		}
	}

	for (int i = t[0]; i < t[2]; i++) {
		for (int j = t[1]; j < t[3]; j++) {
			arr[i][j] = 'O';
		}
	}

	int area = 0;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (arr[i][j] == 'X') {
				area++;
			}
		}
	}

	fout << area << endl;
}