// #include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
// #include<bits/stdc++.h>
using namespace std;
typedef pair<long long int, long long int> pii;

class Edge
{
public:
    int u;
    long long int w;
    Edge(int u = 0, long long int w = 0)
    {
        this->u = u;
        this->w = w;
    }
};

const int N = 1e5 + 5;
vector<vector<Edge>> adj(N);
const long long int INF = 1e18;

vector<long long int> dijkstra(int source)
{
    vector<long long int> dist(N, INF);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        long long int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (const Edge &edge : adj[u])
        {
            int v = edge.u;
            long long int w = edge.w;

            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; ++i)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        Edge edge(b - 1, w);
        adj[a - 1].push_back(edge);
    }

    int test;
    cin >> test;

    while (test--)
    {
        int x, y;
        cin >> x >> y;

        vector<long long int> dist = dijkstra(x - 1);

        if (dist[y - 1] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dist[y - 1] << endl;
        }
    }

    return 0;
}