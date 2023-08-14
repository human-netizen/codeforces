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
        ios::sync_with_stdio(false) , cin.tie(0);
        ll n;cin>>n;
        string s[n];
        for(ll i = 0 ; i < n ; i++){
            cin>>s[i];
        }   
        ll ans = 0;
        

        vector<ll>candi;
        map<ll , map<ll ,ll> >mp;
        for(ll i = 0 ; i < n ; i++){
            ll cnt[26] = {};
            for(char cc:s[i]){
                cnt[cc - 'a']++;
            }
            
            ll cur = 0;
            for(ll j = 0 ; j < 26 ; j++){
                if(cnt[j] % 2 == 1)cur |= ((1 << j));
            }
            for(char ch = 'a' ; ch <= 'z' ; ch++){
                if(cnt[ch -'a'] == 0)mp[ch - 'a'][cur]++;
            }
            
        }
        for(auto it:mp){

        
        for(ll i = 0 ; i < candi.size() ; i++){
            ll cur = candi[i];
            ll inv = 0;
            for(ll j = 0 ; j < 26 ; j++){
                if(((1 << j) & cur) == 0 && (ch - 'a') != j) inv |= ((1 << j));
            }
            ans += (mp[inv] * mp[cur]);

            mp[cur] = 0;
        }
        }
        cout<<ans<<endl;
    }