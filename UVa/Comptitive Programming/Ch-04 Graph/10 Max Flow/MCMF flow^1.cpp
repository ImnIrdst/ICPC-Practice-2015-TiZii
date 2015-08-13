#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 110;
const int oo = 2147483647;

struct Edge {
    int u, v, next;
    long long cost, flow;
}edge[20100];

struct Path {
    int a, b, c;
}path[5010];

int p[maxn], prev[maxn];
long long d[maxn];
bool vis[maxn];
int tot;
queue<int> q;

void add(int u, int v, long long cost, long long flow) {
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot].cost = cost;
    edge[tot].flow = flow;
    edge[tot].next = prev[u];
    prev[u] = tot ++;
}

void addEdge(int u, int v, long long cost, long long flow) {
    add(u, v, cost, flow);
    add(v, u, -cost, 0);
}

bool spfa(int s, int t) {
    int u, v;

    memset(vis, false, sizeof(vis));
    memset(p, -1, sizeof(p));
    fill(d, d + maxn, oo);

    d[s] = 0; vis[s] = true;
    q.push(s);

    while (!q.empty()) {
        u = q.front();

        for (int i = prev[u]; i != -1; i = edge[i].next) {
            v = edge[i].v;
            if (edge[i].flow && d[u] + edge[i].cost < d[v]) {
                d[v] = d[u] + edge[i].cost;
                p[v] = i;
                if (!vis[v]) {
                    vis[v] = true; q.push(v);
                }
            }
        }

        vis[u] = false; q.pop();
    }

    return d[t] != oo;
}

long long MinCostMaxFlow(int s, int t, long long amount) {
    long long delta, flow = 0, ret = 0;
    
    while (spfa(s, t)) {
        delta = oo;

        for (int i = p[t]; i != -1; i = p[edge[i].u])
            delta = min(delta, edge[i].flow);

        for (int i = p[t]; i != -1; i = p[edge[i].u]) {
            edge[i].flow -= delta;
            edge[i ^ 1].flow += delta;
        }

        flow += delta;
        ret += delta * d[t];
    }

    if (flow == amount) return ret;
    else return -1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int N, M;
    int a, b, c;
    int amount, cap;
    long long result;

    while (scanf("%d%d", &N, &M) != EOF) {

        for (int i = 1; i <= M; i ++)
            scanf("%d%d%d", &path[i].a, &path[i].b, &path[i].c);

        scanf("%d%d", &amount, &cap);
        
        memset(prev, -1, sizeof(prev));
        tot = 0;
        addEdge(0, 1, 0, amount);
        addEdge(N, N + 1, 0, amount);
        
        for (int i = 1; i <= M; i ++) {
            addEdge(path[i].a, path[i].b, path[i].c, cap);
            addEdge(path[i].b, path[i].a, path[i].c, cap);
        }

        result = MinCostMaxFlow(0, N + 1, amount);

        if (result >= 0) printf("%lld\n", result);
        else printf("Impossible.\n");
    }

    return 0;
}