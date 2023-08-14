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
ll parbe(ll n){
    ll sq = sqrt(4 * n -3 );
    if(sq * sq != (4 * n - 3))return 0;
    return sq&1;
} 
int main(){
    unordered_map<ll,int>mp;
    for(ll i = 2 ; i <= 1000000 ; i++){
        ll cur = 1 + i + i * i;
        if(cur > 1e18)break;
        ll po = i * i;
        for(ll j = 1 ; j < 64 ; j++){
            mp[cur] = 1;
            if(po > (2e18/i))break;  
            if(cur > 2e18 - po * i)break;
            po *= i;
            cur += po;           
                      
        }
    }
    tc{
        ll n;cin>>n;
        if(n <= 5)
        if(mp[n])cout<<"YES"<<endl;
        else if(parbe(n))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}