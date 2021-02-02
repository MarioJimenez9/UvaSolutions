#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define piii pair<int, pii>
#define ff first
#define ss second
#define INF 1<<30
int n, m;
int grid[1000][1000];
int dis[1000][1000];
int vis[1000][1000];
pii prevv[1000][1000];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans=0;

struct cmp{
    bool operator()(const piii &a, const piii &b){
        return a.ss.ss>b.ss.ss;
    }
};
priority_queue<piii, vector<piii>, cmp > pq;

void relax(int ci, int cj, int adi, int adj, int weight){
    if(dis[ci][cj]+weight < dis[adi][adj]){
        dis[adi][adj] = dis[ci][cj]+weight;
        prevv[adi][adj] = {ci, cj};
        pq.push({adi, {adj, dis[adi][adj]}});
    }
}

void dijkstra(){
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dis[i][j] = INF;
        }
    }
    memset(prevv, -1, sizeof(prevv));

    pq.push({0, {0, grid[0][0]}});
    dis[0][0]=0;
    while(!pq.empty()){
        piii cur = pq.top();
        pq.pop();
        if(vis[cur.ff][cur.ss.ff])continue;
        vis[cur.ff][cur.ss.ff] = 1;

        for(int i = 0; i < 4; i++)
        {
            int auxi = dx[i]+cur.ff, auxj = dy[i]+cur.ss.ff;
            if(auxi >= 0 && auxi<n && auxj >= 0 && auxj < m){
                int w = grid[auxi][auxj];
                relax(cur.ff, cur.ss.ff, auxi, auxj, w);
            }
        }
    }
}
void solve(int i, int j){
    if(prevv[i][j].ff != -1){
        solve(prevv[i][j].ff, prevv[i][j].ss);
    }
    ans += grid[i][j];
}
int main(){
    int t;
    cin>>t;

    while(t--){
        ans = 0;
        cin>>n>>m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>grid[i][j];
            }
        }
        dijkstra();
        solve(n-1, m-1);
        cout<<ans<<"\n";
    }
}
