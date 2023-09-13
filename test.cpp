#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = 1e9 + 7;

class Edge
{
public:
    int u, v, w;
    Edge(int a = 0, int b = 0, int w = 0) : u(a), v(b), w(w) {}
};

int n, e;
vector<Edge> edges(e);

bool bellmanFord(int n, int s, int dest)
{
    vector<int> dist(n + 1, INF);
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
    }
    else if (dist[dest] == INF)
    {
        cout << "Not Possible" << endl;
    }
    else
    {
        cout << dist[dest] << endl;
    }

    return nagCycle;
}

int main()
{

    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int s;
    cin >> s;

    int test;
    cin >> test;

    bool nagCycle = false;

    while (test--)
    {
        int dest;
        cin >> dest;

        if (bellmanFord(n, s, dest) && !nagCycle)
        {
            nagCycle = true;
            break;
        }
    }

    return 0;
}

/*
check this problem Statement again, also my code, my code is handling all this test casses perfecly, but for some reason not passed all test cases in online platform, so please make all corner casses correct and solve this.

my code :


Problem Statement

You will be given N numbers of nodes, E numbers of edges in a graph. For each edge you will be given A, B and W which means there is a connection from A to B for which you need to give W cost. The value of nodes could be from 1 to N.

You will be given a source node S. Then you will be given a test case T, for each test case you will be given a destination node D. You need to tell the minimum cost from source node to destination. If there is no possible path from S to D then print Not Possible.

Note: If there is a negative weight cycle in the graph, then no answer would be correct. So print one line only - "Negative Cycle Detected".

Input Format

First line will contain N and E.
Next E lines will contain A, B and W.
Next line will contain source node S.
Next line will contain T, the number of test cases.
For each test case, you will get D.
Constraints

1 <= N <= 1000
1 <= E <= 1000
1 <= S <= N
1 <= T <= 1000
1 <= D <= N
-10^9 <= W <= 10^9
Output Format

Output the minimum cost for each test case.

Sample Input 1 :
5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
1
5
1
2
3
4
5

Sample Output 1 :
0
-1
-2
-5
0


Sample Input 2 :
5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
5
5
1
2
3
4
5

Sample Output 2 :
Not Possible
Not Possible
Not Possible
Not Possible
0


Sample Input 3 :
5 8
1 2 -2
1 3 -10
3 2 1
2 4 7
4 3 -3
4 5 5
2 5 2
4 1 1
1
5
1
2
3
4
5

Sample Output 3 :
Negative Cycle Detected
*/