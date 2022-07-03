#include <bits/stdc++.h>

using namespace std;

const int MOD = 131071;

int main(){
    string s, x;
    while(cin>>x){
        s = "";
        s += x;
        while(x[x.size() - 1] != '#')cin>>x, s += x;
        int ans = 0;
        int po = 1;
        for(int i = s.size() - 2; i >= 0; i--){
            if(s[i] == '1'){
                ans |= po;
            }
            ans %= MOD;
            po *= 2;
            po %= MOD;
        }
        cout<<(ans? "NO" : "YES")<<endl;
    }

    return 0;
}
