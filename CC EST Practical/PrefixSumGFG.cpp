class Solution {
  public:
    vector<int> rangeSumQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();
        
        vector<int> prefix(n);
        vector<int> ans;
        
        prefix[0] = arr[0];
        
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        for (auto q : queries) {
            int L, R;
            L = q[0], R = q[1];
            
            if (L == 0) {
                ans.push_back (prefix[R]);
            } else {
                ans.push_back (prefix[R] - prefix[L - 1]);
            }
        }
        
        return ans;
    }
};