#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 12;
const int INF = 1e9;

int N;
int arr[MAX];
vector<int> v;
pair<int, int> result;

void func(void)
{
	int temp = arr[0];

	for (int i = 0; i < N - 1; i++)
	{
		switch (v[i])
		{
		case 0:
			temp += arr[i + 1];

			break;
		case 1:
			temp -= arr[i + 1];

			break;
		case 2:
			temp *= arr[i + 1];

			break;
		case 3:
			temp /= arr[i + 1];

			break;
		}
	}

	result.first = min(result.first, temp);
	result.second = max(result.second, temp);
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

		v.clear();

		for (int i = 0; i < 4; i++)
		{
			int num;
			cin >> num;

			for (int j = 0; j < num; j++)
			{
				v.push_back(i);
			}
		}

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}

		sort(v.begin(), v.end());

		result = { INF, -1 * INF };

		do
		{
			func();
		} while (next_permutation(v.begin(), v.end()));

		cout << "#" << t << " " << (result.second - result.first) << "\n";
	}

	return 0;
}