#include <iostream>
using namespace std;

const int MAX = 32767 + 1;

int num[MAX];

// 미리 전처리
void preCalc(void)
{
	for (int i = 0; i*i <= MAX; i++)
		for (int j = i; (i*i + j * j) <= MAX; j++)
			for (int k = j; (i*i + j * j + k * k) <= MAX; k++)
				for (int l = k; (i*i + j * j + k * k + l * l) <= MAX; l++)
				{
					int temp = i * i + j * j + k * k + l * l;
					num[temp]++;
				}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	preCalc();
	for (int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;
		
		cout << "#" << t << " " << num[N] << "\n";
	}
}