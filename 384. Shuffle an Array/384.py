import random

class Solution:
    """
        Title: 384. Shuffle an Array
        Time Complexity: O(1)
        Algorithm: 
            1. Shuffle Algorithm
                i. Each time randomly pick an element, popping it, and 
                   append the element to the tail of the list 
        
        Date: 07/20/2021 17:55				
        Time: 232 ms -- beat 98.88%
        Memory: 19.5 MB  -- beat 20.05%
    """
    def __init__(self, nums: List[int]):
        self.nums = nums.copy()
        self.temp =  nums.copy()
        
    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.nums

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        index = random.randrange(0, len(self.temp))
        pick = self.temp.pop(index)
        self.temp.append(pick)
        
        return self.temp.copy()

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()