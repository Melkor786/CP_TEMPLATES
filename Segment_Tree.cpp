/*
  लाल देह लाली लसे, अरु धरि लाल लँगूर |
  बज्र देह दानव दलन, जय जय जय कपि सूर ||
*/

#include <bits/stdc++.h>
using namespace std;

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


class SEGTree{
    vector<int> seg;
public:
    SEGTree(int n){
        seg.resize(4*n+1);
    }

    void build(int ind, int low, int high, vector<int>&arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = low+(high-low)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }
    
    void update(int ind, int low, int high, int i, int val){
        if(low==high){
            seg[ind] = val;
            return;
        }

        int mid = low+(high-low)/2;
        if(i<=mid)  update(2*ind+1, low, mid, i, val);
        else    update(2*ind+2, mid+1, high, i, val);

        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }
    
    int query(int ind, int low, int high, int l, int r){
        if(r<low || high<l)    return INT_MAX;
    
        if(low>=l && r>=high)    return seg[ind];
    
        else{
            int mid = low + (high-low)/2;
            int left = query(2*ind+1, low, mid, l, r);
            int right = query(2*ind+2, mid+1, high, l, r);
            return min(left, right);
        }
    }
};

void solve(){
    int n;cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    SEGTree sg(n);
    sg.build(0,0,n-1,a);
    int q;cin>>q;
    while(q--){
        int A,b,c;
        cin>>A>>b>>c;
        if(A==1)    cout<<sg.query(0,0,n-1,b,c)<<endl;
        
        else{
            sg.update(0,0,n-1,b,c);
        }
    }
}

int32_t main(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout.precision(20), cout.setf(ios::fixed);
  int t;cin >> t;
  while (t--)
  solve();
  return 0;
}