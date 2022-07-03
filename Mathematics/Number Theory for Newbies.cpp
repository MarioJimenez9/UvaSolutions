#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

ll binPow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans *= a;
        }
        b >>= 1;
        a *= a;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n;
    while(cin>>n){
        vi v;
        while(n){
            v.push_back(n % 10);
            n /= 10;
        }
        sort(v.begin(), v.end());
        ll a = 0, b = 0, len = v.size();
        for(int i = 0; i < len; i++){
            a += (v[i] * binPow(10, i));
        }
        for(int i = 0; i < len; i++){
            if(v[i] != 0){swap(v[i], v[0]); break;}
        }
        for(int i = 0; i < len; i++){
            b += (v[i] * binPow(10, len - i - 1));
        }
        cout<<a<<" - "<<b<<" = "<<a - b<<" = 9 * "<<(a - b) / 9<<"\n";
    }
    return 0;
}
