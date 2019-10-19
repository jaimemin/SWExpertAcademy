#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20;

int arr[MAX][MAX];

int N, X;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> X;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		int result = 0;

		// ����
		for (int i = 0; i < N; i++)
		{
			// Ȱ�ַ� ����
			int road = 1;
			// ������ ���� ����
			int cnt = 1;
			// Ȱ�ַ� ���� �� �ִ��� �Ǵ� ����
			bool flag = true;

			for (int j = 1; j < N; j++)
			{
				int diff = arr[j][i] - arr[j - 1][i];

				// �Ұ����� ���
				if (abs(diff) > 1)
				{
					flag = false;

					break;
				}

				switch (diff)
				{
				// �Ʒ��ʿ� �ִ� ������ �� ���� ���
				case -1:
					cnt = 1;

					// j�� �������� Ȱ�ַ� ���� �� �ִ��� Ȯ���ؾ���
					for (int k = j + 1; k < N; k++)
					{
						// ������ ���� �ƴ϶��
						if (arr[k][i] != arr[k - 1][i])
						{
							break;
						}

						// ������ �����̰� Ȱ�ַ� ���� ���� ���� ��
						if (++cnt >= X)
						{
							break;
						}
					}

					// Ȱ�ַ� ������� ���
					if (cnt >= X)
					{
						cnt = 0;
						j += X - 1;
						road += X;
					}
					else
					{
						flag = false;
					}

					break;
				// ������ ���
				case 0:
					road++;
					cnt++;

					break;
				// �Ʒ��ʿ� �ִ� ������ �� ���� ���
				case 1:
					// ���±��� Ȱ�ַθ� ���� �� �ִ� ������ ����ߴ��� Ȯ��
					if (cnt >= X)
					{
						cnt = 1;
						road++;
					}
					else
					{
						flag = false;
					}

					break;
				}

				if (!flag)
				{
					break;
				}
			}

			if (flag && (road == N))
			{
				result++;
			}
		}

		// ����
		for (int i = 0; i < N; i++)
		{
			int road = 1;
			int cnt = 1;
			bool flag = true;

			for (int j = 1; j < N; j++)
			{
				int diff = arr[i][j] - arr[i][j - 1];

				if (abs(diff) > 1)
				{
					flag = false;

					break;
				}

				switch (diff)
				{
				case -1:
					cnt = 1;

					for (int k = j + 1; k < N; k++)
					{
						if (arr[i][k] != arr[i][k - 1])
						{
							break;
						}

						if (++cnt >= X)
						{
							break;
						}
					}

					if (cnt >= X)
					{
						cnt = 0;
						j += X - 1;
						road += X;
					}
					else
					{
						flag = false;
					}

					break;
				case 0:
					cnt++;
					road++;

					break;
				case 1:
					if (cnt >= X)
					{
						cnt = 1;
						road++;
					}
					else
					{
						flag = false;
					}

					break;
				}

				if (!flag)
				{
					break;
				}
			}

			if (flag && road == N)
			{
				result++;
			}
		}

		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}