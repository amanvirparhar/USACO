#include <bits/stdc++.h>
using namespace std;

ifstream fin("uddered.in");

int main() {
	string alphabet, str;
	cin >> alphabet >> str;

	string mod_alph = alphabet;
	int alph_count = 1;

	int i = 0;

	while ((u_int) i < str.length()) {
		size_t found = mod_alph.find(str[i]);

		if (found == string::npos) {
			mod_alph = alphabet;
			alph_count++;
		}

		found = mod_alph.find(str[i]);
		mod_alph = mod_alph.erase(0, found + 1);
		i++;
	}
	
	cout << alph_count << endl;
}