#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 50;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int N, M, R, C, L;
int arr[MAX][MAX][4];
int result;
bool visited[MAX][MAX];
bool canHide[MAX][MAX];

int canMove[8][4] = {
	{0, 0, 0, 0},
	{1, 1, 1, 1},
	{1, 0, 1, 0},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{1, 1, 0, 0},
	{1, 0, 0, 1},
	{0, 0, 1, 1}
};

void func(int y, int x, int time)
{
	canHide[y][x] = true;

	if (time == L)
	{
		return;
	}

	for (int k = 0; k < 4; k++)
	{
		int nextY = y + moveDir[k].y;
		int nextX = x + moveDir[k].x;
		int nextK = (k + 2) % 4;

		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
		{
			continue;
		}

		if (visited[nextY][nextX])
		{
			continue;
		}

		if (arr[y][x][k] && arr[nextY][nextX][nextK])
		{
			visited[y][x] = true;
			func(nextY, nextX, time + 1);
			visited[y][x] = false;
		}
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
		cin >> N >> M >> R >> C >> L;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int temp;
				cin >> temp;

				for (int k = 0; k < 4; k++)
				{
					arr[i][j][k] = canMove[temp][k];
				}
			}
		}

		memset(visited, false, sizeof(visited));
		memset(canHide, false, sizeof(canHide));
		
		result = 0;

		func(R, C, 1);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (canHide[i][j])
				{
					result++;
				}
			}
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}