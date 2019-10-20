#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 20;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 1, -1 },{ 1, 1 },{ -1, 1 },{ -1, -1 } };

int N;
int result;
int graph[MAX][MAX];
pair<int, int> start;
bool visited[100 + 1];

void func(int y, int x, int dir, int cnt)
{
	if (dir == 4)
	{
		if (y == start.first && x == start.second)
		{
			result = max(result, cnt);
		}

		return;
	}

	int nextY = y + moveDir[dir].y;
	int nextX = x + moveDir[dir].x;

	if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
	{
		return;
	}

	if (dir == 3 && nextY == start.first && nextX == start.second)
	{
		func(nextY, nextX, 4, cnt + 1);

		return;
	}

	if (visited[graph[nextY][nextX]])
	{
		return;
	}

	visited[graph[nextY][nextX]] = true;
	func(nextY, nextX, dir, cnt + 1);
	func(nextY, nextX, dir + 1, cnt + 1);
	visited[graph[nextY][nextX]] = false;
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

		result = -1;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				memset(visited, false, sizeof(visited));

				visited[graph[i][j]] = true;
				start = { i, j };
				func(i, j, 0, 0);
				visited[graph[i][j]] = false;
			}
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}