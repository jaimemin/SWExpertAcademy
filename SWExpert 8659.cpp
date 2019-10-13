#include <iostream>
using namespace std;

const int MAX = 180 + 1;

long long cache[MAX];

void preCalculate(void)
{
	cache[0] = cache[1] = 1;

	for (int i = 2; i < MAX; i++)
	{
		cache[i] = cache[i - 1] + cache[i - 2];
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
		int K;
		cin >> K;

		cout << "#" << t << " " << cache[K + 1] << " " << cache[K] << "\n";
	}
	
	return 0;
}