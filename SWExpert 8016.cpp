#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		long long N;
		cin >> N;

		long long left = 2 * (N - 1)*(N - 1) + 1;
		long long right = 2 * N*N - 1;

		cout << "#" << t << " " << left << " " << right << "\n";
	}
	return 0;
}