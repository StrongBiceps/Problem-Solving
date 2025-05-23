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

#define MAX 300'001
#define endl '\n'
#define INF numeric_limits<ll>::max()

int N{ 0 }, M{ 0 }, start{ 0 }, maxDist{ 0 };
vector<vector<pair<int, int>>> edges(MAX, vector<pair<int, int>>());
vector<ll> dist(MAX, INF);
using vertex = tuple<ll, int>;
vector<int> result;

void input()
{
    cin >> N >> M >> maxDist >> start;

    for (int i{ 0 }; i < M; ++i)
    {
        int src{ 0 }, dst{ 0 };

        cin >> src >> dst;

        edges[src].push_back({ dst,1 });
    }
}

void dijkstra()
{
    priority_queue<vertex, vector<vertex>, greater<vertex>> pq;
    pq.push({ 0,start });
    dist[start] = 0;

    while (pq.empty() == false)
    {
        auto cur{ pq.top() };
        pq.pop();

        auto src{ get<1>(cur) };
        auto curDist{ get<0>(cur) };

        if (dist[src] < curDist)
            continue;

        if (curDist == maxDist)
            result.push_back(src);

        for (auto& edge : edges[src])
        {
            auto dst{ edge.first };
            auto w{ edge.second };
            auto newDist{ curDist + w };

            if (newDist > maxDist)
                continue;

            if (dist[dst] > newDist)
            {
                dist[dst] = newDist;
                pq.push({ newDist,dst });
            }
        }
    }
}

void solve()
{
    dijkstra();

    if (result.size() == 0)
    {
        cout << -1;
        return;
    }

    sort(result.begin(), result.end());

    for (auto& v : result)
    {
        cout << v << endl;
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solve();

    return 0;
}