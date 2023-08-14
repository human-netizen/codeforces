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
const ll maxi = 2e5 + 5;
vector<ll>adj[200005];
ll cost[maxi] = {};
ll sum[maxi] = {};
ll ara[maxi] = {};
void dfs(ll node){
    if(sum[node] != -1)return;
    if(cost[node] == 0)sum[node] = 0;
    ll ss = 0;
    for(ll v:adj[node]){
        dfs(v);
        ss += sum[v];
    }
    
    if(adj[node].size() == 0)sum[node] = cost[node];
    else sum[node] = min(ss , cost[node]);
    //debug(node , sum[node]);
}
ll main(){
    tc{
        ll n , k;
        cin>>n>>k;
        
        for(ll i = 1 ; i <= n ; i++){
            sum[i] = -1;
            cin>>cost[i];
        }
        for(ll i = 0 ; i < k ; i++){
            ll a;cin>>a;
            cost[a] = 0;
        }
        for(ll i = 1 ; i <= n ; i++){
            ll m;cin>>m;
            for(ll j = 0 ; j < m ; j++){
                ll v;cin>>v;
                adj[i].push_back(v);
            }

        }
        for(ll i = 1 ; i <= n ; i++){
            dfs(i);
            cout<<sum[i]<<" ";
        }
        cout<<endl;
        for(ll i = 1 ; i <= n ; i++){
            sum[i] = -1;
            adj[i].clear();
        }
    }
}