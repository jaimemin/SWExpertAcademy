#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

map<string, set<string>> m;
map<string, int> name2color;

bool func(string root, int color)
{
	name2color[root] = color;

	for (auto i : m[root])
	{
		if (name2color[i] == false)
		{
			if (color == 1)
			{
				if (func(i, 2) == false)
				{
					return false;
				}
			}
			else
			{
				if (func(i, 1) == false)
				{
					return false;
				}
			}
		}
		else
		{
			if (name2color[i] == color)
			{
				return false;
			}
		}
	}
	
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		m.clear();

		int K;
		cin >> K;

		string root;
		for (int i = 0; i < K; i++)
		{
			string name, name2;
			cin >> name >> name2;

			if (m.empty())
			{
				root = name;
			}

			m[name].insert(name2);
			m[name2].insert(name);
		}

		bool flag = func(root, 1);
		name2color.clear();
		
		bool flag2 = func(root, 2);
		name2color.clear();

		cout << "#" << t << " ";
		if (flag || flag2)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
}