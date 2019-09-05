#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N;
int graph[MAX][MAX];
bool visited[MAX][MAX];

void func(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;

		if (graph[nextY][nextX] == 0)
		{
			continue;
		}

		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
		{
			continue;
		}

		if (visited[nextY][nextX])
		{
			continue;
		}

		visited[nextY][nextX] = true;

		func(nextY, nextX);
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
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> graph[i][j];
			}
		}

		pair<int, int> result = { 0, 1 };

		for (int day = 1; day <= MAX; day++)
		{
			memset(visited, 0, sizeof(visited));
			
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (graph[i][j] <= day)
					{
						graph[i][j] = 0;
					}
				}
			}

			int cnt = 0;

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (graph[i][j] && visited[i][j] == false)
					{
						visited[i][j] = true;

						func(i, j);
						cnt++;
					}
				}
			}

			if (result.second < cnt)
			{
				result.first = day;
				result.second = cnt;
			}
		}

		cout << "#" << t << " " << result.second << "\n";
	}

	return 0;
}