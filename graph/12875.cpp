#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <limits>
#include <tuple>
#include <string>
#include <cmath>
#include <bitset>
#include <iomanip>

using namespace std;

#define endl '\n'
#define INF numeric_limits<int>::max()/2
#define MAX 51

int N, D;
vector<vector<int>> dist(MAX, vector<int>(MAX, INF));

void input()
{
	cin >> N >> D;

	for (int i{ 0 }; i < N; ++i)
	{
		for (int j{ 0 }; j < N; ++j)
		{
			char temp;
			cin >> temp;

			if (temp == 'Y')
			{
				dist[i][j] = 1;
			}
		}
	}
}

void floydWarshall()
{
	for (int i{ 0 }; i < N; ++i)
	{
		dist[i][i] = 0;
	}

	for (int middle{ 0 }; middle < N; ++middle)
	{
		for (int left{ 0 }; left < N; ++left)
		{
			for (int right{ 0 }; right < N; ++right)
			{
				dist[left][right] = min(dist[left][right], dist[left][middle] + dist[middle][right]);
			}
		}
	}
}

void solve()
{
	floydWarshall();

	int result{ 0 };
	bool isValid{ true };

	for (int i{ 0 }; i < N; ++i)
	{
		for (int j{ 0 }; j < N; ++j)
		{
			if (dist[i][j] == INF)
			{
				isValid = false;
				continue;
			}

			result = max(result, dist[i][j]);
		}
	}

	if (isValid == false)
		cout << -1;
	else
		cout << result * D;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}