/*
    author: Rishi Mohan Jha
    created_at: 17-10-2022  08:04 PM
*/

#include<bits/stdc++.h>
using namespace std;

#define ll        long long
#define ff        first
#define ss        second
#define pb        push_back
#define sz(x)     ((int)(x).size())
#define all(a)    (a).begin(),(a).end()

const int mx = 1e5;
const long long inf = 1e14;

vector<vector<pair<int,int>>> adj(mx + 1);
vector<int> vis(mx + 1);

void dijkstra(ll s, vector<ll> &d) {

    d[s] = 0;
    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii>> q;

    q.push({0, s});

    while (!q.empty()) {

        ll vertex = q.top().second;
        ll weight = q.top().first;
        q.pop();

        if (vis[vertex]) continue;
        vis[vertex] = 1;

        for (auto edge : adj[vertex]) {
            int to = edge.first;  // end
            int len = edge.second; // wt to reach from start(vertex) -> end(to)

            if (d[vertex] + len < d[to]) {
                d[to] = d[vertex] + len;
                // p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  int t = 1;

    ll n, m;
    cin >> n >> m;

    vector< array<ll, 3>> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    sort(all(edges));

    adj[edges[0][0]].pb({edges[0][1], edges[0][2]});
    for (int i = 1; i < m; i++) {
        if (edges[i][0] == edges[i - 1][0] && edges[i][1] == edges[i - 1][1])
            continue;
        adj[edges[i][0]].pb({edges[i][1], edges[i][2]});
    }

    vector<ll> d(n + 1, inf);

    dijkstra(1, d);

    for (int i = 1; i <= n; i++) {
        cout << d[i] << ' ';
    }
    cout << endl;
}
