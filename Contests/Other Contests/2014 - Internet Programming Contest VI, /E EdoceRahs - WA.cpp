#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

#define NUM_NODES 26

using namespace std;

int n;                              // actual number of nodes
int dfs_counter;                    // initial value 0
int vis[NUM_NODES];                 // 0 for unvisited, 1 for visited
int graph[NUM_NODES][NUM_NODES];    // adjacent matrix of graph, 0 & 1
int dfs_num[NUM_NODES];             // initial value 0
int dfs_low[NUM_NODES];             // initial value 0
vector<int> s;                      // a stack to store scc
vector<char> xmap;
map<char, int> mapx;
vector<string> res;

void initialize() {
    memset(graph, 0, sizeof(graph));
    memset(dfs_low, 0, sizeof(dfs_low));
    memset(dfs_num, 0, sizeof(dfs_num));
    memset(vis, 0, sizeof(vis));
    s.clear();
    dfs_counter = 0;
    xmap.clear();
    mapx.clear();
    res.clear();
}

void dfs_scc(int u) {
    dfs_low[u] = dfs_num[u] = ++dfs_counter;
    s.push_back(u);
    vis[u] = 1;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {
            if (!vis[v])                            // never been visited
                dfs_scc(v);
            if (dfs_num[v] != 0)                    // have been visited and not "released"
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }

    if (dfs_low[u] == dfs_num[u]) {                 // root of scc
        string line = "";

        while (1) {
            int v = s.back(); s.pop_back();
            dfs_num[v] = 0;                         // crucial step, "release" node v, don't consider v for updating
            line.push_back(xmap[v]);
            if (u == v)
                break;
        }
        sort(line.begin(), line.end());

        res.push_back(line);
    }
}

void xmapx(char x, char p) {
    if (!mapx.count(x)) {
        xmap.push_back(x);
        mapx[x] = xmap.size() - 1;
    }

    if (x != p) {
        graph[mapx[p]][mapx[x]] = 1;
    }
}

int main(int argc, char const *argv[]) {
    int t;
    int testcount = 0;
    while (cin >> t && t) {
        if (testcount++)
            cout << endl;
        initialize();

        while (t--) {
            string l1, l2, l3, l4, l5, l;

            cin >> l1 >> l2 >> l3 >> l4 >> l5 >> l;
            xmapx(l[0], l[0]);
            xmapx(l1[0], l[0]);
            xmapx(l2[0], l[0]);
            xmapx(l3[0], l[0]);
            xmapx(l4[0], l[0]);
            xmapx(l5[0], l[0]);
        }

        n = xmap.size();

        for (int i = 0; i < n; ++i) {
            if (!vis[i])
                dfs_scc(i);
        }


        sort(res.begin(), res.end());

        for (int i = 0; i < res.size(); ++i) {
            string line = res[i];
            cout << line[0];
            for (int j = 1; j < line.size(); j++)
                cout << " " << line[j];
            cout << endl;
        }
    }

    return 0;
}