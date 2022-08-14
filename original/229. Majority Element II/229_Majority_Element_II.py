class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        count = {}
        res = set()
        
        for num in nums:
            if num not in count:
                count[num] = 1
            else:
                count[num] += 1
            
            if count[num] > len(nums) // 3:
                res.add(num)
                if len(res) >= 2:
                    return res
                
        return res