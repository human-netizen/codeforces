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
        int len , q;cin>>len>>q;
        int extra = 0;
        vector<int>one , zero;
        string s;cin>>s;
        for(int i = 0 ; i < len ; i++){
            if(s[i] == '1')one.push_back(i + 1);
            else zero.push_back(-(i + 1));
        }
        sort(all(zero));
        int paise = 0;
        int ans = 0;
        if(one.size() == 0 || zero.size() == 0){
            ans = 1;
            paise = 1;
        }
        
        unordered_map<int,unordered_map<int,int> > mp;
        for(int i = 0 ; i < q ; i++){
            int l , r;cin>>l>>r;
            if(paise)continue;
            auto iii = lower_bound(all(one) , l);
            auto jjj = (lower_bound(all(zero) , -r));
            if(iii == one.end() || jjj == one.end()){
                extra = 1;
                continue;
            }
            int ii = *iii;
            int jj = -(*jjj);
            //<<ii<<" "<<jj<<endl;
            if(ii > jj){
                extra = 1;
                continue;
            }
            else if(mp[ii][jj] == 0){
                ans++;
                
            }
            mp[ii][jj] = 1;           

        }
        cout<<ans + extra<<endl;
    }
}