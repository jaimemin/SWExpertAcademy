#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 20;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int R, C;
int result;
string graph[MAX];
bool visited[26];

void func(int y, int x, int cnt)
{
	result = max(result, cnt);

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;

		if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
		{
			continue;
		}

		if (visited[graph[nextY][nextX] - 'A'])
		{
			continue;
		}

		visited[graph[nextY][nextX] - 'A'] = true;
		func(nextY, nextX, cnt + 1);
		visited[graph[nextY][nextX] - 'A'] = false;
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		memset(visited, false, sizeof(visited));

		cin >> R >> C;

		for (int i = 0; i < R; i++)
		{
			cin >> graph[i];
		}

		result = 1;
		visited[graph[0][0] - 'A'] = true;
		func(0, 0, 1);

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}