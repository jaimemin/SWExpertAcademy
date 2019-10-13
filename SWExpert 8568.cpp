#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

		vector<pair<int, int>> v(N);

		for (int i = 1; i <= N; i++)
		{
			cin >> v[i - 1].first;
			
			v[i - 1].first %= 3;
			v[i - 1].second = i % 3;
		}

		int result = 0;

		for (int i = 0; i < N - 1; i++)
		{
			if (v[i].first == v[i].second)
			{
				continue;
			}

			for (int j = i + 1; j < N; j++)
			{
				if ((v[i].first == v[j].second) && (v[i].second == v[j].first))
				{
					swap(v[i].first, v[j].first);
					result++;

					break;
				}
			}
		}

		int unsorted = 0;

		for (int i = 0; i < N; i++)
		{
			if (v[i].first == v[i].second)
			{
				continue;
			}

			unsorted++;
		}

		result += (unsorted / 3) * 2;

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}