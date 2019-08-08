#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

int N, M;
int result;
int arr[MAX][MAX];

void func(int y, int x)
{
	bool visited[MAX][MAX] = { false, };

	vector<pair<int, int>> v;
	v.push_back({ y, x });

	int houseDeposit = 0;
	int house = 0;
	if (arr[y][x] == 1)
	{
		houseDeposit += M;
		house++;
	}
	visited[y][x] = true;

	int idx = 0;
	for (int len = 1; len <= N + 1; len++)
	{
		int cost = (len * len) + (len - 1) * (len - 1);

		if (houseDeposit - cost >= 0)
		{
			result = max(result, house);
		}

		int size = v.size();
		// 기존에 가장자리인 부분에서 이어나가지는 방식
		for (; idx < size; idx++)
		{
			for (int k = 0; k < 4; k++)
			{
				int nextY = v[idx].first + moveDir[k].y;
				int nextX = v[idx].second + moveDir[k].x;

				if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N || visited[nextY][nextX])
				{
					continue;
				}

				v.push_back({ nextY, nextX });
				visited[nextY][nextX] = true;
				if (arr[nextY][nextX] == 1)
				{
					houseDeposit += M;
					house++;
				}
			}
		}

		idx = size;
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
		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		result = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				func(i, j);
			}
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}