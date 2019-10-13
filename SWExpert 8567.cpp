#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAX = 100000;

int minFactor[MAX + 1];
int factorCnt[MAX + 1];
int result[MAX + 1];
vector<int> prime;
map<int, bool> reversePrime;

void eratosthenes(void)
{
	minFactor[0] = minFactor[1] = -1;

	for (int i = 2; i <= MAX; i++)
	{
		minFactor[i] = i;
	}

	for (int i = 2; i*i <= MAX; i++)
	{
		if (minFactor[i] == i)
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				if (minFactor[j] == j)
				{
					minFactor[j] = i;
				}
			}
		}
	}

	for (int i = 2; i <= MAX; i++)
	{
		if (minFactor[i] == i)
		{
			prime.push_back(i);

			reversePrime[i] = true;
		}
	}
}

void preCalculate(void)
{
	factorCnt[1] = 1;

	for (int i = 2; i <= MAX; i++)
	{
		if (reversePrime.count(i))
		{
			factorCnt[i] = 2;

			continue;
		}

		int num = i;
		int idx = 0;
		int divider = prime[idx];
		
		vector<int> v;

		while (num != 1)
		{
			if (reversePrime.count(num))
			{
				v.push_back(num);

				break;
			}

			if (num % divider == 0)
			{
				num /= divider;
				v.push_back(divider);

				continue;
			}

			if (idx < prime.size() - 1 && prime[idx] < num)
			{
				divider = prime[++idx];

				continue;
			}

			v.push_back(num);
				
			break;
		}

		int factor = v[0];
		int cnt = 1;
		vector<int> cnts;

		for (int j = 1; j < v.size(); j++)
		{
			if (factor == v[j])
			{
				cnt++;

				continue;
			}

			cnts.push_back(cnt);
			factor = v[j];
			cnt = 1;
		}

		cnts.push_back(cnt);

		int result = 1;
		
		for (int j = 0; j < cnts.size(); j++)
		{
			result *= (cnts[j] + 1);
		}

		factorCnt[i] = result;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	eratosthenes();
	preCalculate();

	int num = 1;
	result[1] = num;
	int cnt = 1;

	for (int i = 2; i <= MAX; i++)
	{
		if (cnt <= factorCnt[i])
		{
			cnt = factorCnt[i];

			num = i;
		}

		result[i] = num;
	}

	for (int t = 1; t <= T;t++)
	{
		int N;
		cin >> N;

		cout << "#" << t << " " << result[N] << "\n";
	}

	return 0;
}