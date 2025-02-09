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
using ll = long long;
using vertex = tuple<ll, int, ll>;

#define MAX 100'001
#define endl '\n'
#define INF numeric_limits<ll>::max()

ll N{ 0 }, M{ 0 }, A{ 0 }, B{ 0 }, C{ 0 };
vector<vector<pair<ll, ll>>> edges(MAX, vector<pair<ll, ll>>());
vector<ll> dist(MAX, INF);

ll result{ INF };

void input()
{
	cin >> N >> M >> A >> B >> C;

	for (int i{ 0 }; i < M; ++i)
	{
		int src{ 0 }, dst{ 0 }, w{ 0 };
		cin >> src >> dst >> w;

		edges[src].push_back({ dst,w });
		edges[dst].push_back({ src,w });
	}
}

void dijkstra()
{
	priority_queue<vertex, vector<vertex>, greater<vertex>> pq;
	pq.push({ 0,A,0 });
	dist[A] = 0;

	while (pq.empty() == false)
	{
		auto cur{ pq.top() };
		pq.pop();

		auto src{ get<1>(cur) };
		auto curDist{ get<0>(cur) };
		auto curMax{ get<2>(cur) };

		if (dist[src] < curMax)
			continue;

		if (src == B)
		{
			result = min(result, curMax);
		}

		for (auto& edge : edges[src])
		{
			auto dst{ edge.first };
			auto w{ edge.second };
			auto newDist{ curDist + w };
			auto tempMax = max(curMax, w);

			if (newDist > C)
				continue;

			if (dist[dst] > tempMax)
			{
				dist[dst] = tempMax;
				pq.push({ newDist,dst,tempMax });
			}
		}
	}
}

void solve()
{
	dijkstra();

	if (result == INF)
		cout << -1;
	else
		cout << result;
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