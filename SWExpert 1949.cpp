#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

const int MAX = 8;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N, K;
int result;
int arr[MAX][MAX];
bool visited[MAX][MAX];

void func(int y, int x, int cnt)
{
	result = max(result, cnt);

	for (int k = 0; k < 4; k++)
	{
		int nextY = y + moveDir[k].y;
		int nextX = x + moveDir[k].x;

		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
		{
			continue;
		}

		if (visited[nextY][nextX])
		{
			continue;
		}

		if (arr[nextY][nextX] >= arr[y][x])
		{
			continue;
		}

		visited[nextY][nextX] = true;
		func(nextY, nextX, cnt + 1);
		visited[nextY][nextX] = false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> K;

		int high = -1;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];

				high = max(high, arr[i][j]);
			}
		}

		vector<pair<int, int>> starts;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == high)
				{
					starts.push_back({ i, j });
				}
			}
		}

		result = 0;

		for (int k = 0; k <= K; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					int temp = arr[i][j];
					arr[i][j] = max(0, arr[i][j] - k);
					
					for (int l = 0; l < starts.size(); l++)
					{
						if (k > 0 && i == starts[l].first && j == starts[l].second)
						{
							continue;
						}

						memset(visited, false, sizeof(visited));
						visited[starts[l].first][starts[l].second] = true;

						func(starts[l].first, starts[l].second, 1);
					}

					arr[i][j] = temp;
				}
			}
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}
