#include <bits/stdc++.h>

using namespace std;

#define NODE pair<int, int>
#define ss second
#define ff first

int n;
int vis[106][106];
char mat[106][106];
int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0, -1, 1};

void BFS(int i, int j){
    queue< NODE > q;
    q.push({i, j});
    vis[i][j] = 1;
    while(!q.empty())
    {
        NODE current = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int auxi = current.ff + dx[i];
            int auxj = current.ss + dy[i];
            if(auxi >= 0 && auxi < n && auxj >=0 && auxj < n && mat[auxi][auxj] != '.' && vis[auxi][auxj] == 0){
                vis[auxi][auxj] = 1;
                q.push({auxi, auxj});
            }
        }
    }
}

int main(){

    int t;
    cin>>t;
    for(int cas = 1; cas <= t; cas++){
        int ans = 0;
        cin>>n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin>>mat[i][j];
                vis[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 'x' && vis[i][j] == 0){
                    BFS(i, j);
                    ans++;
                }
            }
        }
        cout<<"Case " << cas <<": "<<ans<<"\n";
    }

    return 0;
}
