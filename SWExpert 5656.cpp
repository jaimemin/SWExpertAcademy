#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N, W, H;
int arr[16][12];

int result;

void copyMap(int(*a)[12], int(*b)[12]) 
{
	for (int i = 1; i <= H; i++) 
	{
		for (int j = 0; j < W; j++) 
		{
			b[i][j] = a[i][j];
		}
	}
}

void down() {
	for (int i = 0; i < W; i++) 
	{
		queue<int> q;

		for (int y = H; y > 0; y--) 
		{
			if (arr[y][i] > 0) 
			{
				q.push(arr[y][i]);
			}
		}

		for (int y = 1; y <= H; y++)
		{
			arr[y][i] = 0;
		}

		int h = H;
		
		while (!q.empty()) 
		{
			int range = q.front();
			q.pop();

			arr[h--][i] = range;
		}
	}
}

void drop(int y, int x, int range)
{
	if (range == 0) 
	{
		if (y + 1 > H)
		{
			return;
		}

		drop(y + 1, x, arr[y + 1][x]);

		return;
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ { y, x }, range });
	arr[y][x] = 0;

	while (!q.empty()) 
	{
		int curY = q.front().first.first;
		int curX = q.front().first.second;
		int curRange = q.front().second;
		q.pop();

		arr[curY][curX] = 0;

		for (int i = 1; i < curRange; i++) 
		{
			for (int j = 0; j < 4; j++) 
			{
				int nextY = curY + i * moveDir[j].y;
				int nextX = curX + i * moveDir[j].x;

				if (nextY < 1 || nextY >= H + 1 || nextX < 0 || nextX >= W)
				{
					continue;
				}

				if (arr[nextY][nextX] > 0) 
				{
					q.push({ { nextY,nextX }, arr[nextY][nextX] });
					
					arr[nextY][nextX] = 0;
				}
			}
		}
	}

	down();
}

void func(int cnt) 
{
	if (cnt == N) 
	{
		int sum = 0;
		for (int i = 1; i <= H; i++) 
		{
			for (int j = 0; j < W; j++) 
			{
				if (arr[i][j] > 0)
				{
					sum++;
				}
			}
		}
		
		result = min(result, sum);

		return;
	}

	int copyArr[16][12];

	for (int i = 0; i < W; i++) 
	{
		copyMap(arr, copyArr);

		drop(0, i, 0);
		func(cnt + 1);

		copyMap(copyArr, arr);
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie();
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) 
	{
		memset(arr, 0, sizeof(arr));

		cin >> N >> W >> H;

		for (int i = 1; i <= H; i++) 
		{
			for (int j = 0; j < W; j++) 
			{
				cin >> arr[i][j];
			}
		}

		result = INF;
		func(0);

		cout << "#" << t << " " << result << endl;
	}
	return 0;
}