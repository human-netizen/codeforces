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
        int ara[n + 1];
        int allmin = true;
        int allzero = true;
        for(int i = 1 ; i <= n ; i++){
            cin>>ara[i];
            if(ara[i] > 0)allmin = false;
            if(ara[i] != 0)allzero = false;
        }
        if(allzero){
            cout<<0<<endl;
            continue;
        }

        vector<pair<int,int> > vi;
        if(allmin == true){
            for(int i = n - 1 ; i >= 1 ; i--){
                vi.push_back({i , i + 1});
                ara[i] += ara[i + 1];
            }
            for(int i = 1 ; i < n ; i++){
                assert(ara[i] <= ara[i + 1]);
            }
        }
        else{ 
            int idx = 1;
            for(int i = 1 ; i <= n ; i++){
                if(ara[i] > 0){
                    while(ara[i] <= -ara[1]){                    
                        vi.push_back({i , i});
                        assert(vi.size() < 50);
                        ara[i] += ara[i];
                        idx = i;
                    }
                    break;
                }
            }       
            vi.push_back({1 , idx});
            ara[1] += ara[idx];
            for(int i = 1 ; i <= n - 1 ; i++){
                if(ara[i] <= ara[i + 1])continue;
                if(ara[i + 1] > 0){
                    vi.push_back({i + 1 , i});
                    ara[i + 1] += ara[i];
                }
                else{
                    while(ara[i] <= -ara[i + 1]){
                        vi.push_back({i , i});
                        ara[i] += ara[i];
                        assert(vi.size()  < 50;
                    }
                    vi.push_back({i + 1 , i});
                    vi.push_back({i + 1 , i});
                    ara[i + 1] += (2 * ara[i]);
                }
            }
            cout<<vi.size()<<endl;
            for(auto iv:vi){
                cout<<iv.first<<" "<<iv.second<<endl;
            }
            
            //cout<<endl;
    }
    }
}