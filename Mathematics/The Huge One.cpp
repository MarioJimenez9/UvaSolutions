#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

bool two(string s){
    return (s[s.size() - 1] - 48) % 2 == 0;
}
bool three(string s){
    int r = 0;
    for(auto it : s){
        r += (it - 48);
        r %= 3;
    }
    return r == 0;
}
bool four(string s){
    int r = s.back() - 48;
    if(s.size() > 1)r += (10 * (s[s.size() - 2] - 48 ));
    return r % 4 == 0;
}
bool five(string s){
    return (s[s.size() - 1] == '0' || s[s.size() - 1] == '5');
}
bool six(string s){return two(s) & three(s);}
bool seven(string s){
    int last = s.size() - 1;
    while(s.size() > 5){
        int r = s[last] - 48;
        int x = stoi(s.substr(last - 2, 2));
        r *= 2;
        if(x < r){
            x += 100;
            int pos = last - 3;
            while(s[pos] == '0'){
                s[pos] = '9';
                pos--;
            }
            s[pos]--;
        }
        x -= r;
        if(x < 10){
            s[last - 2] = '0';
        }
        else s[last - 2] = (x / 10) + 48;
        s[last - 1] = (x % 10) + 48;
        s = s.substr(0, last);
        last--;
    }
    int x = stoi(s);
    return (x % 7) == 0;

}
bool eight(string s){
    if(s.size() > 3){
      s = s.substr(s.size() - 3, 3);
    }
    int r = stoi(s);
    return (r % 8) == 0;
}
bool nine(string s){
    int r = 0;
    for(auto it : s){
        r += (it - 48);
        r %= 9;
    }
    return r == 0;
}
bool ten(string s){return s.back() == '0';}
bool eleven(string s){
    int x = 0, r = 0;
    for(int i = 0; i < s.size(); i ++){
        if(i & 1)r += (s[i] - 48);
        else x += (s[i] - 48);
    }
    return (x - r) % 11 == 0;
}
bool twelve(string s){return three(s) & four(s);}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t, m, x;
    string n;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>m;
        bool ans = 1;
        map<int, int> mp;
        for(int i = 0; i < m; i++){
            cin>>x;
            mp[x] = 1;
        }
        for(auto it : mp){
            if(it.ff == 2)ans &= two(n);
            if(it.ff == 3)ans &= three(n);
            if(it.ff == 4)ans &= four(n);
            if(it.ff == 5)ans &= five(n);
            if(it.ff == 6)ans &= six(n);
            if(it.ff == 7)ans &= seven(n);
            if(it.ff == 8)ans &= eight(n);
            if(it.ff == 9)ans &= nine(n);
            if(it.ff == 10)ans &= ten(n);
            if(it.ff == 11)ans &= eleven(n);
            if(it.ff == 12)ans &= twelve(n);
        }
        cout<<n<<" - "<<(ans? "Wonderful." : "Simple.")<<"\n";
    }

    return 0;
}
