#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 11;

vector<long long> v[MAX];

int getDigit(int num)
{
	int digit = 0;

	while (num)
	{
		digit++;
		num /= 10;
	}

	return digit;
}

void initialize(void)
{
	long long num = 1e10;
	int digit = 10;

	while (num)
	{
		for (long long i = 1; i*i <= num; i++)
		{
			if (num % i == 0)
			{
				v[digit].push_back(i);
				v[digit].push_back(num / i);
			}
		}
		
		num /= 10;
		digit--;
	}

	for (int i = 1; i < MAX; i++)
	{
		sort(v[i].begin(), v[i].end());
		v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
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
		int X;
		cin >> X;

		int digit = getDigit(X);
		int answer = 0;

		vector<int> result;
		for (int i = digit; i >= 1; i--)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				long long num = v[i][j];
				int tempDigit = getDigit(num);

				if (i == tempDigit)
				{
					if ((i == digit && num <= X) || i < digit)
					{
						result.push_back(num);
					}
				}
			}
		}

		sort(result.begin(), result.end());

		cout << "#" << t << " " << result.size() << "\n";
	}

	return 0;
}