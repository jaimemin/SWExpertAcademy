#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20;

int arr[MAX][MAX];

int N, X;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> X;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		int result = 0;

		// 세로
		for (int i = 0; i < N; i++)
		{
			// 활주로 길이
			int road = 1;
			// 동일한 높이 길이
			int cnt = 1;
			// 활주로 지을 수 있는지 판단 여부
			bool flag = true;

			for (int j = 1; j < N; j++)
			{
				int diff = arr[j][i] - arr[j - 1][i];

				// 불가능한 경우
				if (abs(diff) > 1)
				{
					flag = false;

					break;
				}

				switch (diff)
				{
				// 아래쪽에 있는 지형이 더 낮을 경우
				case -1:
					cnt = 1;

					// j를 기준으로 활주로 지을 수 있는지 확인해야함
					for (int k = j + 1; k < N; k++)
					{
						// 동일한 높이 아니라면
						if (arr[k][i] != arr[k - 1][i])
						{
							break;
						}

						// 동일한 높이이고 활주로 만들 조건 성립 시
						if (++cnt >= X)
						{
							break;
						}
					}

					// 활주로 만들었을 경우
					if (cnt >= X)
					{
						cnt = 0;
						j += X - 1;
						road += X;
					}
					else
					{
						flag = false;
					}

					break;
				// 동일한 경우
				case 0:
					road++;
					cnt++;

					break;
				// 아래쪽에 있는 지형이 더 높은 경우
				case 1:
					// 여태까지 활주로를 만들 수 있는 조건이 충분했는지 확인
					if (cnt >= X)
					{
						cnt = 1;
						road++;
					}
					else
					{
						flag = false;
					}

					break;
				}

				if (!flag)
				{
					break;
				}
			}

			if (flag && (road == N))
			{
				result++;
			}
		}

		// 가로
		for (int i = 0; i < N; i++)
		{
			int road = 1;
			int cnt = 1;
			bool flag = true;

			for (int j = 1; j < N; j++)
			{
				int diff = arr[i][j] - arr[i][j - 1];

				if (abs(diff) > 1)
				{
					flag = false;

					break;
				}

				switch (diff)
				{
				case -1:
					cnt = 1;

					for (int k = j + 1; k < N; k++)
					{
						if (arr[i][k] != arr[i][k - 1])
						{
							break;
						}

						if (++cnt >= X)
						{
							break;
						}
					}

					if (cnt >= X)
					{
						cnt = 0;
						j += X - 1;
						road += X;
					}
					else
					{
						flag = false;
					}

					break;
				case 0:
					cnt++;
					road++;

					break;
				case 1:
					if (cnt >= X)
					{
						cnt = 1;
						road++;
					}
					else
					{
						flag = false;
					}

					break;
				}

				if (!flag)
				{
					break;
				}
			}

			if (flag && road == N)
			{
				result++;
			}
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}