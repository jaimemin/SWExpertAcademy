#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 8;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[5] = { {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

typedef struct
{
	int y, x, c, p;
}BC;

int M, A;
vector<int> a, b;
vector<BC> BCs;
int result;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T;t++)
	{
		cin >> M >> A;

		a.resize(M);

		for (int i = 0; i < M; i++)
		{
			cin >> a[i];
		}

		b.resize(M);

		for (int i = 0; i < M; i++)
		{
			cin >> b[i];
		}

		BCs.clear();

		for (int i = 0; i < A;i++)
		{
			int y, x, c, p;
			cin >> x >> y >> c >> p;

			BCs.push_back({ y - 1, x - 1, c, p });
		}

		int y = 0, x = 0;
		int y2 = 9, x2 = 9;

		result = 0;

		for (int m = -1; m < M; m++)
		{
			bool Avisited[MAX] = { false, };
			bool Bvisited[MAX] = { false, };
			int total = 0;

			// 초기에도 배터리 설정 가능하므로 예외처리
			if (m != -1)
			{
				y += moveDir[a[m]].y;
				x += moveDir[a[m]].x;

				y2 += moveDir[b[m]].y;
				x2 += moveDir[b[m]].x;
			}

			for (int i = 0; i < BCs.size(); i++)
			{
				// A가 i 번째 배터리 범위 내에 있다면
				if (abs(y - BCs[i].y) + abs(x - BCs[i].x) <= BCs[i].c)
				{
					Avisited[i] = true;
				}
				
				// B가 i 번째 배터리 범위 내에 있다면
				if (abs(y2 - BCs[i].y) + abs(x2 - BCs[i].x) <= BCs[i].c)
				{
					Bvisited[i] = true;
				}
			}

			// 각 초마다 모든 경우의 수 확인
			// 즉, 모든 배터리를 사용하는 것에 대해 확인
			for (int i = 0; i < BCs.size(); i++)
			{
				for (int j = 0; j < BCs.size(); j++)
				{
					// 동일한 배터리 사용할 경우 효율은 1
					if (i == j && Avisited[i] && Bvisited[j])
					{
						total = max(total, BCs[i].p);
						
						continue;
					}

					int aPower = Avisited[i] ? BCs[i].p : 0;
					int bPower = Bvisited[j] ? BCs[j].p : 0;

					total = max(total, aPower + bPower);
				}
			}

			result += total;
		}
		
		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}