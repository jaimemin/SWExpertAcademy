#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 50;
const int INF = 987654321;

int N, M;
int result;
string graph[MAX];

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
			cin >> graph[i];

		result = INF;
		for (int i = 1; i <= N - 2; i++)
		{
			int whiteTemp = 0;
			for (int w = 0; w < i; w++)
				for (int a = 0; a < graph[w].size(); a++)
					if (graph[w][a] != 'W')
						whiteTemp++;

			for (int j = 1; j <= N - i - 1; j++)
			{
				int blueTemp = 0;
				for (int b = i; b < i + j; b++)
					for (int a = 0; a < graph[b].size(); a++)
						if (graph[b][a] != 'B')
							blueTemp++;

				for (int k = 1; k <= N - i - j; k++)
				{
					int redTemp = 0;
					for (int r = i + j; r < i + j + k; r++)
						for (int a = 0; a < graph[r].size(); a++)
							if (graph[r][a] != 'R')
								redTemp++;
					
					if(i + j + k == N)
						result = min(result, whiteTemp + blueTemp + redTemp);
				}
			}
		}

		cout << "#" << t << " " << result << "\n";
	}
	return 0;
}

