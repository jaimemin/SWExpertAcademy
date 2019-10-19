#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 10;

int N, M, C;
int arr[MAX][MAX];
int cache[MAX][MAX];

int func2(vector<int> &v, int idx, int sum, int total)
{
	if (sum > C)
	{
		return 0;
	}

	if (idx == v.size())
	{
		return total;
	}

	return max(func2(v, idx + 1, sum + v[idx], total + v[idx] * v[idx]), func2(v, idx + 1, sum, total));
}

int func(int y, int x)
{
	vector<int> v;

	for (int i = 0; i < M; i++)
	{
		v.push_back(arr[y][x + i]);
	}

	return func2(v, 0, 0, 0);
}

int DFS(int y, int x)
{
	int answer = 0;

	for (int i = x + M; i < N - M + 1; i++)
	{
		answer = max(answer, cache[y][i]);
	}

	for (int i = y + 1;i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			answer = max(answer, cache[i][j]);
		}
	}

	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M >> C;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];

				cache[i][j] = 0;
			}
		}
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - M + 1; j++)
			{
				cache[i][j] = func(i, j);
			}
		}

		int result = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				result = max(result, DFS(i, j) + cache[i][j]);
			}
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}