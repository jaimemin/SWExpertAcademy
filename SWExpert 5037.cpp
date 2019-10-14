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

// 마름모 만드는 대각선 순서
Dir moveDir[4] = { {1, -1}, {1, 1}, {-1, 1}, {-1, -1} }; // ↙ ↘ ↗ ↖

int N;
int result;
int graph[MAX][MAX];
pair<int, int> start; // 시작한 지점
bool visited[100 + 1]; // 디저트 종류 표시

void func(int y, int x, int dir, int cnt)
{
	// 마지막 방향까지 탐색했고
	if (dir == 4)
	{
		// 다시 시작점으로 돌아왔다면
		if (y == start.first && x == start.second)
		{
			// 갱신
			result = max(result, cnt);
		}

		return;
	}

	int nextY = y + moveDir[dir].y;
	int nextX = x + moveDir[dir].x;

	// 범위 벗어날 경우
	if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
	{
		return;
	}

	// 다음 지점이 시작점이고 마지막 방향일 경우
	if (dir == 3 && nextY == start.first && nextX == start.second)
	{
		func(nextY, nextX, 4, cnt + 1);

		return;
	}

	// 이미 먹었던 종류라면
	if (visited[graph[nextY][nextX]])
	{
		return;
	}

	visited[graph[nextY][nextX]] = true;
	// 같은 방향
	func(nextY, nextX, dir, cnt + 1);
	// 방향 틀어서
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

		// 마름모를 형성하지 못할 경우 -1이므로 -1로 초기화
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