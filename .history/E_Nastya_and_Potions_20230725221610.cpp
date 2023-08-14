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
vector<int>adj[200005];
int cost[maxi] = {};
int sum[maxi] = {};
int ara[maxi] = {};
void dfs(int node){
    if(sum[node] != -1)return;
    if(cost[node] == 0)sum[node] = 0;
    int ss = 0;
    for(int v:adj[node]){
        dfs(v);
        ss += sum[v];
    }
    
    if(adj[node].size() == 0)sum[node] = cost[node];
    else sum[node] = min(ss , cost[node]);
    debug(node , sum[node]);
}
int main(){
    tc{
        int n , k;
        cin>>n>>k;
        
        for(int i = 1 ; i <= n ; i++){
            cin>>cost[i];
        }
        for(int i = 0 ; i < k ; i++){
            int a;cin>>a;
            cost[a] = 0;
        }
        for(int i = 1 ; i <= n ; i++){
            int m;cin>>m;
            for(int j = 0 ; j < m ; j++){
                int v;cin>>v;
                adj[i].push_back(v);
            }

        }
        for(int i = 1 ; i <= n ; i++){
            dfs(i);
            cout<<sum[i]<<" ";cout<<endl;
        }
        for(int i = 1 ; i <= n ; i++){
            sum[i].clear();
            adj[i].clear();
        }
    }
}