#include <vector>
#include <cmath>
using namespace std;

/*
    Use grouping to decrease the time complexity
    N elements 
        => num of groups: sqrt(N)
        => size of group: sqrt(N)
    
    Time Complexity
        - query: O(sqrt(N))
        - update: O(1)
*/

class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        this->groupSize = (int)(sqrt(nums.size())) + 1;
        this->groupSum = vector<int>(nums.size()/groupSize + 1, 0);
        for (int i = 0; i < nums.size(); i ++) {
            this->groupSum[i/groupSize] += nums[i];
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        groupSum[index/groupSize] += diff;
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int leftGroup = left/groupSize;
        int rightGroup = right/groupSize;

        int sum = 0;
        if (leftGroup == rightGroup) {
            for (int i = left; i <= right; i ++) {
                sum += nums[i];
            }
        }
        else {
            for (int i = leftGroup+1; i <= rightGroup-1; i ++) {
                sum += groupSum[i];
            }

            int leftGroupEnd = groupSize * (left/groupSize+1) - 1;
            int rightGroupStart = (right/groupSize) * groupSize;
            for (int i = left; i <= leftGroupEnd; i ++) {
                sum += nums[i];
            }
            for (int i = rightGroupStart; i <= right; i ++) {
                sum += nums[i];
            }
        }
        return sum;
    }

private:
    vector<int> nums;
    vector<int> groupSum;
    int groupSize;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */