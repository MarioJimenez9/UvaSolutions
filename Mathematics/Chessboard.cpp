#include <bits/stdc++.h>

using namespace std;

const double D = 1.414213562;

double sum(int n){
    return n * (n + 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        double n;
        cin>>n;
        if(n == 1)cout<<"0.000\n";
        else{
            double v = sum(n - 2) + sum(n - 3);
            cout<<fixed<<setprecision(3)<<(v * D) + (n * n - v)<<"\n";
        }

        if(t)cout<<"\n";
    }

    return 0;
}
