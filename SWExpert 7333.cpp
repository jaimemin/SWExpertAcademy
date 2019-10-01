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

		vector<int> v;
		int result = 0;

		for (int i = 0; i < N; i++)
		{
			int weight;
			cin >> weight;

			if (weight >= 50)
			{
				result++;

				continue;
			}

			v.push_back(weight);
		}

		if (v.empty())
		{
			cout << "#" << t << " " << result << "\n";

			continue;
		}

		sort(v.begin(), v.end());

		int idx = v.size() - 1;
		int top = v[idx];
		int sum = top;

		for (int i = 0; i < idx; i++)
		{
			sum += top;

			if (sum >= 50)
			{
				top = v[--idx];
				sum = top;

				result++;
			}
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}