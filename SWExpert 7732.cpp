#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		string time, time2;
		cin >> time >> time2;

		cout << "#" << t + 1 << " ";

		bool flag = false;
		// 초
		string s3;
		int second = stoi(time.substr(6, 2));
		int second2 = stoi(time2.substr(6, 2));
		if (second > second2)
		{
			flag = true;
			second2 += 60;
		}
		int diff = second2 - second;
		if (diff < 10)
			s3 += '0';
		s3 += to_string(diff);
		// 분
		string s2;
		int minute = stoi(time.substr(3, 2));
		int minute2 = stoi(time2.substr(3, 2));
		if (flag)
		{
			minute2--;
			flag = false;
		}
		if (minute > minute2)
		{
			minute2 += 60;
			flag = true;
		}
		diff = minute2 - minute;
		if (diff < 10)
			s2 += '0';
		s2 += to_string(diff);

		// 시간
		string s;
		int hour = stoi(time.substr(0, 2));
		int hour2 = stoi(time2.substr(0, 2));
		if (flag)
			hour2--;
		if (hour > hour2)
			hour2 += 24;
		diff = hour2 - hour;
		if (diff < 10)
			s += '0';
		s += to_string(diff);

		cout << s + ":" + s2 + ":" + s3 << "\n";
	}
	return 0;
}