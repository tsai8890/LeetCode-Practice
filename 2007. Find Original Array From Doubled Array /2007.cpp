#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    /*
        Title: 2007. Find Original Array From Doubled Array
        Time Complexity: O(N)
        
        Algorithm: 
            1. Two Pointer

        Date: 12/19/2021 16:50				
        Time: 228ms  -- beat 97.01%
        Memory: 121.2 MB  -- beat 93.97%
    */
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 == 1)
            return vector<int>();
        
        sort(changed.begin(), changed.end());
        
        vector<int> original;
        vector<int> used(changed.size(), 0);
        int count = 0;
        int ptr1 = 0, ptr2 = 1;
        
        while (ptr1 < changed.size()) {
            used[ptr1] = 1;
            while (ptr2 < changed.size() 
                   && (changed[ptr2] != 2 * changed[ptr1] || used[ptr2] == 1)) {
                ptr2 += 1;
            }
            
            if (ptr2 == changed.size()) 
                break;
            else {
                count += 1;
                used[ptr2] = 1;
                original.push_back(changed[ptr1]);
                while (ptr1 < changed.size() && used[ptr1]) 
                    ptr1 += 1;
            }
        }
        
        if (count == changed.size() / 2)
            return original;
        else{
            vector<int> nothing;
            return nothing;
        }
    }
};