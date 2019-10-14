#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 최대 300초동안 한 방향으로 자라는 것을 고려하여
const int MAX = 300 * 2 + 50;
// 생명력 X는 1 이상 10 이하
const int MAX_TIME = 10 + 1;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

// {비활성 시간 + 활성 시간, 비활성 시간}
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

		// 초기화
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
					// 위치를 한 가운데로 지정
					int y = MAX / 2 + i;
					int x = MAX / 2 + j;

					// 비활성 상태 시간 = 활성 상태 시간
					// {비활성 상태 + 활성 상태, 비활성 상태}
					cell[y][x] = { time * 2 , time };

					q[time].push({ y, x });
				}
			}
		}

		for (int k = 0; k < K; k++)
		{
			// 동시에 번식할 경우 우선순위가 생명력이 강한 세포 순
			// 따라서 10부터 역순
			for (int i = 10; i >= 1; i--)
			{
				int qSize = q[i].size();

				for (int j = 0; j < qSize; j++)
				{
					int y = q[i].front().first;
					int x = q[i].front().second;
					q[i].pop();

					// 비활성 상태 -> 활성 상태
					if (cell[y][x].first == cell[y][x].second)
					{
						for (int l = 0; l < 4; l++)
						{
							int nextY = y + moveDir[l].y;
							int nextX = x + moveDir[l].x;

							// 이미 우선순위가 높은 세포가 증식을 한 경우
							if (cell[nextY][nextX].second)
							{
								continue;
							}

							// 똑같이 {비활성 상태 + 활성 상태, 비활성 상태}
							cell[nextY][nextX].first = cell[y][x].second * 2;
							cell[nextY][nextX].second = cell[y][x].second;

							q[i].push({ nextY,nextX });
						}
					}

					// 시간이 지났으므로 
					cell[y][x].first--;

					// 죽지 않았다면 큐에 다시 넣어준다
					if (cell[y][x].first)
					{
						q[i].push({ y, x });
					}
				}
			}
		}

		int result = 0;
		
		// 죽지 않은 세포의 수
		for (int i = 1; i <= 10; i++)
		{
			result += q[i].size();
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}