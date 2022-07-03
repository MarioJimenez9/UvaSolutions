#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll LIM = 1e10;
    bitset<1000010> bs;
vector<int> primes;
void sieve(ll n){

    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= sqrt(n); i++){
        if(bs[i]){
            for(ll j = i * i; j <= sqrt(n); j+=i){
                bs[j] = 0;
            }
            primes.push_back(i);
        }

    }
}

int sumDig(ll n){
    int ans = 0;
    while(n){
        ans = ans + (n % 10);
        n /= 10;
    }
    return ans;
}

int factors(ll n){
    ll idx = 0, PF = primes[idx];
    int ans = 0;
    bool f = 0;
    while(PF * PF <= n){
        while(n % PF == 0){
            ans += sumDig(PF);
            n /= PF;
            f = 1;
        }
        PF = primes[++idx];
    }
    if(n > 1)ans += sumDig(n);
    if(!f)ans = -1;
    return ans;
}

int main(){
    sieve(LIM);
    ll n, t;
    cin>>t;
    while(t--){
        cin>>n;
        ll tmp = n + 1;
        while(sumDig(tmp) != factors(tmp)){
            tmp++;
        }
        cout<<tmp<<"\n";
    }
}
