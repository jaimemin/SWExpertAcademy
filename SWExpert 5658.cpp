#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T;t++)
	{
		int N, K;
		cin >> N >> K;

		string s;
		cin >> s;

		deque<char> dq;
		for (int i = 0; i < s.length(); i++)
		{
			dq.push_back(s[i]);
		}

		vector<long long> v;
		map<long long, bool> visited;

		int len = N / 4;

		for (int i = 0; i < len; i++)
		{
			int idx = 0;

			for (int j = 0; j < 4; j++)
			{
				string temp;

				for (int k = 0; k < len; k++)
				{
					temp += dq[idx++];
				}

				long long num = 0;
				
				for (int k = 0; k < temp.length(); k++)
				{
					int digit;

					switch (temp[temp.length() - k - 1])
					{
					case 'A':
						digit = 10;
						break;
					case 'B':
						digit = 11;
						break;
					case 'C':
						digit = 12;
						break;
					case 'D':
						digit = 13;
						break;
					case 'E':
						digit = 14;
						break;
					case 'F':
						digit = 15;
						break;
					default:
						digit = temp[temp.length() - 1 - k] - '0';
						break;
					}

					num += digit * pow(16, k);
				}

				if (!visited.count(num))
				{
					visited[num] = true;

					v.push_back(num);
				}
			}

			char c = dq.back();
			dq.pop_back();
			dq.push_front(c);
		}

		sort(v.begin(), v.end(), greater<long long>());

		cout << "#" << t << " " << v[K - 1] << "\n";
	}

	return 0;
}