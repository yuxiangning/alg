#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct graph {
    vector<list<int> > adj;

    graph(int count) {
        adj.resize(count);
    }

    void add(int from, int to) {
        adj[from].push_back(to); 
    }
};

void dfs(graph &g, int v, bool visited[])
{
    if (visited[v] == true)
        return;

    visited[v] = true;

    cout << v << endl;

    for (auto &w : g.adj[v]) {
        if (visited[w] == false)
            dfs(g, w, visited);
    }
}

void bfs(graph &g, int v)
{
    bool visited[4] = {false};
    queue<int> q;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();
        visited[v] = true;

        cout << v << endl;

        for (auto &w : g.adj[v]) {
            if (visited[w] == false)
                q.push(w);
        }
    }
}

int main()
{
    struct graph g(4);
    bool visited[4] = { false };

    g.add(0, 1);
    g.add(0, 2);
    g.add(1, 2);
    g.add(2, 0);
    g.add(2, 3);
    g.add(3, 3);
/*
    for (int i = 0; i < 4; i++)
        visited[i] = false;
*/

    dfs(g, 2, visited);

    bfs(g, 2);
    return 0;
}

