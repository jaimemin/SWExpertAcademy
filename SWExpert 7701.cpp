#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
	if (a.length() < b.length())
	{
		return true;
	}

	if (a.length() == b.length())
	{
		if (a < b)
		{
			return true;
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;

		vector<string> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		v.erase(unique(v.begin(), v.end()), v.end());

		sort(v.begin(), v.end(), cmp);

		cout << "#" << t << "\n";
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << "\n";
		}
	}

	return 0;
}