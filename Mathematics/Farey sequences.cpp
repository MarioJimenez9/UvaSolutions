#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ss second
#define ff first
#define pii pair<double, double>

struct cmp{
    bool operator()(const pii &a, const pii &b){
        return a.ff / a.ss < b.ff / b.ss;
    }
};


int gcd(int a, int b){
    if(b == 0)return a;
    return gcd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k;
    while(cin>>n>>k){
        vector<pii> F;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if(gcd(i, j) == 1){
                    F.push_back({j, i});
                }
            }
        }
        sort(F.begin(), F.end(), cmp());
        cout<<F[--k].ff<<"/"<<F[k].ss<<"\n";
    }


    return 0;
}
