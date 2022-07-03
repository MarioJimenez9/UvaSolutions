#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("outi.txt", "w", stdout);
    ll n, m, c;
    while(cin>>n>>m>>c, n){
        ll ans = 0;
        n += 2, m += 2;
        if(c == 0){
            ans += ((n - 9) / 2) * ((m - 8) / 2);
            ans += ((m - 9) / 2) * ((n - 8) / 2);
        }
        else{
            ans += ((n - 8) / 2) * ((m - 8) / 2);
            ans += ((n - 9) / 2) * ((m - 9) / 2);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
