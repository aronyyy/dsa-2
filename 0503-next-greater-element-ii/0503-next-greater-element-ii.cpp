class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int>st;
        for (int i=2*n-1; i>=0; i--){
            while(!st.empty() && nums[i%n] >= st.top()){
                st.pop();
            }
            if (st.empty()){
                if (i<n){
                    nge[i] = -1;
                }
            }
            else{
                if (i<n){
                    nge[i] = st.top();
                }
            }
            st.push(nums[i%n]);
        }

        return nge;
    }
};