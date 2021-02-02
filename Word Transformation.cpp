#include <bits/stdc++.h>

using namespace std;

#define psi pair<string, int>
#define ss second
#define ff first

struct stu{
    string a, b;
    int n;
};

bool valid(string a, string b){
    int dif = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i])dif++;
        if(dif > 1) return false;
    }
    if(dif) return true;
}

int main(){

    int t;
    cin>>t;
    while(t--){
    string word, par;
    vector<string> v[100005];
    while(cin>>word, word != "*"){
        if(word != ""){
            v[word.size()].push_back(word);
        }
    }
    cin.ignore();
        bool f = false;
        while(getline(cin, par), par != ""){
            f = true;
            map<string, int> vis;
            stringstream in(par);
            string to, from;
            in>>to>>from;
            queue< psi > q;
            q.push({to, 0});
            vis[to]=1;
            while(!q.empty()){
                psi cur = q.front();
                q.pop();

                if(cur.ff == from)
                {
                    cout<<to<<" "<<from<<" "<<cur.ss<<"\n";
                    break;
                }
                for(int i = 0; i<v[to.size()].size(); i++){
                    if(!vis[v[to.size()][i]] && valid(cur.ff, v[to.size()][i]))
                    {
                        q.push({v[to.size()][i], cur.ss+1});
                        vis[v[to.size()][i]] = 1;
                    }
                }
            }
        }
        if(t)cout<<"\n";
    }
    return 0;
}
