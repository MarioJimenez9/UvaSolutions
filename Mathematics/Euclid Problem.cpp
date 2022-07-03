#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ss second
#define ff first
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back

const ll INF = 1e10;
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
ll numDiffPF[MAXN + 5];
void modSieve(ll n){
    memset(numDiffPF, 0, sizeof numDiffPF);
    for(int i = 2; i < n; i++){
        if(numDiffPF[i] == 0){
            for(int j = i; j < n; j += i){
                numDiffPF[j]++;
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
int x, y, d;
void extendedEuclid(int a, int b){
    if(b == 0){
        x = 1, y = 0, d = a;
        return;
    }
    extendedEuclid(b, a % b);
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main(){
    int a, b;
    while(cin>>a>>b){
        //if(b > a)swap(a, b);
        extendedEuclid(a, b);
        cout<<y<<" "<<b - y<<endl;
    }
    return 0;
}
