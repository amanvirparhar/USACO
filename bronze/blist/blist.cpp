#include <bits/stdc++.h>
using namespace std;

ifstream fin("blist.in");
ofstream fout("blist.out");

int main()
{
	int n;
	fin >> n;

	int arr[1001] = {0};

	for (int i = 0; i < n; i++)
	{
		int s, t, b;
		fin >> s >> t >> b;

		for (int j = s; j < t; j++)
		{
			arr[j] += b;
		}
	}

	int max_buckets = 0;
	for (int e : arr)
	{
		max_buckets = max(max_buckets, e);
	}

	fout << max_buckets << endl;
}