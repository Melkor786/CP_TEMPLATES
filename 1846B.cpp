/*
  लाल देह लाली लसे, अरु धरि लाल लँगूर |
  बज्र देह दानव दलन, जय जय जय कपि सूर ||
*/

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long
#define double long double
#define ff first
#define ss second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MP make_pair
#define all(x) x.begin(), x.end()
#define rev_all(x) x.rbegin(), x.rend()
#define size(x) (int)(x).size()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define FIND(x, y) binary_search(all(x), y)
#define MEM(x, y) memset(x, y, sizeof(x))
#define CNT(x) __builtin_popcountll(x)
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define bck(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define yes {cout << "YES\n";return;}
#define no {cout << "NO\n";return;}
#define endl "\n"

void solve(){
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];

}

int32_t main(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout.precision(20), cout.setf(ios::fixed);
  int t;cin >> t;
  while (t--)
  solve();
  return 0;
}