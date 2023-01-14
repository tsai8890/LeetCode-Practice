#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> posMap;
        vector<int> res(m, -1);

        int curPos;
        for (int i = m-1; i >= 0; i --) {
            posMap[nums2[i]] = i;
            if (i != m-1) {
                curPos = i + 1;
                while (true) {
                    if (nums2[i] < nums2[curPos]) {
                        res[i] = curPos;
                        break;
                    }
                    else {
                        if (res[curPos] == -1) {
                            res[i] = -1;
                            break;
                        }
                        curPos = res[curPos];
                    }
                }
            }
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