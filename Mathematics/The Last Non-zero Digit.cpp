#include <bits/stdc++.h>

using namespace std;

#define ll long long
//11 digitos minimo
ll MOD = 1e11;

int main(){
    ll n, m;
    while(cin>>n>>m){
        ll r = 1;
        for(ll i = n - m + 1; i <= n; i++){
            r *= i;
            while(r % 10 == 0 )r /= 10LL;
            r %= MOD;
        }
        cout<<r % 10<<"\n";
    }

    return 0;
}
