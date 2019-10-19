#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100;

typedef struct {
	int y, x, cnt, dir;
}Algae;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[5] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

vector<int> graph[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) 
	{
		int N, M, K;
		cin >> N >> M >> K;

		vector<Algae> v(K);

		for (int i = 0; i < K; i++)
		{
			cin >> v[i].y >> v[i].x >> v[i].cnt >> v[i].dir;

			graph[v[i].y][v[i].x].push_back(i);
		}

		for (int m = 0; m < M; m++)
		{
			for (int i = 0; i < K; i++)
			{
				if (v[i].cnt == 0)
				{
					continue;
				}

				graph[v[i].y][v[i].x].clear();
			}

			for (int i = 0; i < K; i++)
			{
				if (v[i].cnt == 0)
				{
					continue;
				}

				v[i].y += moveDir[v[i].dir].y;
				v[i].x += moveDir[v[i].dir].x;

				graph[v[i].y][v[i].x].push_back(i);
			}

			for (int i = 0; i < K; i++)
			{
				if (v[i].cnt == 0)
				{
					continue;
				}

				if (v[i].y == 0 || v[i].y == N - 1 || v[i].x == 0 || v[i].x == N - 1)
				{
					v[i].cnt /= 2;

					v[i].dir = v[i].dir <= 2 ? 3 - v[i].dir : 7 - v[i].dir;
				}
				else if (graph[v[i].y][v[i].x].size() > 1)
				{
					int y = v[i].y;
					int x = v[i].x;

					int maxNum = 0;
					int maxDir = 0;
					int total = 0;
					int mergedIdx = 0;

					for (int i = 0; i < graph[y][x].size(); i++)
					{
						total += v[graph[y][x][i]].cnt;

						if (maxNum < v[graph[y][x][i]].cnt)
						{
							maxNum = v[graph[y][x][i]].cnt;
							maxDir = v[graph[y][x][i]].dir;
							mergedIdx = graph[y][x][i];
						}

						v[graph[y][x][i]].cnt = 0;
					}

					v[mergedIdx].cnt = total;
					v[mergedIdx].dir = maxDir;
				}
			}
		}

		int result = 0;

		for (int i = 0; i < K; i++)
		{
			result += v[i].cnt;
		}

		cout << "#" << t << " " << result << "\n";

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				graph[i][j].clear();
			}
		}
	}
	return 0;
}