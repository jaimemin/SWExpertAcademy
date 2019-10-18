#include <iostream>
#include <algorithm>
using namespace std;

int prices[4];
int monthly[12];
int result;

void func(int month, int price)
{
	if (month >= 11)
	{
		result = min(result, price);
		
		return;
	}

	if (monthly[month + 1])
	{
		// 하루치
		func(month + 1, price + prices[0] * monthly[month + 1]);
		// 한달치
		func(month + 1, price + prices[1]);
		// 3달치
		func(month + 3, price + prices[2]);
	}
	else
	{
		func(month + 1, price);
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
		for (int i = 0; i < 4; i++)
		{
			cin >> prices[i];
		}

		for (int i = 0; i < 12; i++)
		{
			cin >> monthly[i];
		}

		result = prices[3];

		func(-1, 0);

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}