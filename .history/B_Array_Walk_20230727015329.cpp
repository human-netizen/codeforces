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
int ara[100005];
int pref[100005];
int ans;
void rec(string cur , int remk , int rem , int res , int idx){
    cout<<cur<<" "<<idx<<" "<<res<<endl;
    if(remk <= 0){
        cout<<"##"<<cur<<" "<<idx<<" "<<res<<" "<<rem<<endl;
        int ii = idx;
        for(int i = 0 ; i < cur.size() ; i++){
            if(cur[i] == 'l')ii--;
            else ii++;
            if(ii <= 0)return;
            res += ara[ii];
            rem--;
        }
        if(rem > 0)res += (pref[ii + rem] - pref[ii]);
        ans = max(ans , res);
        cout<<"#"<<cur<<" "<<ii<<" "<<res<<" "<<rem<<endl;
        return;
    }
    if(cur.back() != 'l')
    rec(cur + "l" , remk - 1 , rem , res , idx);
    rec(cur + "r" , remk - 1 , rem , res , idx);
}
int main(){
    tc{
        int n , rem , k;cin>>n>>rem>>k;
        for(int i = 1 ; i <= n ; i++)cin>>ara[i];
        for(int i = 1 ; i <= n ; i++)pref[i] = pref[i - 1] + ara[i];
        int sum = 0;
        for(int i = 1 ; i <= n ; i++){
            sum+=ara[i];
            rec("" , min(k , rem - i) , rem - i , sum , i);
        }
        cout<<ans<<endl;
        ans = 0;
    }
}