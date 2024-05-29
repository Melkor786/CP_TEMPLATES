// Range Max Query
class SEGTree {
    vector<int> seg;

public:
    SEGTree(int n) {
        seg.resize(4 * n + 1, INT_MIN);
    }

    void build(int ind, int low, int high, const vector<int>& arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if (i <= mid) {
            update(2 * ind + 1, low, mid, i, val);
        } else {
            update(2 * ind + 2, mid + 1, high, i, val);
        }

        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        // No overlap
        if (r < low || high < l) {
            return INT_MIN;
        }

        // Total overlap
        if (l <= low && high <= r) {
            return seg[ind];
        }

        // Partial overlap
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return max(left, right);
    }
};

//Range Min Query
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


//Range Sum Query
class SEGTree {
    vector<int> seg;
public:
    SEGTree(int n) {
        seg.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, const vector<int>& arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if (i <= mid) {
            update(2 * ind + 1, low, mid, i, val);
        } else {
            update(2 * ind + 2, mid + 1, high, i, val);
        }

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r) {
        // No overlap
        if (r < low || high < l) {
            return 0;
        }

        // Total overlap
        if (l <= low && high <= r) {
            return seg[ind];
        }

        // Partial overlap
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};
