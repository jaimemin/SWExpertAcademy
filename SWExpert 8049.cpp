#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		string s;
		cin >> s;

		int type = 0;
		bool flag = true;
		for (int i = 0; i < s.length(); i++)
		{
			switch (type)
			{
			case 0:
				if (s[i] == 'F' && i < s.length() - 1)
				{
					switch (s[i + 1])
					{
					case 'C':
						type = 2;
						break;
					case 'F':
						type = 1;
						break;
					case 'M':
						flag = false;
						break;
					}
				}
				break;
			case 1:
				while (s[i] == 'F' && i < s.length())
				{
					i++;
				}

				if (i + 2 < s.length() && s[i] == 'M' && s[i + 1] == 'C' && s[i + 2] == 'M')
				{
					i += 2;

					while (s[i] == 'M' && i < s.length())
					{
						i++;
					}

					i--;
					type = 0;
				}
				else
				{
					flag = false;
				}
				break;
			case 2:
				while (s[i] == 'C' && i < s.length())
				{
					i++;
				}

				if (i + 1 < s.length() && s[i] == 'M' && s[i + 1] == 'F')
				{
					i++;
					type = 0;
				}
				else
				{
					flag = false;
				}
				break;
			}

			if (flag == false)
			{
				break;
			}
		}

		cout << "#" << t << " ";
		if (flag)
		{
			cout << "DETECTED!\n";
		}
		else
		{
			cout << "NOTHING!\n";
		}
	}

	return 0;
}