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

struct Node{
    Node *link[26];
    bool flag = false;

    Node *nextNode(char c){
        return link[c - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    
    
};


class Trie {

private:
    Node *root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *temp = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(temp->nextNode(word[i]) == NULL){
                temp->link[word[i] - 'a'] = new Node();
            }
            temp = temp->nextNode(word[i]);
        }
        temp->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *temp = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(temp->nextNode(word[i]) == NULL){
                return 0;
            }
            temp = temp->nextNode(word[i]);
        }
        if(temp->flag)return 1;
        return 0;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node *temp = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(temp->nextNode(word[i]) == NULL){
                return 0;
            }
            temp = temp->nextNode(word[i]);
        }
        return 1;

    }
};
int main(){
    
}