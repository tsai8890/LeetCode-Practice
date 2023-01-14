#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> posMap;
        int n = nums1.size(), m = nums2.size();

        vector<int> res(m, -1);
        stack<int> st;
        for (int i = 0; i < m; i ++) {
            posMap[nums2[i]] = i;
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        vector<int> retVec;
        for (int i = 0; i < n; i ++) {
            int nextGreater = res[posMap[nums1[i]]];
            if (nextGreater == -1) 
                retVec.push_back(-1);
            else 
                retVec.push_back(nums2[nextGreater]);
        }
        return retVec;
    }
};