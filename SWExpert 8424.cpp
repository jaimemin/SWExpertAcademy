#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1000 + 1;

int result;
vector<int> graph[MAX];
bool visited[MAX][MAX];

void func(int start, int node, int cnt)
{
	if (start == node)
	{
		result = max(result, cnt);

		return;
	}

	for (int i = 0; i < graph[node].size(); i++)
	{
		int next = graph[node][i];

		if (visited[node][next])
		{
			continue;
		}

		visited[node][next] = true;
		visited[next][node] = true;
		func(start, next, cnt + 1);
		visited[next][node] = false;
		visited[node][next] = false;
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
		memset(visited, false, sizeof(visited));

		for (int i = 1; i < MAX; i++)
		{
			graph[i].clear();
		}

		int N;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		result = 1;

		for (int i = 1; i < MAX; i++)
		{
			if (graph[i].size() > 0)
			{
				for (int j = 0; j < graph[i].size(); j++)
				{
					int next = graph[i][j];

					if (visited[i][next])
					{
						continue;
					}

					visited[i][next] = true;
					visited[next][i] = true;

					func(i, next, 1);
				}
			}
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}