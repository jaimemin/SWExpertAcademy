#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int D, W, K;

int result;
int arr[13][20];
int colored[13];

bool checkValid(void)
{
	for (int i = 0; i < W; i++)
	{
		int cnt = 1;

		for (int j = 0; j < D - 1; j++)
		{
			// 약을 투여하지 않았으면 -1
			// 약을 투여했으면 0 혹은 1
			int cur = (colored[j] == -1) ? arr[j][i] : colored[j];
			int next = (colored[j + 1] == -1) ? arr[j + 1][i] : colored[j + 1];
			
			// 비교해서 같을 때마다
			if (cur == next)
			{
				// 연속해서 일치하는 구간 표시
				if (++cnt >= K)
				{
					break;
				}

				continue;
			}
			
			cnt = 1;
		}

		// 하나라도 성립하지 않으면 실패
		if (cnt < K)
		{
			return false;
		}
	}

	return true;
}

void func(int idx, int cnt)
{
	if (cnt > result)
	{
		return;
	}

	if (checkValid())
	{
		result = min(result, cnt);

		return;
	}

	if (idx >= D)
	{
		return;
	}

	// 약을 투여하고 원상복귀
	colored[idx] = 0;
	func(idx + 1, cnt + 1);
	colored[idx] = -1;

	// 약을 투여하고 원상복귀
	colored[idx] = 1;
	func(idx + 1, cnt + 1);
	colored[idx] = -1;

	// 약 투여 X
	func(idx + 1, cnt);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> D >> W >> K;

		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> arr[i][j];
			}
		}

		memset(colored, -1, sizeof(colored));

		result = K;

		func(0, 0);

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}