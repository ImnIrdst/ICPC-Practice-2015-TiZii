#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = (int)1e8;



struct ToNode{
	int v, w;
	ToNode(int v, int w)
		:v(v), w(w){}
};

struct pii {
	int time, tax;
	pii(int time = INF, int tax = INF)
		:time(time), tax(tax){}
	bool operator<(const pii& op) const {
		return make_pair(time, tax) < make_pair(op.time, op.tax);
	}
	bool operator>(const pii& op) const {
		return make_pair(time, tax) > make_pair(op.time, op.tax);
	}
	bool operator==(const pii& op) const {
		return make_pair(time, tax) == make_pair(op.time, op.tax);
	}
};

struct QEntry{
	int node; pii cost;
	QEntry(int node, pii cost)
		:node(node), cost(cost){}
	bool operator<(const QEntry& op) const {
		return cost < op.cost;
	}
};

typedef vector<pii>     vp;
typedef vector<int>     vi;
typedef vector<ToNode> vtn;
typedef vector<vtn   > vvtn;

int n, m; vvtn adj;

pii dijkstra(int s, int t, vp& dist){
	dist.assign(n, pii());
	priority_queue<QEntry> q;
	q.push(QEntry(s, pii(0,0))); dist[s] = pii(0,0);

	while (!q.empty()){
		QEntry u = q.top(); q.pop();
		if (u.node == t) return u.cost;
		if (u.cost > dist[u.node]) continue;
		for (int i = 0; i < adj[u.node].size(); i++){
			QEntry v(adj[u.node][i].v, pii(u.cost.time + 94, u.cost.tax + adj[u.node][i].w));
			if (dist[v.node] > v.cost){
				dist[v.node] = v.cost; q.push(v);
			}
		}
	}
	return pii();
}

int main(){
	int s, t; 
	cin >> n >> m >> s >> t;
	s--; t--;
	adj.assign(n, vtn());
	for (int i = 0; i < m; i++){
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		int w; cin >> w;
		adj[u].push_back(ToNode(v, w));
		adj[v].push_back(ToNode(u, w));
	}

	vp dist(n, pii());
	pii ans = dijkstra(s, t, dist);
	if (ans.time == INF) cout << "NEVER" << endl;
	else cout << ans.time << " " << ans.tax << endl;
}