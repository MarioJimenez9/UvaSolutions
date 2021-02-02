#include <bits/stdc++.h>

using namespace std;

int r, c, m, n;
int water[105][105], mark[105][105], ways[105][105];
int even = 0, odd = 0;
void init(){
    even = 0, odd = 0;
    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            water[i][j] = 0;
            mark[i][j] = 0;
            ways[i][j] = 0;
        }
    }
}

int check(int x, int y){
    int dx[] = {m, n, m, n, -m, -n, -m, -n};
    int  dy[] = {n, m, -n, -m, n, m, -n, -m};
    int ct = 0;
    map< tuple<int, int>, int> mp;
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c || water[nx][ny] == 1 || mp[make_tuple(nx, ny)] == 1){
            continue;
        }
        else{
            ct++;
            mp[make_tuple(nx, ny)] = 1;
        }
    }
    return (ct % 2 == 0 ? 2 : 1);
}

void DFS(int i, int j){
    if(i < 0 || j < 0 || i >= r || j >= c){
        return;
    }
    if(mark[i][j] == 1 || water[i][j] == 1){
        return;
    }
    if(ways[i][j] == 0){
        ways[i][j] = check(i, j);
    }
    mark[i][j] = 1;
    if(ways[i][j] == 1){
        odd++;
    }
    else even++;
    DFS(i + n, j + m);
    DFS(i + n, j + -m);
    DFS(i + -n, j + m);
    DFS(i + -n, j + -m);
    DFS(i + m, j + n);
    DFS(i + m, j + -n);
    DFS(i + -m, j + n);
    DFS(i + -m, j + -n);
}

int main(){

    int t, q, x, y;
    cin>>t;

    for(int cas = 1; cas <= t; cas++){
        init();
        cin>>r>>c>>m>>n;
        cin>>q;
        for(int i = 0; i < q; i++){
            cin>>x>>y;
            water[x][y] = 1;
        }
        DFS(0, 0);
        cout<<"Case " << cas <<": "<<even<<" "<<odd<<"\n";
    }

    return 0;
}
