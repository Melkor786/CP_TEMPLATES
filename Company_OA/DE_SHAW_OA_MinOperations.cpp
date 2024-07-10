// DE SHAW OA 2nd Question 
// This can be done with linear time complexity:
// Get the sum of all the values in the array.

// Perform a forward sweep through the array making the necessary reductions to ensure that a value is never greater than one more than its (possibly already updated) predecessor. The predecessor value of the very first element should be taken as 0.




// On the updated array, repeat the same operation in the reversed direction.

// After these two steps we have performed the minimum reductions needed to get an array whose elements are never greater than either neighbor plus 1, again taking 0 for a neighbor value when there is no neighbor.

// Find the greatest value in this array, which will become the peak of the bitonic array. If there are multiple positions to choose from, it doesn't matter as the final sum of the bitonic array will be the same: the number of operations to achieve it is the difference between the original array's sum and the final array's sum.

// The final array sum is the peak value squared -- it is not necessary to actually make the array bitonic. For instance, if the peak value is 3, then the sum of the values in the bitonic array will be 1+2+3+2+1 = 9.

// Here is an implementation:

#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "E:\Online_Judge\Templates\debug.h"
#else
#define debug(...)
#endif

#define all(x) x.begin(), x.end()
#define rev_all(x) x.rbegin(), x.rend()
#define size(x) (int)(x).size()
#define MAX(x) *max_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define rep(i, a, b) for (int i = (a); i < (b); i++)
int solve(vector<int>&arr);
int32_t main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    rep(i,0,n)cin>>arr[i];
    cout<<solve(arr)<<endl;
}

int solve(vector<int> &arr){
    int sum = SUM(arr);
    for (int sweep = 0; sweep < 2; sweep++){
        int max = 0;
        for (auto &i:arr){
            max++;
            if (i > max)    i = max;
            else    max = i;
        }
        reverse(all(arr));
    }
    int m=MAX(arr);
    return sum-m*m;
}
