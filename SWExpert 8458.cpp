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

		int state = -1; 
		bool flag = true;
		long long distance = 0;

		for (int i = 0; i < N; i++)
		{
			long long x, y;
			cin >> x >> y;

			long long sum = abs(x) + abs(y);
			
			if (state == -1)
			{
				distance = sum;
				state = sum % 2;

				continue;
			}

			if (state != sum % 2)
			{
				flag = false;

				break;
			}

			distance = max(distance, sum);
		}

		if (!flag)
		{
			cout << "#" << t << " " << -1 << "\n";

			continue;
		}

		long long low = 0, high = 1e5;
		while (low <= high)
		{
			long long mid = (low + high) / 2;

			if ((mid * (mid + 1) / 2) >= distance)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}

		long long sum = (low * (low + 1)) / 2;

		while (sum % 2 != state)
		{
			low++;

			sum = (low * (low + 1) / 2);
		}

		cout << "#" << t << " " << low << "\n";
	}

	return 0;
}