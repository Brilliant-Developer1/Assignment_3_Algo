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

vector<int> parent;

int dsu_find(int node)
{
    if (node == parent[node])
        return node;
    return parent[node] = dsu_find(parent[node]);
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
        parent[leaderA] = leaderB;
}

int main()
{
    int n, e;
    cin >> n >> e;

    parent.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    int cycleEdges = 0;

    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;

        if (dsu_find(u) == dsu_find(v))
        {

            cycleEdges++;
        }
        else
        {
            dsu_union(u, v);
        }
    }

    cout << cycleEdges << endl;

    return 0;
}