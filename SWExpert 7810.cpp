#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000 + 1;

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

		vector<int> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		int result = 0;
		for (int i = 1; i <= N; i++)
		{
			if (v[N - i] >= i)
			{
				result = i;
			}
		}

		cout << "#" << t << " " << i << "\n";
	}

	return 0;
}