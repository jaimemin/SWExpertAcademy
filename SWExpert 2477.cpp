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
		queue<int> v; // ���� ��⿭
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> v2; // ���� ��⿭

		while (1)
		{
			// ������ Ȯ��
			while (1)
			{
				if (idx == customers.size())
				{
					break;
				}

				// �ð��� �´ٸ� ���� ��⿭�� �߰�
				if (customers[idx] == time)
				{
					v.push(idx++);
				}
				else
				{
					break;
				}
			}

			// ���� â�� ���� ������
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
					// �빫�� ���ƴٸ�
					else
					{
						// ���� ��⿭�� �̵�
						v2.push({ time, {i, j} });
					}
				}

				if (q[i].empty())
				{
					// �� ��⿭�� ���ٸ�
					if (v.empty())
					{
						continue;
					}

					int j = v.front();
					v.pop();

					// ��
					q[i].push({ receptions[i], j });
					// ����â ���
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