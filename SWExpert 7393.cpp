#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100 + 1;
const int MOD = 1e9;

int N;
int cache[10][MAX][1 << 10];

int func(int digit, int length, int visited)
{
	if (length == N)
	{
		if (visited == (1 << 10) - 1)
		{
			return 1;
		}

		return 0;
	}

	int &result = cache[digit][length][visited];

	if (result != -1)
	{
		return result;
	}

	result = 0;

	if (digit >= 1)
	{
		result = (result + func(digit - 1, length + 1, visited | 1 << (digit - 1)) % MOD) % MOD;
	}

	if (digit < 9)
	{
		result = (result + func(digit + 1, length + 1, visited | 1 << (digit + 1)) % MOD) % MOD;
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
		cin >> N;

		int result = 0;
		for (int i = 1; i <= 9; i++)
		{
			memset(cache, -1, sizeof(cache));

			result += func(i, 1, 1 << i);
			result %= MOD;
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}