#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> sec(1, 1);

ll binPow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1)ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
const ll lim = 2000000000;
void prePro(){
    for(int i = 0; i < 31; i++){
        ll i2 = binPow(2, i);
        for(int j = 0; j < 20; j++){
            ll i3 = binPow(3, j);
            if(i3 * i2 > lim)break;
            for(int k = 0; k < 14; k++){
                ll i5 = binPow(5, k);
                if(i3 * i2 * i5 > lim)break;
                for(int l = 0; l < 12; l++){
                    ll i7 = binPow(7, l);
                    if(i3 * i2 * i5 * i7 > lim)break;
                    if(i2 * i3 * i5 * i7 != 1)sec.push_back(i2 * i3 * i5 * i7);
                }
            }
        }
    }
    sort(sec.begin(), sec.end());
}

int main(){
    prePro();
    int n;
    while(cin>>n, n){
        cout<<"The "<<n;
        if(n % 10 == 1 && n % 100 != 11){
            cout<<"st ";
        }
        else if(n % 10 == 2 && n % 100 != 12){
            cout<<"nd ";
        }
        else if(n % 10 == 3 && n % 100 != 13){
            cout<<"rd ";
        }
        else cout<<"th ";
        cout<<"humble number is "<<sec[n - 1]<<".\n";
    }

    return 0;
}
