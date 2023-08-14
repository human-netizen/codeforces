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
        int n , k;cin>>n>>k;
        int ara[n + 1];
        for(int i = 1 ; i <= n ; i++)cin>>ara[i];
        int ansara[n + 1][n + 1] = {};
        ansara[0][0] = 1;
        for(int i = 1 ; i <= n ; i++){
            int cur = k;
            for(int j = i ; j >= 1 ; j--){
                if(ara[j] == ara[i])cur--;
                if(cur <= 0){
                    for(int k = 1 ; k <= n ; k++){
                        ansara[i][k] += ansara[j - 1][k - 1];
                        cout<<i<<" "<<j<<" "<<k<<" "<<ansara[i]
                    }
                }
            }

        }
        int maxj = 0 , maxans = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(ansara[i][j] && j > maxj){
                    maxj = j;
                    maxans = ansara[i][j];
                }
                cout<<ansara[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<maxans<<endl;

    }
}