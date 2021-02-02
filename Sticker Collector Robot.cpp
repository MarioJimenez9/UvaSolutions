#include <bits/stdc++.h>

using namespace std;

int pi, pj, o, n, m, s;
char mat[105][105];

void turnleft(){
    o--;
    if(o == 0)o = 4;
}

void turnright(){
    o++;
    if(o == 5) o = 1;
}

bool valid(int i, int j){
    if(i>=n || i<0 || j>=m || j<0 || mat[i][j]=='#'){
        return false;
    }
    return true;
}
void mov(){
    if(o == 1){
        if(valid(pi-1, pj)){
            pi--;
        }
    }
    else if(o == 2){
        if(valid(pi, pj+1)){
            pj++;
        }
    }
    else if(o == 3){
        if(valid(pi+1, pj)){
            pi++;
        }
    }
    else{
        if(valid(pi, pj-1)){
            pj--;
        }
    }
}

int main(){

    while(cin>>n>>m>>s, n && m && s){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
                switch(mat[i][j]){
                    case 'N' :
                    pi = i, pj = j, o = 1;
                    break;
                    case 'L' :
                    pi = i, pj = j, o = 2;
                    break;
                    case 'S' :
                    pi = i, pj = j, o = 3;
                    break;
                    case 'O' :
                    pi = i, pj = j, o = 4;
                    break;
                }
            }
        }
        char c;
        int ans = 0;
        while(s--){
            cin>>c;
            switch(c){
                case 'F' : mov();
                break;
                case 'D' : turnright();
                break;
                case 'E' : turnleft();
                break;
            }
            if(mat[pi][pj] == '*'){
                ans++;
                mat[pi][pj] = '.';
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
