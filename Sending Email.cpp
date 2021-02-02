#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define Node pair<int, int>
#define ss second
#define ff first
#define INF (1<<30)
#define MAX 20006

struct cmp{
    bool operator()(const Node &a, const Node &b){
        return a.ss>b.ss;
    }
};

int n, m, s, t, x, y, w, ans;
vector<Node> ad[MAX];
priority_queue<Node, vector<Node>, cmp> pq;
map<int, int> mp;
int dis[MAX], vis[MAX], previo[MAX];

void relax(int cur, int adj, int we){
    if(dis[cur]+we < dis[adj]){
        dis[adj] = dis[cur]+we;
        previo[adj] = cur;
        pq.push(Node(adj, dis[adj]));
    }
}

void dijkstra(int start){
    for(int i = 0; i < n; i++) dis[i] = INF;
    memset(vis, 0, sizeof(vis));
    memset(previo, -1, sizeof(previo));
    ll ans = 0;
    pq.push(Node(start, 0));
    dis[start] = 0;
    while(!pq.empty()){
        int cur = pq.top().ff;
        pq.pop();
        if(vis[cur])continue;
        vis[cur] = 1;

        for(int i = 0; i < ad[cur].size(); i++){
            if(!vis[ad[cur][i].ff]){
                int w = ad[cur][i].ss;
                int adj = ad[cur][i].ff;
                relax(cur, adj, w);
            }
        }
    }
}

int main(){

    int q;
    cin>>q;
    int caso = 1;
    while(q--){
        cin>>n>>m>>s>>t;
        for(int i = 0; i < m; i++){
            cin>>x>>y>>w;
            ad[x].push_back(Node(y, w));
            ad[y].push_back(Node(x, w));
        }
        dijkstra(s);
        cout<<"Case #"<<caso++<<": ";
        if(dis[t] == INF){
            cout<<"unreachable\n";
        }
        else{
            cout<<dis[t]<<"\n";
        }
        for(int i = 0; i < n; i++){
            ad[i].clear();
        }
    }

    return 0;
}
