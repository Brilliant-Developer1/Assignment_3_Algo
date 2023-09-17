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

You have just opened a dish cable business and you want to connect your dish lines in your area. In your area there are N buldings and E roads. The roads are two way obviously. In each road there is a cost of connecting the cables. You want to connect all buldings in such a way that there is connection from any building to another, not necessary to be directly.

As you are a businessman, you want the total cost to be minimum. Can you tell the minimum total cost to do the work?

Note: There can be multiple road from one building to another. If it is not possible to connect all the building, print -1.

Input Format

First line will contain N and E.
Next E lines will contain A, B and W which means there is a connection in between A and B where the cost for connecting the cable is W.
Constraints

1 <= N, E <= 10^5
1 <= A, B <= N
1 <= W <= 10^9
Output Format

Output the minimum cost.

Sample Input 0 :
5 7
1 2 10
1 3 5
3 2 4
2 4 1
3 4 2
4 5 3
1 5 2

Sample Output 0 :
8

Sample Input 1 :
3 2
1 2 10
2 1 2

Sample Output 1 :
-1




for this input :
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

my expected output is :
4
6
8
2
4
6

but receiving this output :
4
4
2
2
4
4

check this code, can I avoid use of emplace_back here? :

*/