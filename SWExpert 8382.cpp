#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 201;

typedef struct
{
	int x, y;
}Dir;

Dir moveDir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int x, y, x2, y2;
		cin >> x >> y >> x2 >> y2;

		bool visited[MAX][MAX][2] = { false, };
		queue<pair<pair<int, int>, pair<int,int>>> q;

		q.push({ {x, y}, {0, 0} });
		q.push({ {x, y}, {1, 0} });
		visited[x + 100][y + 100][0] = true;
		visited[x + 100][y + 100][1] = true;

		int result = -1;
		while (!q.empty())
		{
			int curX = q.front().first.first;
			int curY = q.front().first.second;
			int dir = q.front().second.first;
			int cnt = q.front().second.second;
			q.pop();

			if (curX == x2 && curY == y2)
			{
				result = cnt;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				if (i % 2 == dir)
				{
					continue;
				}

				int nextX = curX + moveDir[i].x;
				int nextY = curY + moveDir[i].y;
				int nextDir = 1 - dir;

				if (nextX < -100 || nextX > 100 || nextY < -100 || nextY > 100)
				{
					continue;
				}

				if (visited[nextX + 100][nextY + 100][nextDir])
				{
					continue;
				}

				visited[nextX + 100][nextY + 100][nextDir] = true;
				q.push({ {nextX, nextY}, {nextDir, cnt + 1} });
			}
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}