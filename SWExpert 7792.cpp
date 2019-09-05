#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 100;

bool visited[MAX][26];

bool cmp(pair<int, string> a, pair<int, string> b)
{
	if (a.first > b.first)
	{
		return true;
	}

	if (a.first == b.first)
	{
		if (a < b)
		{
			return true;
		}
	}

	return false;
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

		int N;
		cin >> N;

		string flushBuffer;
		getline(cin, flushBuffer);
		
		vector<pair<int, string>> v(N);
		for (int i = 0; i < N; i++)
		{
			v[i].first = 0;
			getline(cin, v[i].second);

			for (int j = 0; j < v[i].second.length(); j++)
			{
				if (v[i].second[j] == ' ')
				{
					continue;
				}

				if (!visited[i][v[i].second[j]])
				{
					visited[i][v[i].second[j]] = true;
					v[i].first++;
				}
			}
		}

		sort(v.begin(), v.end(), cmp);

		cout << "#" << t << " " << v[0].second << "\n";
	}

	return 0;
}