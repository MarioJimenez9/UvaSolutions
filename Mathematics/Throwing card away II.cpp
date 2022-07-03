#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin>>n, n){
        int lg = ceil(log2(n));
        n = (1 << lg) - n;
        cout<<(1 << lg) - (n * 2)<<"\n";
    }


    return 0;
}
