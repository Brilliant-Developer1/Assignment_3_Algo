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

const long long INF = 1e18;

class Edge
{
public:
    int u, v, w;
    Edge(int u = 0, int v = 0, long long int w = 0)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool bellmanFord(int n, int s, int dest, vector<Edge> &edges, vector<long long> &dist)
{
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (const Edge &edge : edges)
        {
            if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    bool nagCycle = false;
    for (const Edge &edge : edges)
    {
        if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v])
        {
            nagCycle = true;
            break;
        }
    }

    if (nagCycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return false;
    }
    else if (dist[dest] == INF)
    {
        cout << "Not Possible" << endl;
        return true;
    }
    else
    {
        cout << dist[dest] << endl;
        return true;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edges(e);
    vector<long long> dist(n + 1, INF);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
    }

    int s;
    cin >> s;

    int test;
    cin >> test;

    while (test--)
    {
        int dest;
        cin >> dest;

        if (!bellmanFord(n, s, dest, edges, dist))
        {
            break;
        }
    }

    return 0;
}