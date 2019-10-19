#include <iostream>
#include <vector>
using namespace std;

const int MAX = 4000 + 1;

typedef struct
{
	int y, x, dir, k;
} Atom;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 0, 1 },{ 0, -1 },{ -1, 0 },{ 1, 0 } };

int N;
vector<Atom> atoms;
int arr[MAX][MAX];

int func()
{
	int result = 0;

	while (!atoms.empty())
	{
		int aSize = atoms.size();

		for (int i = 0; i < aSize; i++)
		{
			arr[atoms[i].y][atoms[i].x] = 0;

			int dir = atoms[i].dir;
			int nextY = atoms[i].y + moveDir[dir].y;
			int nextX = atoms[i].x + moveDir[dir].x;

			if (nextY < 0 || nextY > 4000 || nextX < 0 || nextX > 4000)
			{
				atoms[i].k = 0;

				continue;
			}

			atoms[i].y = nextY;
			atoms[i].x = nextX;

			arr[nextY][nextX] += atoms[i].k;
		}

		for (int i = 0; i < aSize; i++)
		{
			if (atoms[i].k == 0)
			{
				continue;
			}

			int y = atoms[i].y;
			int x = atoms[i].x;

			if (arr[y][x] != atoms[i].k)
			{
				result += arr[y][x];

				arr[y][x] = 0;
				atoms[i].k = 0;
			}
		}

		vector<Atom> v;
		v.assign(atoms.begin(), atoms.end());
		atoms.clear();

		int vSize = v.size();
		for (int i = 0; i < vSize; i++)
		{
			if (v[i].k != 0)
			{
				atoms.push_back(v[i]);
			}
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N;

		atoms.clear();

		for (int i = 0; i < N; i++)
		{
			int y, x, dir, k;
			cin >> y >> x >> dir >> k;

			y += 1000;
			x += 1000;
			y *= 2;
			x *= 2;

			atoms.push_back({ y, x, dir, k });
		}

		cout << "#" << t << " " << func() << "\n";
	}

	return 0;
}