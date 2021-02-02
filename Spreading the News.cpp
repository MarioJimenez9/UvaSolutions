#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define piii pair<int, pii>
#define ss second
#define ff first

int dx[]= {0, 0, -1, 1 };
int dy[]= {1, -1, 0, 0 };

int main(){

    int e, t, s;
    cin>>e;
    vector<int> ad[10006];
    for(int i = 0; i < e; i++){
        int n, x;
        cin>>n;
        for(int k = 0; k < n; k++){
            cin>>x;
            ad[i].push_back(x);
        }
    }
    cin>>t;
    while(t--){
        cin>>s;
        map<int, int> vis, ans;
        queue<pii> q;
        q.push({s, 1});
        vis[s] = 1;
        while(!q.empty()){
            pii cur = q.front();
            q.pop();
            for(int i = 0; i < ad[cur.ff].size(); i++){
                if(!vis[ad[cur.ff][i]]){
                    vis[ad[cur.ff][i]] = 1;
                    ans[cur.ss]++;
                    q.push({ad[cur.ff][i], cur.ss+1});
                }
            }
        }
        int mx = 0, day = 0;
        for(auto it : ans){
            if(it.ss > mx){
                mx = it.ss;
                day = it.ff;
            }
        }
        if(!day){
            cout<<day<<"\n";
        }
        else{
            cout<<mx<<" "<<day<<"\n";
        }
    }
    
    return 0;
}

