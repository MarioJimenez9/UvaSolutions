#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ss second
#define ff first
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define vpii vector<pii>
const int INF = 1e9;
const int MAXN = 1e6;

ll binExp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

vi primes;
void sieve(ll n){
    bitset<10010000> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 4; i <= sqrt(n); i += 2){
        bs[i] = 0;
    }
    primes.pb(2);
    for(ll i = 3; i <= sqrt(n); i += 2){
        if(bs[i] == 1){
            for(ll j = i * i; j <= sqrt(n); j += i){
                bs[j] = 0;
            }
            primes.pb(i);
        }
    }
}
vi phi;
vi M, mu;
void modSieve(int n){
    phi.resize(n);
    for(int i = 2; i < n; i++){
        if(phi[i] == 0){
            for(int j = i; j < n; j += i){
                if(phi[j] == 0)phi[j] = j;
                phi[j] -=  (phi[j] / i);
            }
        }
    }
}

ll numDiv(ll n){
    int idx = 0;
    ll PF = primes[idx], ans = 1;
    while(PF * PF <= n){
        int po = 1;
        while(n % PF == 0){
            n /= PF;
            po++;
        }
        ans *= po;
        PF = primes[++idx];
    }
    if(n != 1)ans *= 2;
    return ans;
}

ll sumDiv(ll n){
    int idx = 0;
    ll PF = primes[idx], ans = 1;
    while(PF * PF <= n){
        int po = 1;
        while(n % PF == 0){
            n /= PF;
            po++;
        }
        ans *= ((binExp(PF, po) - 1) / (PF - 1));
        PF = primes[++idx];
    }
    if(n != 1){
        ans *= ((binExp(n, 2) - 1) / (n - 1));
    }
    return ans;
}
ll EulerPhi(ll n){
    int idx = 0;
    ll PF = primes[idx], ans = n;
    while(PF * PF <= n){
        if(n % PF == 0)ans -= (ans / PF);
        while(n % PF == 0){
            n /= PF;
        }
        PF = primes[++idx];
    }
    if(n != 1){
        ans -= (ans / n);
    }
    return ans;
}


int main(){
    modSieve(2 * MAXN + 5);
    vector<ll> dp(2 * MAXN + 1);
    dp[0] = 0, dp[1] = dp[2] = 1;
    for(int i = 3; i <= 2 * MAXN; i++){
        dp[i] = dp[phi[i]] + 1;
    }
    for(int i = 2; i <= 2 * MAXN; i++){
        dp[i] += dp[i - 1];
    }
    int n, m, t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cout<<dp[m] - dp[n - 1]<<"\n";
    }
    return 0;
}
