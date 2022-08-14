class Solution:
    """
        Title: 3Sum
        Time Complexity: O(N^3)
        Algorithm: 
            1. Brutally Searching all the combinations

        Date: 2021.7.11 15:30
    """
    def Find_3comb(self, nums: List[int], nums_len: int , 
                   ans_list: List[int], start_pos: int, cur_list: List[int]):
        
        if len(cur_list) == 3:
            if sum(cur_list) == 0:
                ans_list.append(cur_list.copy())
       
        else:
            for i in range(start_pos, nums_len):
                cur_list.append(nums[i])
                self.Find_3comb(nums, nums_len, ans_list, i+1, cur_list)
                cur_list.pop()
            
        
        
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans_list, cur_list = [], []
        nums.sort()
        
        self.Find_3comb(nums, len(nums), ans_list, 0, cur_list)
        
        ans_list = list(set([tuple(i) for i in ans_list]))
        return ans_list
    