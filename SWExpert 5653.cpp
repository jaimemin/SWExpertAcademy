#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// �ִ� 300�ʵ��� �� �������� �ڶ�� ���� ����Ͽ�
const int MAX = 300 * 2 + 50;
// ����� X�� 1 �̻� 10 ����
const int MAX_TIME = 10 + 1;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

// {��Ȱ�� �ð� + Ȱ�� �ð�, ��Ȱ�� �ð�}
pair<int, int> cell[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N, M, K;
		cin >> N >> M >> K;

		// �ʱ�ȭ
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				cell[i][j] = { 0, 0 };
			}
		}

		queue<pair<int, int>> q[MAX_TIME];

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int time;
				cin >> time;

				if (time)
				{
					// ��ġ�� �� ����� ����
					int y = MAX / 2 + i;
					int x = MAX / 2 + j;

					// ��Ȱ�� ���� �ð� = Ȱ�� ���� �ð�
					// {��Ȱ�� ���� + Ȱ�� ����, ��Ȱ�� ����}
					cell[y][x] = { time * 2 , time };

					q[time].push({ y, x });
				}
			}
		}

		for (int k = 0; k < K; k++)
		{
			// ���ÿ� ������ ��� �켱������ ������� ���� ���� ��
			// ���� 10���� ����
			for (int i = 10; i >= 1; i--)
			{
				int qSize = q[i].size();

				for (int j = 0; j < qSize; j++)
				{
					int y = q[i].front().first;
					int x = q[i].front().second;
					q[i].pop();

					// ��Ȱ�� ���� -> Ȱ�� ����
					if (cell[y][x].first == cell[y][x].second)
					{
						for (int l = 0; l < 4; l++)
						{
							int nextY = y + moveDir[l].y;
							int nextX = x + moveDir[l].x;

							// �̹� �켱������ ���� ������ ������ �� ���
							if (cell[nextY][nextX].second)
							{
								continue;
							}

							// �Ȱ��� {��Ȱ�� ���� + Ȱ�� ����, ��Ȱ�� ����}
							cell[nextY][nextX].first = cell[y][x].second * 2;
							cell[nextY][nextX].second = cell[y][x].second;

							q[i].push({ nextY,nextX });
						}
					}

					// �ð��� �������Ƿ� 
					cell[y][x].first--;

					// ���� �ʾҴٸ� ť�� �ٽ� �־��ش�
					if (cell[y][x].first)
					{
						q[i].push({ y, x });
					}
				}
			}
		}

		int result = 0;
		
		// ���� ���� ������ ��
		for (int i = 1; i <= 10; i++)
		{
			result += q[i].size();
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}