#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 1;

long long arr[MAX];

long long func(int num, int exp)
{
	if (exp == 0)
	{
		return 1;
	}

	if (exp == 1)
	{
		return num;
	}

	long long temp = func(num, exp / 2) % MOD;

	if (exp % 2)
	{
		return (temp * temp) % MOD * num;
	}
	else
	{
		return (temp * temp) % MOD;
	}
}

void initialize(void)
{
	long long result = 0;
	for (long long i = 1; i < MAX; i++)
	{
		arr[i] = (arr[i - 1] + (func(i, i) % MOD)) % MOD;
		arr[i] %= MOD;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	initialize();

	for (int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;

		cout << "#" << t << " " << arr[N] << "\n";
	}

	return 0;
}