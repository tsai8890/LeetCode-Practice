class Solution:
    """
        Title: 205. Isomorphic Strings
        Time Complexity: O(N)
        Algorithm: 
            1. Hash Table by Python dict()
        
        Date: 2021.7.12 21:25
        Time: 32 ms  -- beat 96.01%
        Memory: 14.5 MB  -- beat 47.08%
    """

    def isIsomorphic(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        ch_dict = {}
        for ch_s, ch_t in zip(s, t):
            if ch_s not in ch_dict:
                if ch_t not in ch_dict.values():
                    ch_dict[ch_s] = ch_t
                else:
                    return False
            
            else:
                if ch_dict[ch_s] == ch_t:
                    continue
                else:
                    return False
        return True