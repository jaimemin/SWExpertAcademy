#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100 + 2;

typedef struct
{
	int y, x;
}Dir;

// SOUTH, EAST, NORTH, WEST
Dir moveDir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

enum dir
{
	SOUTH = 0, EAST, NORTH, WEST,
};

int N;
int result;
int arr[MAX][MAX];
pair<int, int> start;
map<pair<int, int>, pair<int, int>> wormHole;
bool flag;

// SOUTH, EAST, NORTH, WEST
int nextDir[5+1][4]={
	{0, 0, 0, 0},
	{EAST, WEST, SOUTH, NORTH},
	{NORTH, WEST, EAST, SOUTH},
	{NORTH, SOUTH, WEST, EAST},
	{WEST, NORTH, SOUTH, EAST},
	{NORTH, WEST, SOUTH, EAST}
};

typedef struct
{
	int y, x, d, cnt;
}Pinball;

void func(int y, int x, int d)
{
	queue<Pinball> q;
	q.push({ y, x, d, 0 });
	// 시작하자마자 끝나는 것을 방지
	flag = false;

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		int curD = q.front().d;
		int cnt = q.front().cnt;
		q.pop();


		// 시작점에 돌아왔을 경우
		if (flag && curY == y && curX == x)
		{
			result = max(result, cnt);

			continue;
		}

		// 블랙홀
		if (arr[curY][curX] == -1)
		{
			result = max(result, cnt);

			continue;
		}

		flag = true;

		// 웜홀
		if (arr[curY][curX] >= 6)
		{
			int nextY = wormHole[{curY, curX}].first + moveDir[curD].y;
			int nextX = wormHole[{curY, curX}].second + moveDir[curD].x;

			q.push({ nextY, nextX, curD, cnt });

			continue;
		}

		// 블록
		if (arr[curY][curX] >= 1 && arr[curY][curX] <= 5)
		{
			int nextD = nextDir[arr[curY][curX]][curD];
			int nextY = curY + moveDir[nextD].y;
			int nextX = curX + moveDir[nextD].x;

			q.push({ nextY, nextX, nextD, cnt + 1 });

			continue;
		}

		int nextY = curY + moveDir[curD].y;
		int nextX = curX + moveDir[curD].x;

		q.push({ nextY, nextX, curD, cnt });
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
		wormHole.clear();

		cin >> N;

		vector<pair<int, int>> v[11];
		vector<pair<int, int>> starts;

		for (int i = 0; i < N + 2; i++)
		{
			for (int j = 0; j < N + 2; j++)
			{
				// 벽을 정사각형 블록으로 채움
				if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
				{
					arr[i][j] = 5;

					continue;
				}

				cin >> arr[i][j];

				if (arr[i][j] >= 6)
				{
					v[arr[i][j]].push_back({ i, j });
				}

				if (arr[i][j] == 0)
				{
					starts.push_back({ i, j });
				}
			}
		}

		for (int i = 6; i <= 10; i++)
		{
			if (v[i].empty())
			{
				continue;
			}

			wormHole[v[i][0]] = v[i][1];
			wormHole[v[i][1]] = v[i][0];
		}

		result = 0;

		for (int i = 0; i < starts.size(); i++)
		{
			for (int k = 0; k < 4; k++)
			{
				start = starts[i];
				flag = false;

				func(starts[i].first, starts[i].second, k);
			}
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}