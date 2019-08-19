#include <iostream>
using namespace std;

const int MAX = 10;

int N, X, M;
bool answer;
int maxSum;
int cage[MAX];
int arr[MAX];
int leftCage[MAX];
int rightCage[MAX];
int sumOfHamsters[MAX];

void func(int idx)
{
	if (idx == N)
	{
		bool flag = true;
		// ������ �����ϴ��� Ȯ��
		for (int i = 0; i < M; i++)
		{
			int sum = 0;
			for (int j = leftCage[i] - 1; j <= rightCage[i] - 1; j++)
			{
				sum += cage[j];
			}

			if (sum != sumOfHamsters[i])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			// ó�� ������ ������ ���
			if (!answer)
			{
				for (int i = 0; i < N; i++)
				{
					arr[i] = cage[i];
					maxSum += cage[i];
				}
				answer = true;
			}
			// ���� ������ ������ ���
			else
			{
				int tempSum = 0;
				for (int i = 0; i < N; i++)
				{
					tempSum += cage[i];
				}

				// ���� 2: �ܽ��Ͱ� �� ���� ��� ���
				if (tempSum > maxSum)
				{
					maxSum = tempSum;
					for (int i = 0; i < N; i++)
					{
						arr[i] = cage[i];
					}
				}
				// ���� 3: �ܽ��� ���� ���� ��� ���������� �ռ��� ��� ���
				else if (tempSum == maxSum)
				{
					bool flag2 = true;
					for (int i = 0; i < N; i++)
					{
						if (cage[i] < arr[i])
						{
							flag2 = false;
							break;
						}
					}

					if (flag2)
					{
						for (int i = 0; i < N; i++)
						{
							arr[i] = cage[i];
						}
					}
				}
			}
		}

		return;
	}

	for (int i = 0; i <= X; i++)
	{
		cage[idx] = i;
		func(idx + 1);
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
		cin >> N >> X >> M;

		for (int i = 0; i < M; i++)
		{
			cin >> leftCage[i] >> rightCage[i] >> sumOfHamsters[i];
		}

		maxSum = 0;
		answer = false;
		func(0);

		cout << "#" << t << " ";
		if (answer)
		{
			for (int i = 0; i < N; i++)
			{
				cout << arr[i] << " ";
			}
		}
		else
		{
			cout << -1;
		}
		cout << "\n";
	}

	return 0;
}