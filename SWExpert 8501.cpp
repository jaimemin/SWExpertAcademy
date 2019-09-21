#include <iostream>
using namespace std;

const int MAX = 1e3 + 1;
const int MOD = 1e9 + 7;

long long cache[MAX];
long long factorial[MAX];

void preCalculate(void)
{
	factorial[0] = 1;
	
	for (int i = 1; i < MAX; i++)
	{
		factorial[i] = (factorial[i - 1] * i) % MOD;
	}

	for (int i = 2; i < MAX; i++)
	{
		cache[i] = (i * cache[i - 1] + (i / 2) * factorial[i - 1]) % MOD;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	preCalculate();

	for (int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;

		cout << "#" << t << " " << cache[N] << "\n";
	}

	return 0;
}