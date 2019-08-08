#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 10;
const int INF = 987654321;

int N;
int result;
int arr[MAX][MAX];
int cache[MAX];
vector<pair<int, int>> person;
vector<pair<pair<int, int>, int>> stair;

int dist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int idx)
{
	if (idx == person.size())
	{
		int time = 0;
		vector<int> descending;
		queue<int> q[2];

		for (int i = 0; i < person.size(); i++)
		{
			descending.push_back(dist(person[i], stair[cache[i]].first) + 1);
		}

		int size = person.size();
		int exit = person.size();
		while (exit)
		{
			time++;

			for (int i = 0; i < size; i++)
			{
				if (descending[i] == -1)
				{
					continue;
				}
				else if (descending[i] == 1)
				{
					if (q[cache[i]].size() < 3)
					{
						q[cache[i]].push(stair[cache[i]].second);
						descending[i] = -1;
					}
				}
				else
				{
					descending[i]--;
				}
			}

			for (int i = 0; i < 2; i++)
			{
				int qSize = q[i].size();
				while (qSize--)
				{
					int temp = q[i].front();
					q[i].pop();

					if (--temp == 0)
					{
						exit--;
					}
					else
					{
						q[i].push(temp);
					}
				}
			}
		}

		result = min(result, time);
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		cache[idx] = i;
		dfs(idx + 1);
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
		person.clear();
		stair.clear();
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];

				if (arr[i][j] == 1)
				{
					person.push_back({ i, j });
				}
				else if (arr[i][j] >= 2)
				{
					stair.push_back({{ i, j }, arr[i][j] });
				}
			}
		}

		result = INF;
		dfs(0);
		
		cout << "#" << t << " " << result + 1 << "\n";
	}

	return 0;
}