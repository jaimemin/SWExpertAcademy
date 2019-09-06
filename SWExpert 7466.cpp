#include <iostream>
using namespace std;

int func(int N, int K)
{
	int result = 1;

	for (int i = N; i >= 1; i--)
	{
		if (K == 1)
		{
			break;
		}

		if (K % i == 0)
		{
			result *= i;
			K /= i;

			if (i >= K)
			{
				i = K + 1;
			}
		}
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N, K;
		cin >> N >> K;

		int result;
		if (N > K)
		{
			result = K;
		}
		else
		{
			result = func(N, K);
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}