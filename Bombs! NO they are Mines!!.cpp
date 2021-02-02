#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define piii pair<int, pii>
#define ss second
#define ff first

int dx[]= {0, 0, -1, 1 };
int dy[]= {1, -1, 0, 0 };

int main(){

    int n, m;
    while(cin>>n>>m, (n || m)){
        int t;
        int grid[n][m], vis[n][m];
        memset(grid, 0, sizeof(grid));
        memset(vis, 0, sizeof(vis));
        cin>>t;
        while(t--){
            int r, c, am;
            cin>>r>>am;
            for(int i = 0; i < am; i++){
                cin>>c;
                grid[r][c] = 1;
            }
        }
        int si, sj, fi, fj;
        cin>>si>>sj>>fi>>fj;
        queue<piii> q;
        q.push({si, {sj, 0}});
        vis[si][sj] = 1;
        while(!q.empty())
        {
            piii cur = q.front();
            q.pop();
            if(cur.ff == fi && cur.ss.ff == fj){
                cout<<cur.ss.ss<<"\n";
                break;
            }
            for(int i = 0; i < 4; i++){
                int auxi = cur.ff+dx[i], auxj = cur.ss.ff+dy[i];
                if(auxi >= 0 && auxi < n && auxj >= 0 && auxj < m && grid[auxi][auxj] == 0 && vis[auxi][auxj] == 0){
                    q.push({auxi, {auxj, cur.ss.ss+1}});
                    vis[auxi][auxj] = 1;
                }
            }
        }
    }

    return 0;
}
