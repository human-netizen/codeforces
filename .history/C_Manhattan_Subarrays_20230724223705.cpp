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
                int bara[3][3] = {
                    {1 , 2 , 3} , 
                    {1 , 2 , 4} , 
                    {1 , 3 , 4}
                };
                for(int j = 0 ; j < 3 ; j++){
                    int parbe = 0;
                    if(i + bara[j][2] <= n){
                        int one = num[bara[j][0]];
                        int two = num[bara[j][1]];
                        int three = num[bara[j][2]];
                        parbe = !(two >= min(one , three) && two <= max(one , three));
                    }
                }
                
            }
            cout<<ans<<endl;
        }
    }
}