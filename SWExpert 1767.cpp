#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 12;
const int INF = 987654321;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N;
int connected, result;
int arr[MAX][MAX];
vector<pair<int, int>> core;
bool visited[MAX][MAX];

void func(int idx, int coreCnt, int wireLen)
{
	if (idx == core.size())
	{
		if (connected < coreCnt)
		{
			connected = coreCnt;
			result = wireLen;
		}
		else if (connected == coreCnt)
		{
			result = min(result, wireLen);
		}

		return;
	}

	if (core[idx].first == 0 || core[idx].first == N - 1 || core[idx].second == 0 || core[idx].second == N - 1)
	{
		func(idx + 1, coreCnt + 1, wireLen);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int y = core[idx].first;
		int x = core[idx].second;
		int len = 0;
		bool flag = true;

		while (1)
		{
			y += moveDir[i].y;
			x += moveDir[i].x;

			if (y < 0 || y >= N || x < 0 || x >= N)
			{
				break;
			}

			if (visited[y][x])
			{
				flag = false;
				break;
			}

			visited[y][x] = true;
			len++;
		}

		if (flag)
		{
			func(idx + 1, coreCnt + 1, wireLen + len);
		}

		while (1)
		{
			if (y - moveDir[i].y == core[idx].first && x - moveDir[i].x == core[idx].second)
			{
				break;
			}

			y -= moveDir[i].y;
			x -= moveDir[i].x;
			visited[y][x] = false;
		}
	}

	func(idx + 1, coreCnt, wireLen);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		core.clear();
		memset(visited, 0, sizeof(visited));
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];

				if (arr[i][j] == 1)
				{
					visited[i][j] = true;
					core.push_back({ i, j });
				}
			}
		}

		connected = 0;
		result = INF;
		func(0, 0, 0);

		cout << "#" << t << " " << result << "\n";
	}
	
	return 0;
}
