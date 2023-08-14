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
        int n;cin>>n;
        vector<int>num(n + 1);
        for(int i = 0 ; i < n ; i++){
            cin>>num[i + 1];
        }
        if(n <= 2)cout<<n + n - 1 <<endl;
        else{
            int ans = n + n - 1;
            
            for(int i = 0 ; i < n ; i++){
                if(!(num[2 + i] >= min(num[1 + i] , num[3 + i]) && (num[2 + i] <= max(num[1 + i] , num[3 + i])))){
                    ans++;
                    if(!(num[3 + i] >= min(num[1 + i] , num[4 + i]) && (num[3 + i] <= max(num[1 + i] , num[4 + i]))))ans++;
                }
                
            }
            cout<<ans<<endl;
        }
    }
}