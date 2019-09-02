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

		vector<int> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());
		
		long long result;
		if (N % 2)
		{
			result = v[N / 2] * v[N / 2] * 1LL;
		}
		else
		{
			result = v[0] * v[v.size() - 1] * 1LL;
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}