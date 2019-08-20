#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A, B;
vector<int> mail;
vector<int> result;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1;t <= T; t++)
	{
		cin >> N >> A >> B;

		mail.clear();
		result.clear();
		for (int i = 0; i < N; i++)
		{
			int time;
			cin >> time;

			mail.push_back(time);
		}

		sort(mail.begin(), mail.end());

		int idx = 0;
		int time = mail[idx];
		pair<int, int> oldest = { 0, mail[0] };
		
		for (; result.size() != N; time++)
		{
			if (idx < N - 1 && mail[idx + 1] == time)
			{
				idx++;
			}

			int timeDiff = time - oldest.second;
			int leftMail = idx - oldest.first + 1;
			int half = leftMail % 2 ? leftMail / 2 + 1 : leftMail / 2;

			if (timeDiff == B || leftMail >= A)
			{
				for (int j = oldest.first; j < oldest.first + half; j++)
				{
					result.push_back(time);
				}

				if (oldest.first + half < N)
				{
					oldest = { oldest.first + half, mail[oldest.first + half] };
				}
			}
		}

		cout << "#" << t << " ";
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}