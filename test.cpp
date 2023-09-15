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

using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 5;
const int INF = 1e9 + 10;
vector<pii> adj[N];
vector<int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int source)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (pii vpair : adj[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (visited[v])
                continue;

            // kaaj
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w}); // undirected

        adj[v].push_back({u, w}); // directed
    }

    // O(n+m)
    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance " << i << ": " << dist[i] << endl;
    }

    return 0;
}

/*
check this problem Statement, also my code, my code is handling all this test casses perfecly, but for some reason not passed all test cases in online platform, so please make all corner casses correct and solve this.

my code :


Problem Statement

You'll be given a graph of N nodes and E edges. For each edge, you'll be given A, B and W which means there is an edge from A to B which will cost W. Also, you'll be given Q queries, for each query you'll be given X and Y, where X is the source and Y is the destination. You need to print the minimum cost from A to B for each query. If there is no connection between X and Y, print -1.

Note: There can be multiple edges from one node to another.

Input Format

First line will contain N and E.
Next E lines will contain A, B and W.
After that you'll get Q.
Next Q queries will contain X and Y.
Constraints

1 <= N <= 100
1 <= E <= 10^5
1 <= A, B <= N
1 <= W <= 10^9
1 <= Q <= 10^5
1 <= X, Y <= N
Output Format

Output the minimum cost for each query.

Sample Input 0 :
4 7
1 2 10
2 3 5
3 4 2
4 2 3
3 1 7
2 1 1
1 4 4
6
1 2
4 1
3 1
1 4
2 4
4 2

Sample Output 0 :
7
4
6
4
5
3

Sample Input 1 :
4 4
1 2 4
2 3 4
3 1 2
1 2 10
6
1 2
2 1
1 3
3 1
2 3
3 2

Sample Output 1 :
4
6
8
2
4
6




for this input :
4 7
1 2 10
2 3 5
3 4 2
4 2 3
3 1 7
2 1 1
1 4 4
6
1 2
4 1
3 1
1 4
2 4
4 2

my expected output is :
7
4
6
4
5
3

but receiving this output :
10
4
7
4
5
3

check this code, can I avoid use of emplace_back here? :

*/