#include <bits/stdc++.h>

using namespace std;

int n, m;
char c;
char mat[105][106];
int vis[105][105];
int ans, maxans;
void DFS(int i, int j){

    if(j < 0 ){
        j = m - 1;
    }
    else if(j == m){
        j = 0;
    }
    if(i < 0 || i == n || mat[i][j]!= c || vis[i][j]==1)
        return;

    ans++;
    vis[i][j] = 1;
    DFS(i, j+1);
    DFS(i+1, j);
    DFS(i, j-1);
    DFS(i-1, j);
}

int main()
{
    while(cin>>n>>m){
        maxans = 0;
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++)
                cin>>mat[i][j], vis[i][j] = 0;
        }
        int x, y;
        cin>>x>>y;
        c = mat[x][y];
        DFS(x, y);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == c && vis[i][j] == 0){
                    ans = 0;
                    DFS(i, j);
                    maxans = max(ans, maxans);
                }
            }
        }

        cout<<maxans<<"\n";
    }
}
