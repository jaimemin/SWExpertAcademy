#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100 + 1;

int result;
vector<int> graph[MAX];
bool visited[MAX];

void func(int num)
{
	for (int i = 0; i < graph[num].size(); i++)
	{
		int next = graph[num][i];

		if (visited[next])
		{
			continue;
		}

		visited[next] = true;
		func(next);
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
		for (int i = 0; i < MAX; i++)
		{
			graph[i].clear();
		}

		int N, M;
		cin >> N >> M;

		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		result = 0;
		memset(visited, false, sizeof(visited));

		for (int i = 1; i <= N; i++)
		{
			if (visited[i])
			{
				continue;
			}

			visited[i] = true;
			result++;
			func(i);
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}