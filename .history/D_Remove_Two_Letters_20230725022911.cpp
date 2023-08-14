#include<bits/stdc++.h>
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>&p) {return os<<'(' << p.first << ", " << p.second << ')';}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) {os << '{'; string sep;for(const T& x: v) os << sep << x, sep = ", "; return os << '}';}
void dbg_out() {cerr<<endl;}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {cerr << " " << H; dbg_out(T...); }
 
#define debug(args...) cerr << "(" << #args << "):",dbg_out(args)
 
 
typedef long long ll;
#define all(x) x.begin(),x.end()
#define tc int tt, qq=0; cin>>tt; while(qq++<tt)
#define cs cout<<"Case "<<qq<<": "
#define csl cout<<"Case "<<qq<<":"<<endl
#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
const int maxi = 2e5 + 5;
ll pref1[maxi] , ten1[maxi];
ll pref2[maxi] , ten2[maxi];
ll mod1 = 1e9 + 7;
ll mod2 = 1e9 + 9;
void hash(string s){
    for(int i = 1 ; i < s.size() ; i++){
        pref1[i] = pref1[i - 1] * ('z' - 'a' + 1) + (s[i] - 'a');
        pref2[i] = pref2[i - 1] * ('z' - 'a' + 1) + (s[i] - 'a');
        pref1[i]%=mod1;
        pref2[i]%=mod2;
    }
}
int main(){
    ten1[1] = ten2[1] = 1;
    for(int i = 2 ; i < maxi ; i++){
        ten1[i] = ten1[i - 1] * 10;
        ten2[i] = ten2[i - 1] * 10;
        ten1[i] %= mod1;
        ten2[i] %= mod2;
    }
    tc{

    }
}