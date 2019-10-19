#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

const int MAX = 10;

int N, M, K, A, B;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M >> K >> A >> B;

		vector<pair<int, int>> visited(K, { -1, -1 });

		vector<int> receptions(N + 1);
		for (int i = 1; i <= N; i++)
		{
			cin >> receptions[i];
		}

		vector<int> fixes(M + 1);
		for (int i = 1; i <= M; i++)
		{
			cin >> fixes[i];
		}

		vector<int> customers(K);
		for (int i = 0; i < K; i++)
		{
			cin >> customers[i];
		}

		queue<pair<int, int>> q[MAX], q2[MAX];

		int time = 0;
		int idx = 0;
		queue<int> v; // 접수 대기열
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> v2; // 정비 대기열

		while (1)
		{
			// 접수자 확인
			while (1)
			{
				if (idx == customers.size())
				{
					break;
				}

				// 시간이 맞다면 접수 대기열에 추가
				if (customers[idx] == time)
				{
					v.push(idx++);
				}
				else
				{
					break;
				}
			}

			// 접수 창구 작은 순으로
			for (int i = 1; i <= N; i++)
			{
				if (!q[i].empty())
				{
					int t = q[i].front().first;
					int j = q[i].front().second;
					q[i].pop();

					if (--t > 0)
					{
						q[i].push({ t, j });
					}
					// 용무를 마쳤다면
					else
					{
						// 정비 대기열로 이동
						v2.push({ time, {i, j} });
					}
				}

				if (q[i].empty())
				{
					// 고객 대기열이 없다면
					if (v.empty())
					{
						continue;
					}

					int j = v.front();
					v.pop();

					// 고객
					q[i].push({ receptions[i], j });
					// 접수창 등록
					visited[j].first = i;
				}
			}

			for (int i = 1; i <= M; i++)
			{
				if (!q2[i].empty())
				{
					int t = q2[i].front().first;
					int j = q2[i].front().second;
					q2[i].pop();

					if (--t > 0)
					{
						q2[i].push({ t, j });
					}
				}

				if (q2[i].empty())
				{
					if (v2.empty())
					{
						continue;
					}

					int j = v2.top().second.second;
					v2.pop();

					q2[i].push({ fixes[i], j });

					visited[j].second = i;
				}
			}

			bool flag = true;

			for (int i = 0; i < K; i++)
			{
				if (visited[i].first == -1 || visited[i].second == -1)
				{
					flag = false;

					break;
				}
			}

			if (flag)
			{
				break;
			}

			time++;
		}
		
		int result = 0;

		for (int i = 0; i < K; i++)
		{
			if (visited[i].first == A && visited[i].second == B)
			{
				result += (i + 1);
			}
		}

		if (result == 0)
		{
			result = -1;
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}