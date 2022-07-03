#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    while(cin>>n, n){
        int pos = 0;
        int val = 1, inc = 2;
        while(val + pos < n){
            val += inc;
            inc += 2;
            pos++;
        }
        int x, y;
        pos++;
        if(val > n){
            if(!(pos & 1)){
                x = pos, y = pos - (val - n);
            }
            else y = pos, x = pos - (val - n);
        }
        else{
            if(!(pos & 1)){
                y = pos, x = pos - (n - val);
            }
            else x = pos, y = pos - (n - val);
        }
        cout<<y<<" "<<x<<endl;
    }
    return 0;
}
