#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <set>

using namespace std;

#define n 7

int extract_min(set<int> &s, int dist[n])
{
    int min = INT_MAX;
    int v;
    
    for (auto & i : s) {
        if (dist[i] < min) {
            min = dist[i];
            v = i;
        }
    }
    s.erase(v);
    return v;
}

void dijkstra(int g[n][n], int src)
{
    int dist[n];
    int prev[n];
    set<int> s;
 
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        s.insert(i);
    }
    dist[src] = 0;

    while (!s.empty()) {
        int u = extract_min(s, dist);

        for (int w = 0; w < n; w++) {
            if (g[u][w] != INT_MAX) {
                int tmp = dist[u] + g[u][w];
                if (tmp < dist[w]) {
                    dist[w] = tmp;
                    prev[w] = u;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << ':' << dist[i] << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << i << ':' << prev[i] << endl;
    }
}

int main()
{
    /* see FaGe's book */
    int graph[n][n] = {{0, 10, 2, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
                       {10, 0, INT_MAX, INT_MAX, 1, INT_MAX, INT_MAX},
                       {2, INT_MAX, 0, 2, INT_MAX, 11, INT_MAX},
                       {INT_MAX, INT_MAX, 2, 0, 4, 6, INT_MAX},
                       {INT_MAX, 1, INT_MAX, 4, 0, INT_MAX, 7},
                       {INT_MAX, INT_MAX, 11, 6, INT_MAX, 0, 3},
                       {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 7, 3, 0},
                   };

    dijkstra(graph, 0);
    return 0;
}
