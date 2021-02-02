#include <bits/stdc++.h>

using namespace std;

#define NODE pair<int, int>
#define ss second
#define ff first

int n, m;
string grid[250];
int vis[250][250];
int ans = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int BFS2(int i, int j){
    bool f = true;
    queue< NODE > q;
    q.push({i, j});
    vis[i][j] = 1;
    while(!q.empty()){
        NODE current = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int auxi = current.ff + dx[i];
            int auxj = current.ss + dy[i];
            if(auxi < 0 || auxi >= n || auxj < 0 || auxj >= m*4){
                f = false;
                continue;
            }
            else if(grid[auxi][auxj] == '0' && vis[auxi][auxj] == 0){
                vis[auxi][auxj] = 1;
                q.push({auxi, auxj});
            }
        }
    }
    return f ? 1 : 0;
}

void BFS(int i, int j){
    queue< NODE > q;
    q.push({i, j});
    vis[i][j] = 1;
    while(!q.empty()){
        NODE current = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int auxi = current.ff + dx[i];
            int auxj = current.ss + dy[i];
            if(auxi < 0 || auxi >= n || auxj < 0 || auxj >= m*4 || vis[auxi][auxj] == 1)
                continue;
            if(grid[auxi][auxj] == '1'){
                vis[auxi][auxj] = 1;
                q.push({auxi, auxj});
            }
            if(grid[auxi][auxj] == '0'){
                ans += BFS2(auxi, auxj);
            }
        }
    }
}

int main(){
    int cas = 1;
    map<char, string> mp;
    mp['0'] = "0000";
    mp['1'] = "0001";
    mp['2'] = "0010";
    mp['3'] = "0011";
    mp['4'] = "0100";
    mp['5'] = "0101";
    mp['6'] = "0110";
    mp['7'] = "0111";
    mp['8'] = "1000";
    mp['9'] = "1001";
    mp['a'] = "1010";
    mp['b'] = "1011";
    mp['c'] = "1100";
    mp['d'] = "1101";
    mp['e'] = "1110";
    mp['f'] = "1111";

    map<int, char> mp2;
    mp2[0] = 'W';
    mp2[1] = 'A';
    mp2[2] = 'K';
    mp2[3] = 'J';
    mp2[4] = 'S';
    mp2[5] = 'D';
    char c;
    while(cin>>n>>m, n && m){
        string ans2 = "";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>c;
                grid[i] += mp[c];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m*4; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    ans = 0;
                    BFS(i, j);
                    ans2 += mp2[ans];
                }
            }
        }
        sort(ans2.begin(), ans2.end());
        cout<<"Case " << cas++ <<": " << ans2<<"\n";
        for(int i = 0; i < n; i++){
            grid[i] = "";
            for(int j = 0; j < m*4; j++){
                vis[i][j] = 0;
            }
        }
    }

    return 0;
}
