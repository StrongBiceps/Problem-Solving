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
#define MAX 101

int N{ 0 }, M{ 0 };
vector<vector<int>> dist(MAX, vector<int>(MAX, INF));

pair<int, int> result{ INF,INF };
int totalDist{ INF };

void input()
{
	cin >> N >> M;

	for (int i{ 0 }; i < M; ++i)
	{
		int src{ 0 }, dst{ 0 };
		cin >> src >> dst;

		dist[src][dst] = 1;
		dist[dst][src] = 1;
	}
}

void floydWarshall()
{
	for (int i{ 1 }; i <= N; ++i)
	{
		dist[i][i] = 0;
	}

	for (int middle{ 1 }; middle <= N; ++middle)
	{
		for (int left{ 1 }; left <= N; ++left)
		{
			for (int right{ 1 }; right <= N; ++right)
			{
				dist[left][right] = min(dist[left][right], dist[left][middle] + dist[middle][right]);
			}
		}
	}
}

void solve()
{
	floydWarshall();

	for (int i{ 1 }; i <= N; ++i)
	{
		for (int j{ i + 1 }; j <= N; ++j)
		{
			auto total{ 0 };

			for (int k{ 1 }; k <= N; ++k)
			{
				if (i == k || j == k)
					continue;

				total += min(dist[i][k], dist[j][k]);
			}

			if (total < totalDist)
			{
				totalDist = total;

				result.first = i;
				result.second = j;
			}
			else if (total == totalDist)
			{
				result = min(result, { i,j });
			}
		}
	}

	cout << result.first << ' ' << result.second << ' ' << totalDist * 2;
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