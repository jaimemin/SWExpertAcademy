#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;
string s;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int t = 1; t <= 10; t++)
	{
		cin >> N >> s;

		string postfix;
		stack<char> st;
		long long result = 0;

		for (int i = 0; i < s.length(); i++)
		{
			switch (s[i])
			{
			case '+':
				while (!st.empty() && (st.top() == '+'))
				{
					postfix += st.top();
					st.pop();
				}

				st.push(s[i]);
				break;
			default:
				postfix += s[i];
				break;
			}
		}

		while (!st.empty())
		{
			postfix += st.top();
			st.pop();
		}

		stack<int> calculator;
		for (int i = 0; i < postfix.length(); i++)
		{
			if (postfix[i] >= '0' && postfix[i] <= '9')
				calculator.push(postfix[i] - '0');
			else
			{
				int a = calculator.top();
				calculator.pop();
				int b = calculator.top();
				calculator.pop();
				
				calculator.push(a + b);
			}
		}

		cout << "#" << t << " " << calculator.top() << "\n";
	}
	return 0;
}