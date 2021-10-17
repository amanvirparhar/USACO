#include <bits/stdc++.h>
using namespace std;

ifstream fin("pails.in");
ofstream fout("pails.out");

int main() {
	// Read inputs
	int x, y, m;
	fin >> x >> y >> m;

	// Initialize max_sum variable, which will be used to store maximum sum that is no more than m at any given point in the loops 
	int max_sum = 0;
	
	// Two for loops that have limits at m / x and m / y, inclusive. This tests every possible combination/sum of x and y.
	for (int i = 0; i <= (m / x); i++) {
		for (int j = 0; j <= (m / y); j++) {
			// Check if it is the maximum sum and if it's under m and makes it the new max_sum if so
			if ((i * x) + (j * y) > max_sum && (i * x) + (j * y) <= m) {
				max_sum = (i * x) + (j * y);
			}
		}
	}

	// Output max_sum
	fout << max_sum << endl;
}