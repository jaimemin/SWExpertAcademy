#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 16;
const int INF = 987654321;

int N;
int result;
int arr[MAX][MAX];
vector<int> v;

void func(void)
{
	vector<int> a, b;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 1)
		{
			a.push_back(i);
		}
		else
		{
			b.push_back(i);
		}
	}

	int aResult = 0;
	
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i + 1; j < a.size(); j++)
		{
			aResult += arr[a[i]][a[j]];
			aResult += arr[a[j]][a[i]];
		}
	}

	int bResult = 0;

	for (int i = 0; i < b.size(); i++)
	{
		for (int j = i + 1; j < b.size(); j++)
		{
			bResult += arr[b[i]][b[j]];
			bResult += arr[b[j]][b[i]];
		}
	}

	result = min(result, abs(aResult - bResult));
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

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		result = INF;

		v.clear();
		
		v.resize(N, 1);

		for (int i = N / 2; i < N; i++)
		{
			v[i] = 2;
		}

		do
		{
			func();
		} while (next_permutation(v.begin(), v.end()));

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}

