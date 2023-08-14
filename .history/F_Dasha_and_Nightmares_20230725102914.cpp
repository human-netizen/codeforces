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
    int n;cin>>n;
    string s[n];
    for(int i = 0 ; i < n ; i++){
        cin>>s[i];
    }   
    for(char ch = 'a' ; ch <= 'z' ; ch++){
        vector<int>candi;
        map<int,int>mp;
        for(int i = 0 ; i < n ; i++){
            int cnt[26] = {};
            for(char cc:s[i]){
                cnt[cc - 'a']++;
            }
            if(cnt[ch - 'a'])continue;
            int cur = 0;
            for(int j = 0 ; j < 26 ; j++){
                cnt[j]%=2;
                cur |= ((1 << j) & cnt[j]);
            }
            candi.push_back(cur);
            mp[cur]++;
        }
        sort(all(candi));
        uniq(candi);
        for(int i = 0 ; i < candi.size() ; i++){
            int cur = candi[i];
            int inv = 0;
            for(int j = 0 ; j < 26 ; j++){}
        }
    }
}