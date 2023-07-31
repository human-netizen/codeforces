#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,avx,fma,bmi2")

#include <bits/stdc++.h>
#include <immintrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
//#define int long long
#define all(arr) arr.begin(), arr.end()
#define multitest() int _gorilla_silverback; cin >> _gorilla_silverback; while (_gorilla_silverback --> 0)
#define pikachu push_back
#define ls(id) (id << 1 | 1)
#define rs(id) ((id << 1) + 2)
#define sqr(x) ((x) * (x))
#define dlg(x) (31 - __builtin_clz(x))
#define ulg(x) (32 - __builtin_clz(x))

typedef pair<int, int> ipair;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> treap;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 200200;
const int L = 26;

int n;
string srr[MAXN];
int arr[MAXN], brr[MAXN], crr[MAXN];

void build() {
	for (int i = 0; i < n; ++i) {
		for (char c: srr[i]) {
			arr[i] ^= (1 << (c - 'a'));
			brr[i] |= (1 << (c - 'a'));
		}
	}
}

long long calc(int c) {
	int k = 0;
	for (int i = 0; i < n; ++i)
		if (brr[i] >> c & 1 ^ 1) crr[k++] = arr[i];
	sort(crr, crr + k);
	int mask = ((1 << L) - 1) ^ (1 << c);
	long long ans = 0;
	for (int i = 0; i < k; ++i) {
		auto itl = lower_bound(crr, crr + k, crr[i] ^ mask);
		auto itr = upper_bound(crr, crr + k, crr[i] ^ mask);
		ans += itr - itl;
	}
	return ans >> 1LL;
}

long long solve() {
	long long ans = 0;
	for (int c = 0; c < L; ++c)
		ans += calc(c);
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> srr[i];
	build();
	cout << solve() << endl;
}