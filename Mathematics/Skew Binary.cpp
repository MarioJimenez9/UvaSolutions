#include<bits/stdc++.h>

using namespace std;

int binPow(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1)ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main(){
    string s;
    while(cin>>s, s != "0"){
        int ans = 0;
        for(int i = s.size() - 1, e = 1; i >= 0; i--, e++){
            ans += ((binPow(2, e) - 1) * (s[i] - 48));
        }
        cout<<ans<<"\n";
    }

}
