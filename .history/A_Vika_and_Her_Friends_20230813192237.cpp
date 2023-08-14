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
 
int main(){
    tc{
        int n , m , q;cin>>n>>m>>q;
        int parbe = false;
        int x , y;cin>>x>>y;
        int cnt = 0;
        for(int i = 0 ; i < q ; i++){
            int xx , yy;cin>>xx>>yy;
            if(abs((xx - x) + (yy - y)) % 2 == 1)cnt++;            
            
        }
        if(cnt < 1 && (n == 1 || m == 1))cout<<"YES"<<endl;
        else if((n !=1 && m!=1) && cnt < 2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}