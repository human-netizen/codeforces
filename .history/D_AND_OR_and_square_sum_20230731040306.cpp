#include<bits/stdc++.h>
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>&p) {return os<<'(' << p.first << ", " << p.second << ')';}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) {os << '{'; string sep;for(const T& x: v) os << sep << x, sep = ", "; return os << '}';}
void dbg_out() {cerr<<endl;}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {cerr << " " << H; dbg_out(T...); }
 
#define debug(args...) cerr << "(" << #args << "):",dbg_out(args)
 
 
typedef long long ll;
#define all(x) x.begin(),x.end()
#define tc ll tt, qq=0; cin>>tt; while(qq++<tt)
#define cs cout<<"Case "<<qq<<": "
#define csl cout<<"Case "<<qq<<":"<<endl
#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
 
int main(){
    
        ll n;cin>>n;
        vector<pair<ll,ll>>bits[30];
        ll ara[n];
        for(ll i = 0 ; i < n; i++)cin>>ara[i];
        sort(ara , ara + n);
        for(ll i = 0 ; i < n; i++){
            for(ll j = 0 ; j < 25 ; j++){
                if((ara[i] >> j)&1 ^ 1){
                    //cout<<bitset<20>(ara[i])<<" "<<j<<endl;
                    bits[j].push_back({ara[i] , i});
                }
            }
        }
        cout<<"here"<<endl;
        for(ll i = 0 ; i < n; i++){
            for(ll j = 0 ; j < 25 ; j++){
                if((ara[i] >> j)& 1 ^ 1){
                    if(bits[j].empty() == false && bits[j].back().first > ara[i] && bits[j].back().second != i){
                        cout<<bits[j].back().first<<" "<<bits[i].back().second<<endl;
                        ara[i] ^= (1 << j);
                        ara[bits[j].back().second] |= (1 << j);
                        bits[j].pop_back();
                    }
                }
            }
        }
        ll ans = 0;
        for(ll i = 0 ; i < n ; i++){
            ans += ara[i] * ara[i];
        }
        cout<<ans<<endl;

    
    
}